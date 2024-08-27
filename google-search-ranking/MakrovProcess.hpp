#include <cstdio>
#include "matrix.hpp"
#include "FileReader.hpp"

#pragma once

using namespace std;


class MakrovProcess
{
private:

    // Matrices
    Matrix *matrixG;
    Matrix *matrixS;
    Matrix *matrixQ;
    Matrix *matrixM;

protected:
    // Constants
    const double     ONE     = 1.0;
    const double     ZERO    = 0.0;
    static const int ZEROI   = 0;
    const int        HUNDY   = 100;
    const int        TWO     = 2;
    const double     PROBFAC = 0.85;
    const double     TELEFAC = 0.15;
    const double     convergenceThreshold = 0.0001;

    struct Rank
    {
        vector<double> *oldRank;
        vector<double> *newRank;
        vector<double> *currRank;
    } rank;

public:
    /*
     * Function to start the Markov process.
     *
     * PRE: None.
     * POST: Markov process is initiated and matrices are created.
     */
    static void startMakrov();

    /*
   * Function to create the matrix S.
   *
   * PRE: None.
   * POST: Matrix S is created and values are assigned based on the input data.
   */
    explicit MakrovProcess(vector<double> parsedVec);

    /*
    * Function to create the matrix S from Connectivity Q matrix.
    *
    * PRE: vector needs to be a square matrix.
    * POST: Matrix S is created and values are assigned based on the input data.
    */
    void createSMatrix();

    /*
    * Function to create the matrix Q.
    *
    * PRE: None.
    * POST: Matrix Q is created and values are assigned.
    */
    void createQMatrix();

    /*
     * Function to create the matrix M by equation M = p * S + (1-p) * Q
     *
     * PRE: Matrices S and Q are required to create M.
     * POST: Matrix M is created as the sum of S and Q.
     */
    void createMMatrix();

    /*
    * Function to perform matrix-vector multiplication.
    *
    * PRE: A matrix and a vector are required.
    * POST: The result of the multiplication is returned.
    */
    vector<double> matrixVectorMultiply(const Matrix &matrix, vector<double> &v);

    /*
    * Function to run the Markov process recursively.
    *
    * PRE: Previous and current ranks are provided.
    * POST: The Markov process is applied, and the updated rank is returned.
    */
    vector<double> *runMarkovProcess(vector<double> *previousRank, vector<double> *currRank);

    /*
     * Function to process the Markov algorithm.
     *
     * PRE: None.
     * POST: The Markov algorithm is executed, and results are printed.
     */
    void makrovProcessor();

/**getters required for memory deletion**/
    Matrix *getMatrixG() const;

    Matrix *getMatrixS() const;

    Matrix *getMatrixQ() const;

    Matrix *getMatrixM() const;
};

