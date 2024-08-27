#include "matrix.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

Matrix::Matrix()
{
    rows    = DEFAULT_ROWS;
    columns = DEFAULT_COLUMNS;

    matrix = (double **)calloc(rows, sizeof(double *));

    if(matrix != nullptr)
    {
        matrix[ZEROI] = (double *)calloc(columns, sizeof(double));
    }

    clear();
}

Matrix::Matrix(int n)
{
    try
    {
        if(n > ZEROI)
        {
            rows = n;
            columns = n;

            matrixInit(rows, columns);
            clear();
        }
        else
        {
            throw invalid_argument("Error: Invalid Size\n");
        }
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

Matrix::Matrix(int r, int c)
{
    try
    {
        if(r > ZEROI && c > ZEROI)
        {
            rows    = r;
            columns = c;

            matrixInit(rows, columns);
            clear();
        }
        else
        {
            throw invalid_argument("Error: Invalid Size\n");
        }
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}


Matrix::Matrix(const vector<double> &nums)
{
    int size = (int)nums.size();

    try
    {
        if(isSquare(size))
        {
            int root = (int)sqrt(size);

            rows    = root;
            columns = root;

            matrixInit(rows, columns);
            populateMatrix(nums);
        }
        else
        {
            throw invalid_argument("Invalid vector size!\n");
        }
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

Matrix::Matrix(const Matrix &other)
{
    // assign other value to current value.
    rows    = other.rows;
    columns = other.columns;

    matrixInit(rows ,columns);
    populateMatrix(other);

}

void Matrix::setValue(int row, int column, double value)
{
    try
    {
        if((row >= ZEROI && column >= ZEROI) && (row < rows && column < columns))
        {
            matrix[row][column] = value;
        }
        else
        {
            throw invalid_argument("Invalid index or value!\n");
        }
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

double Matrix::getValue(int row, int column) const
{
    try
    {
        if((row >= ZEROI && row < rows) && (column >= ZEROI && column < columns))
        {
            return matrix[row][column];
        }
        else
        {
            throw invalid_argument("Invalid Index!\n");
        }
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Matrix::matrixInit(int numColumns, int numRows)
{
    matrix = (double **)malloc(numRows * sizeof(double *));

    for (int i = ZEROI; i < numRows; i++)
    {
        matrix[i] = (double *)malloc(numColumns * sizeof(double));
    }
}

Matrix::~Matrix()
{
//    cout << "Matrix Destroyed" << endl;
}

void Matrix::clear()
{
    for (int i = ZEROI; i < rows; i++)
    {
        for (int j = ZEROI; j < columns; j++)
        {
            matrix[i][j] = ZEROD;
        }
    }
}

bool Matrix::isSquare(int num)
{
    double squared = sqrt(num);

    return squared == static_cast<int>(squared);
}

void Matrix::populateMatrix(const vector<double> &nums)
{
    int index = ZEROI;

    for (int i = ZEROI; i < rows; i++)
    {
        for (int j = ZEROI; j < columns; j++)
        {
            setValue(i, j, nums.at(index));
            //matrix[i][j] = nums.at(index);
            index++;
        }
    }
}

void Matrix::populateMatrix(const Matrix &other)
{
    int index = ZEROI;

    for (int i = ZEROI; i < rows; i++)
    {
        for (int j = ZEROI; j < columns; j++)
        {
            setValue(i, j, other.getValue(i,j));
            index++;
        }
    }
}

int Matrix::getRows() const
{
    return rows;
}

int Matrix::getColumns() const
{
    return columns;
}

void Matrix::matrixSwap(Matrix &first, Matrix &second)
{
    swap(first.rows, second.rows);
    swap(first.columns, second.columns);
    swap(first.matrix, second.matrix);
}

ostream &operator<<(ostream &os, Matrix &thisMatrix)
{
    for (int i = Matrix::ZEROI; i < thisMatrix.getRows(); i++)
    {
        os << "| ";
        for (int j = Matrix::ZEROI; j < thisMatrix.getColumns(); j++)
        {
            os << fixed << setprecision(3)<<  thisMatrix.getValue(i, j)<< " ";
        }
        os << "|" << endl;
    }
    return os;
}

bool operator==(Matrix &leftMatrix, Matrix &rightMatrix)
{
    if(leftMatrix.getRows() == rightMatrix.getRows() && leftMatrix.getColumns() == rightMatrix.getColumns())
    {
        for (int i = Matrix::ZEROI; i < leftMatrix.getRows(); i++)
        {
            for (int j = Matrix::ZEROI; j < leftMatrix.getColumns(); j++)
            {
                // rounds to one decimal place.
                double currentLeft = round(leftMatrix.getValue(i, j) * Matrix::TENNER) / Matrix::TENNER;
                double currentRight = round(rightMatrix.getValue(i, j) * Matrix::TENNER) / Matrix::TENNER;

                if(currentLeft != currentRight)
                {
                    return false;
                }
            }
        }

        return true;
    }

    return false;
}

Matrix &Matrix::operator++()
{
    for (int i = ZEROI; i < rows; i++)
    {
        for (int j = ZEROI; j < columns; j++)
        {
            double currentValue = getValue(i, j);

            setValue(i, j, currentValue + ONE);
        }
    }

    return *this;
}

Matrix Matrix::operator++(int)
{
    Matrix temp(*this);
    operator++();

    return temp;
}

Matrix &Matrix::operator--()
{
    for (int i = ZEROI; i < rows; i++)
    {
        for (int j = ZEROI; j < columns; j++)
        {
            double currentValue = getValue(i, j);

            setValue(i, j, currentValue - ONE);
        }
    }

    return *this;
}

Matrix Matrix::operator--(int)
{
    Matrix temp(*this);
    operator--();

    return temp;
}

Matrix &Matrix::operator+=(Matrix &right)
{
    try
    {
        if(rows == right.rows && columns == right.columns)
        {
            for (int i = ZEROI; i < right.rows; i++)
            {
                for (int j = ZEROI; j < right.columns; j++)
                {
                    double thisValue  = getValue(i, j);
                    double rightValue = right.getValue(i, j);

                    setValue(i, j, thisValue + rightValue);
                }
            }
        }
        else
        {
            throw invalid_argument("Matrix sizes do not match!\n");
        }
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    return *this;
}

Matrix operator+(const Matrix& left, const Matrix& right)
{
    Matrix newMatrix(left.rows, right.rows);

    try
    {
        if(left.rows == right.rows && left.columns == right.columns)
        {
            newMatrix.matrixInit(newMatrix.rows, newMatrix.columns);

            for (int i = Matrix::ZEROI; i < newMatrix.getRows(); i++)
            {
                for (int j = Matrix::ZEROI; j < newMatrix.getColumns(); j++)
                {
                    double combinedValue = left.getValue(i, j) + right.getValue(i, j);

                    newMatrix.setValue(i, j, combinedValue);
                }
            }
        }
        else
        {
            throw invalid_argument("Matrix sizes do not match!\n");
        }
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    return newMatrix;
}

Matrix &Matrix::operator-=(Matrix &right)
{
    try
    {
        if(rows == right.rows && columns == right.columns)
        {
            for (int i = ZEROI; i < right.rows; i++)
            {
                for (int j = ZEROI; j < right.columns; j++)
                {
                    double thisValue  = getValue(i, j);
                    double rightValue = right.getValue(i, j);

                    setValue(i, j, thisValue - rightValue);
                }
            }
        }
        else
        {
            throw invalid_argument("Matrix sizes do not match!\n");
        }
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    return *this;
}

Matrix operator-(Matrix left, Matrix &right)
{
    Matrix newMatrix(left.rows, right.rows);

    try
    {
        if(left.rows == right.rows && left.columns == right.columns)
        {
            newMatrix.matrixInit(newMatrix.rows, newMatrix.columns);

            for (int i = Matrix::ZEROI; i < newMatrix.getRows(); i++)
            {
                for (int j = Matrix::ZEROI; j < newMatrix.getColumns(); j++)
                {
                    double subtractedValue = left.getValue(i, j) - left.getValue(i, j);

                    newMatrix.setValue(i, j, subtractedValue);
                }
            }
        }
        else
        {
            throw invalid_argument("Matrix sizes do not match!\n");
        }
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    return newMatrix;
}


Matrix& Matrix::operator*=(double scalar)
{
    for (int i = ZEROI; i < rows; i++)
    {
        for (int j = ZEROI; j < columns; j++)
        {
            double value   = getValue(i,j);
            double product = value *scalar;

            setValue(i,j,product);
        }
    }

    return *this;
}



