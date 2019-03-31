//
// Created by CVH on 30/03/2019
//

#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "Matrix.h"


// CONSTRUCTOR
template<typename T>
Matrix<T>::Matrix(int rows, int columns, const T& init)
//Matrix::Matrix(int rows, int columns, const float init)
{
    ROWS = rows;
    COLS = columns;
    mat.resize(ROWS);
    for(int i=0; i<mat.size(); i++)
    {
        mat[i].resize(COLS, init);
    }
}


// COPY CONSTRUCTOR                                                                                                                                                           
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& rhs) 
{
    mat = rhs.mat;
    ROWS = rhs.getRows();
    COLS = rhs.getColumns();
}


// DESTRUCTOR
template<typename T>
Matrix<T>::~Matrix()
//Matrix::~Matrix()
{
    cout << "Matrix succesfully destroyed." << endl;
}


//----------------------------------------------------------------------------------------------------


// PUBLIC METHODS


// Get number of rows
template<typename T>
int Matrix<T>::getRows() const
//int Matrix::getRows()
{
    return this->ROWS;
}
        
// Get number of columns
template<typename T>
int Matrix<T>::getColumns() const
//int Matrix::getColumns()
{
    return this->COLS;
}


// Print whole matrix
template<typename T>
void Matrix<T>::printMatrix()
//void Matrix::printMatrix()
{   
    int r = getRows();
    int c = getColumns();
    int limit = c-1;
    cout << "Matrix[" << r << "][" << c << "]:" << endl << endl; 
    for(int i=0; i<r; i++)
    {   
        for(int j=0; j<c; j++)
        {
            if(j == limit)
            {
                cout << this->mat[i][j];
            }
            else
            {
                cout << this->mat[i][j] << ",";
            }
        }
        cout << endl;
    }
    cout << endl;
}


// Get individual element
template<typename T>
T& Matrix<T>::getElement(int row, int col)
{
    return this->mat[row][col];
}


// Update individual value 
template<typename T>
void Matrix<T>::updateElement(int row, int col, T value)
{
    mat[row][col] = value;
}


//----------------------------------------------------------------------------------------------------


// OPERATORS


// Access individual elements
template<typename T>
T& Matrix<T>::operator()(const int& row, const int& col)
{
    return this->mat[row][col];
}


//----------------------------------------------------------------------------------------------------


// ALGEBRA


// Multiplication of a matrix A (m x n) by a vector v (n x 1) 
template<typename T>
vector<T> Matrix<T>::matrixByColumnVector(vector<T> vec)
{
    // Declare result vector
    vector<T> result;

    int vecRows = vec.size();
    int c = this->COLS;
    int r = this->ROWS;
    result.resize(r, 0);
    if (vecRows == c)
    {
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                result[i] += this->mat[i][j] * vec[j];
            }
        }
        return result;
    }
    else
    {
        cout << "ERROR: Invalid vector size!" << endl;
        result.resize(r, 0);
        return result;
    }
}


// Multiplication of a row vector (1 x m) by a matrix (m x n)
template<typename T>
vector<T> Matrix<T>::rowVectorByMatrix(vector<T> vec)
{
    // Declare result vector
    vector<T> result;

    int vecCols = vec.size();
    int c = this->COLS;
    int r = this->ROWS;
    result.resize(c, 0);
    if (vecCols == r)
    {
        for(int i=0; i<c; i++)
        {
            for(int j=0; j<r; j++)
            {
                result[i] += this->mat[j][i] * vec[j];
            }
        }
        return result;
    }
    else
    {
        cout << "ERROR: Invalid vector size!" << endl;
        result.resize(c, 0);
        return result;
    }
}


// Multiplication of Column vector (m x 1) by a row vector (1 x m) 
template<typename T>
Matrix<T> Matrix<T>::columnVectorByRowVector(vector<T> a, vector<T> b)
{   
    Matrix<T> result(a.size(), b.size(), 0);
    if(a.size() == b.size())
    {
        // Initialize Matrix
        int r = a.size();
        int c = b.size();

        // Calculate elements:
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                result.updateElement(i, j, a[i]*b[j]);
            }
        } 
        return result;
    }
    else
    {
        // Initialize Matrix
        int r = a.size();
        int c = b.size();
        cout << "ERROR: Invalid vector size!" << endl;
        return result;
    }
}


// Transpose
template<typename T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix t(COLS, ROWS, 0);
    for(int i=0; i<COLS; i++)
    {
        for(int j=0; j<ROWS; j++)
        {
            t.updateElement(i, j, this->mat[j][i]);
        }
    }
    return t;
}


//----------------------------------------------------------------------------------------------------


#endif //MATRIX_CPP