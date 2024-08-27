#pragma once
#include <vector>
#include <iostream>
#include <cmath>


using namespace std;

/*
 * Matrix class. Represents a rows by columns matrix containing double values.
 *
 *      Instance variables: - 2D array of doubles (acting as the matrix).
 *                          - numbers of rows in the matrix.
 *                          - numbers of columns in the matrix.
 *
 *  Authors: Randall Kong and Xavier Roy Pimentel
 */
class Matrix {


private:
    const int DEFAULT_ROWS = 1;
    const int DEFAULT_COLUMNS = 1;
    double **matrix{};
    int rows;
    int columns;

    /*
     * Function that initializes the matrix and allocates memory for all indices.
     *
     * PRE: number of rows and columns are passed in as the parameter.
     * POST:
     *
     * Sample IO:
     *      Input: rows = 2, columns = 2
     *      Background: Allocating memory for indices from [0, 0] to [1, 1]
     */
    void matrixInit(int rows, int columns);

public:
    const double ONE = 1.0;
    static const int ZEROI = 0;
    const double ZEROD = 0.0;
    const int HUNDY = 100;
    static const int TENNER = 10;
    const int TWO = 2;

    /*
     * Function that swaps the values of the two Matrix objects.
     *
     * PRE: Two Matrix objects are passed in.
     * POST: Values are swapped for the two Matrix's.
     */
    static void matrixSwap(Matrix& first, Matrix& second);

    /*
     * Function that initializes/sets all the doubles in the matrix to 0.0.
     *
     * PRE:
     * POST: Sets all the values in the matrix to 0.0.
     */
    void clear();


    /*
     * Checks if an integer is a square.
     *
     * PRE: Integer is passed in as the parameter.
     * POST: If arg is a square, return true.
     *       If arg is not a square, return false.
     *
     *
     * Sample IO:
     *      Input: num = 4
     *      Output: true
     *
     *      Input: num = 3
     *      Output: false
     */
    static bool isSquare(int num);

    /*
     * Function populate the matrix with values in the vector.
     *
     * PRE: Vector of doubles passed in.
     * POST: Populates the matrix with the values in the vector.
     */
    void populateMatrix(const vector<double> &nums);

    /*
     * Default constructor.
     *
     * PRE:
     * POST: Initialize the matrix with DEFAULT_ROWS and DEFAULT_COLUMNS sizes and assigns all the indices to 0.0.
     */
    Matrix();

    /*
    * Destructor.
    *
    * PRE:Requires a  Matrix object
    * POST: frees allocated Matrix obj memory..
    */
    ~Matrix();

    /*
     * n x n Matrix Constructor.
     *
     * PRE: Single integer is passed in.
     * POST: Initializes the n by n matrix and 0.0's out all the indices.
     * CONDITIONS: If n is 0 or a negative number, exception is thrown.
     */
    explicit Matrix(int n);

    /*
     * r x c Matrix Constructor.
     *
     * PRE: Two integers are passed in (r and c, represent rows and columns).
     * POST: Initializes the r by c matrix and 0.0's out all the indices.
     * CONDITIONS: If (r or c) is 0 or a negative number, exception is thrown.
     */
    Matrix(int r, int c);

    /*
     * Set value Constructor.
     *
     * PRE: Vector of doubles is passed in.
     * POST: Initializes the sqrt(vector.size) by sqrt(vector.size) Matrix and
     *          adds the vector values to the matrix row by row.
     *
     * CONDITIONS: If vector size is not square (ex. 1, 4, 9, 16, etc.), an exception is thrown.
     */
    explicit Matrix(const vector<double> &nums);

    /*
     * Copy Constructor.
     *
     * PRE:
     * POST: All values from the passed in Matrix object are copied to the newly created Matrix.
     */
    Matrix(const Matrix &other);

    /*
     * populates matrix for copy constructro.
    *
    * PRE: Matrix not null
    * POST: All values from the passed in Matrix object are copied to the newly created Matrix.
    */
    void populateMatrix(const Matrix &other);


    /*
     * Function that sets a specific index's value in the matrix.
     *
     * PRE: Two integers and a double are passed in(row, column and value).
     * POST: Sets the index's value to the value passed in.
     * CONDITION: If the integers are negative or not a real index, an exception is thrown.
     */
    void setValue(int row, int column, double value);

