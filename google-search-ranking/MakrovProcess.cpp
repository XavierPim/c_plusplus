#include <iomanip>
#include "MakrovProcess.hpp"


void MakrovProcess::startMakrov()
{
    FileReader read;
    MakrovProcess matrix(read.parseFile());
    delete matrix.getMatrixM();
    delete matrix.getMatrixS();
    delete matrix.getMatrixQ();
    delete matrix.getMatrixG();
}


MakrovProcess::MakrovProcess(vector<double> parsedVec)
{
    /**connectivity matrix**/
    matrixG = new Matrix(parsedVec);

    /**importance matrix created from matrix above**/
    matrixS = new Matrix(matrixG->getRows(), matrixG->getColumns());

    /**teleport matrix**/
    matrixQ = new Matrix(matrixS->getRows(), matrixS->getColumns());

    /**transition matrix**/
    matrixM = new Matrix(matrixS->getRows(), matrixS->getColumns());

    this->createSMatrix();
    this->createQMatrix();
    this->createMMatrix();

    rank.oldRank = new vector<double>(matrixS->getRows(), ZERO);
    rank.newRank = new vector<double>(matrixM->getRows(), ZERO);
    rank.currRank = new vector<double>(matrixM->getRows(), ONE);

    this->makrovProcessor();
}


void MakrovProcess::createSMatrix()
{
    //creates a dictionary for matrixS to for division of each element 1/columnSum
    vector<double> outLinks(matrixG->getColumns(), ZERO); // Initialize with zeros

    //looks through matrix G for 1's
    for(int j = ZEROI; j < matrixG->getColumns(); j++)
    {
        double colSum = ZERO;

        for(int i = ZEROI; i < matrixG->getRows(); i++)
        {
            double value = matrixG->getValue(i, j);

            if(value == ONE)
            {
                colSum++;
            }
        }

        outLinks[j] = colSum; // Assign the sum to the corresponding column
    }

    /*sets values for importance matrixS based on dictionary Outlinks*/
    for(int j = ZEROI; j < matrixG->getColumns(); j++)
    {
        for(int i = ZEROI; i < matrixG->getRows(); i++)
        {
            double value = matrixG->getValue(i, j);

            if(value == ONE)
            {
                double probability = ONE / outLinks[j];
                matrixS->setValue(i, j, probability);
            }
            else if(outLinks[j] == ZERO)
            {
                double probability = ONE / matrixS->getRows();
                matrixS->setValue(i, j, probability);
            }
        }
    }
    cout << "before scale applied\n" << *matrixS << endl;
}

Matrix *MakrovProcess::getMatrixS() const
{
    return matrixS;
}

void MakrovProcess::createQMatrix()
{
    /*sets values teleportation matrix*/
    for(int j = ZEROI; j < matrixQ->getColumns(); j++)
    {
        for(int i = ZEROI; i < matrixQ->getRows(); i++)
        {
            double probability = ONE / matrixQ->getRows();
            matrixQ->setValue(i, j, probability);
        }
    }

    cout << *matrixQ << endl;
}

Matrix *MakrovProcess::getMatrixQ() const
{
    return matrixQ;
}

Matrix *MakrovProcess::getMatrixG() const
{
    return matrixG;
}

void MakrovProcess::createMMatrix()
{
    *matrixS *= PROBFAC;
    *matrixQ *= TELEFAC;
    *matrixM = *matrixS + *matrixQ;

    cout << *matrixS << endl;
    cout << *matrixQ << endl;
    cout << *matrixM << endl;
}

Matrix *MakrovProcess::getMatrixM() const
{
    return matrixM;
}

vector<double> *MakrovProcess::runMarkovProcess(vector<double> *previousRank, vector<double> *currRank)
{
    *previousRank = *currRank;

    vector<double> result = matrixVectorMultiply(*matrixM, *currRank); // Use currRank, not rank.currRank
    bool converged = true;

    //checks if within convergence threshold
    for(size_t i = ZEROI; i < rank.currRank->size(); ++i)
    {
        if(abs(result[i] - previousRank->at(i)) > convergenceThreshold)
        {
            converged = false;
            break;
        }
    }

    //exits and returns result vector
    if(converged)
    {
        // Convert result to a dynamically allocated vector
        return new vector<double>(result);
    }
    else
    {
        // Recurse with the current rank as the previous rank
        return runMarkovProcess(currRank, &result);
    }
}

vector<double> MakrovProcess::matrixVectorMultiply(const Matrix &matrix, vector<double> &v)
{
    // Get the dimensions of the matrix and vector
    int numRows = matrix.getRows();
    int numCols = matrix.getColumns();

    try
    {
        if(numCols != static_cast<int>(v.size()))
        {
            throw invalid_argument("Matrix and vector size mismatch.");
        }
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    vector<double> result(numRows, ZERO);

    for(int i = ZEROI; i < numRows; i++)
    {
        for(int j = ZEROI; j < numCols; j++)
        {
            result[i] += matrix.getValue(i, j) * v[j];
        }
    }

    return result;
}


void MakrovProcess::makrovProcessor()
{
    rank.currRank = runMarkovProcess(rank.oldRank, rank.currRank);

    // Final print of results
    char label = 'A';

    for (double value: *rank.currRank)
    {
        cout <<fixed<< setprecision(TWO)<<"PAGE "<< label << ':' << (value / matrixS->getRows()) * HUNDY << "%\n";
        label++;
    }

    cout << endl;

    delete rank.newRank;
    delete rank.oldRank;
    delete rank.currRank;
}







