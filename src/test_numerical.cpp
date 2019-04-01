//
// Created by CVH on 30/03/2019
//

#include "Matrix.h"

using namespace std;

int main()
{
    cout << "TESTING THE MATRIX CLASS" << endl << endl;

    cout << "1. Testing determinant:" << endl << endl;

    Matrix<float> M(3, 3, 1);
    M.updateElement(0, 0, 7);
    M.updateElement(0, 2, 3);
    M.updateElement(1, 0, 2);
    M.updateElement(1, 1, 4);
    M.updateElement(2, 1, 5);

    M.printMatrix();
    int size = M.getColumns();
    float det = M.getDeterminant(size);
    cout << "Det(M) = " << det << endl << endl;

    cout << "2. Testing scalar multiplication:" << endl << endl;
    Matrix<float> DoubleM = M.scalarTimesMatrix(2);
    cout << "M · 2 = " << endl << endl;
    DoubleM.printMatrix();

    cout << "3. Testing adjoint:" << endl << endl;
    
    cout << "adj(M) = " << endl << endl;
    Matrix<float> adjM = M.adjoint();
    adjM.printMatrix();

    cout << "4. Testing inverse:" << endl << endl;

    cout << "inv(M) = " << endl << endl;
    Matrix<float> invM = M.inverse();
    invM.printMatrix();

    cout << "Test Completed." << endl;
    return 0;
}
