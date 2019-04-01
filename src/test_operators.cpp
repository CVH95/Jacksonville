//
// Created by CVH on 30/03/2019
//

#include "Matrix.h"

using namespace std;

int main()
{
    cout << "TESTING THE MATRIX CLASS" << endl << endl;

    cout << "1. Testing Matrix operators:" << endl << endl;

    Matrix<double> M(4, 4, 5.0);
    cout << "M = " << endl << endl;
    M.printMatrix();

    Matrix<double> N(4, 4, 2.0);
    cout << "N = " << endl << endl;
    N.printMatrix();

    Matrix<double> P = M + N;
    cout << "P = M + N =" << endl << endl;
    P.printMatrix();

    Matrix<double> Q = M - N;
    cout << "Q = M - N =" << endl << endl;
    Q.printMatrix();

    Matrix<double> R = M * N;
    cout << "R = M * N =" << endl << endl;
    R.printMatrix();

    cout << "2. Testing scalar addition / substraction:" << endl << endl;

    Matrix<double> X = M.scalarPlusMatrix(3.0);
    cout << "X = M + 3 =" << endl << endl;
    X.printMatrix();

    Matrix<double> Y = M.scalarMinusMatrix(4.0);
    cout << "Y = M - 4 =" << endl << endl;
    Y.printMatrix();

    cout << "3. Testing diagonal vector:" << endl << endl;

    vector<double> z = Y.diagonalVector();
    cout << "Vector z = diag(Y) = ";
    for(int i=0; i<z.size(); i++)
    {
        cout << " " << z[i];
    }
    cout << endl << endl; 

    cout << "Test Completed" << endl;

    return 0;
}