    /*
     * Function that gets the value of a specific index in the matrix.
     *
     * PRE: Two integers are passed in(row, column).
     * POST: Returns the index's value.
     * CONDITION: If the integers are negative or not a real index, an exception is thrown.
     */
    double getValue(int row, int column) const;

    /*
     * Getter for the amount of rows in the matrix.
     *
     * PRE:
     * POST: Returns the amount of rows in the matrix.
     */
    int getRows() const;

    /*
     * Getter for the amount of columns in the matrix.
     *
     * PRE:
     * POST: Returns the amount of columns in the matrix.
     */
    int getColumns() const;

    /*
     * Overridden insertion operator.
     *
     * PRE: Ex operator call: cout << {Matrix object};
     * POST: Prints all the doubles in the matrix.
     */
    friend ostream & operator<<(ostream &os, Matrix &thisMatrix);

    /*
     * Overridden equals operator.
     *
     * PRE: Ex operator call: {Matrix object} == {Matrix object};
     * POST: True if number of rows/columns are the same and if all the values are the same.
     *      False if the number of rows/columns is different or the values are different.
     */
    friend bool operator==(Matrix &leftMatrix, Matrix &rightMatrix);

    /*
     * Overridden inequality operator.
     *
     * Note: Tolerence is to one decimal place.
     *
     * PRE: Ex operator call: {Matrix object} != {Matrix object};
     * POST: True if the number of rows/columns are different or the values are different.
     *       False if the number of rows/columns are different and the values are the same.
     */
    friend bool operator!=(Matrix &leftMatrix, Matrix &rightMatrix){ return !(leftMatrix == rightMatrix);}

    /*
     * Overridden pre increment operator.
     *
     * PRE: Ex operator call: ++{Matrix object};
     * POST: Increment each value in the matrix by 1 (Matrix returned after incrementation).
     */
    Matrix& operator++();

    /*
     * Overridden post increment operator.
     *
     * PRE: Ex operator call: {Matrix object}++;
     * POST: Increment each value in the matrix by 1 (Matrix returned before incrementation).
     */
    Matrix operator++(int);

    /*
     * Overridden pre decrement operator.
     *
     * PRE: Ex operator call: --{Matrix object};
     * POST: Decrement each value in the matrix by 1 (Matrix returned after decrement).
     */
    Matrix& operator--();

    /*
     * Overridden post decrement operator.
     *
     * PRE: Ex operator call: {Matrix object}--;
     * POST: Decrement each value in the matrix by 1 (Matrix returned before decrement).
     */
    Matrix operator--(int);

    /*
     * Overridden assignment operator.
     *
     * PRE: Ex operator call: {Matrix object} = {Matrix object};
     * POST: Transfer all the values from the right matrix to the left matrix.
     *
     */
    Matrix& operator=(Matrix other){ matrixSwap(*this, other); return *this;}

    /*
     * Overridden assignment/addition operator.
     *
     * PRE: Ex operator call: {Matrix object} += {Matrix object};
     * POST: Adds all the values in the matrices and assigns it to the left matrix.
     * CONDITION: Matrices must be the same size.
     */
    Matrix& operator+=(Matrix& right);

    /*
     * Overridden addition operator.
     *
     * PRE: Ex operator call: {Matrix object} = Matrix object} + {Matrix object};
     * POST: Combines all the values in the matrices.
     * CONDITION: Matrices must be the same size.
     */
    friend Matrix operator+(const Matrix& left, const Matrix& right);

    /*
     * Overridden assignment/subtraction operator.
     *
     * PRE: Ex operator call: {Matrix object} -= {Matrix object};
     * POST: Subtracts the values in the left matrix from the values in the right matrix.
     * CONDITION: Matrices must be the same size.
     */
    Matrix& operator-=(Matrix& right);

    /*
     * Overridden subtraction operator.
     *
     * PRE: Ex operator call: {Matrix object} = {Matrix object} - {Matrix object};
     * POST: Subtracts the values in the left matrix from the values in the right matrix.
     * CONDITION: Matrices must be the same size.
     */
    friend Matrix operator-(Matrix left, Matrix& right);

    /*
  * Overridden multiplication calculator for ease of use.
  *
  * PRE: Ex operator call: {Matrix object} = {scalar} - {scalar};
  * POST: Multiplies each element in matrix with scalar
  * CONDITION: Matrices must be the same size.
  */
    Matrix& operator*=(double scalar);



};
