//
// Created by CVH on 30/03/2019
//

#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> class Matrix
{
    public:

        // Constructor
        Matrix(int rows, int columns, const T& init);
        
        // Copy constructor
        Matrix(const Matrix<T>& rhs);

        // Destructor
        virtual ~Matrix();

        // PUBLIC METHODS
        
        int getRows() const; // Get Matrix Size
        int getColumns() const; // Get Matrix Size
        void printMatrix(); // Print complete matrix
        T& getElement(int row, int col); // Get individual element
        void updateElement(int row, int col, T value); // Update individual element
        
        
        // OPERATORS

        T& operator()(const int& row, const int& col);

        // ALGEBRA
        
        // Multiplications
        vector<T> matrixByColumnVector(vector<T> vec);// Matrix by Column Vector multiplication (result = vector)
        vector<T> rowVectorByMatrix(vector<T> vec);// Row Vector by Matrix Multiplication (result = )
        Matrix<T> columnVectorByRowVector(vector<T> a, vector<T> b);// Column Vector by Row Vector multiplication (result = Matrix)
        
        // Transformations
        Matrix<T> transpose(); // Transpose of the original matrix.

    private:

        int ROWS;
        int COLS;
        vector<vector<T> > mat;
};

#include "Matrix.cpp"

#endif //MATRIX_H