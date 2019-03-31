//
// Created by CVH on 30/03/2019
//

#include "Matrix.h"

using namespace std;

int main()
{
    cout << "TESTING THE MATRIX CLASS" << endl << endl;

    cout << "1. Testing Matrix initialization and basic functionalities:" << endl << endl;

    // Create pointer to Matrix Object
    Matrix<float>  m(5, 5, 1.0);

    m.printMatrix();

    // Get individual element
    float el24 = m.getElement(2, 4);
    cout << "M(2,4) = " << el24 << endl << endl;

    // Assign new value to individual element
    m.updateElement(2, 4, 4.0);
    cout << "Updated element at row 2, column 4." << endl;
    el24 = m.getElement(2, 4);
    cout << "M(2,4) = " << el24 << endl;
    cout << "M(1,3) = " << m(1,3) << endl << endl;

    m.printMatrix();

    // Multiplication by column vector
    cout << "2. Testing Matrix by Column vector multiplication:" << endl << endl;

    Matrix<int> A(2, 3, 2);
    A.updateElement(1, 2, -1);
    cout << "Matrix size = " << A.getRows() << " x " << A.getColumns() << endl;
    A.printMatrix();

    vector<int> v = {1, 2, 4};
    cout << "Vector v =";
    for(int i=0; i<v.size(); i++)
    {
        cout << " " << v[i];
    }
    cout << endl << endl;

    vector<int> res = A.matrixByColumnVector(v);
    cout << "res (m x 1) = A (m x n) * v (n x 1)" << endl;
    cout << "Vector res =";
    for(int i=0; i<res.size(); i++)
    {
        cout << " " << res[i];
    }
    cout << endl << endl;

    // ERROR in multiplication
    cout << "3. Testing Matrix by Column vector multiplication ERROR:" << endl << endl;
    cout << "Matrix size = " << A.getRows() << " x " << A.getColumns() << endl;
    A.printMatrix();
    
    vector<int> w = {1, 2, 4, 3};
    cout << "Vector w =";
    for(int i=0; i<w.size(); i++)
    {
        cout << " " << w[i];
    }
    cout << endl << endl;

    vector<int> res2 = A.matrixByColumnVector(w);
    cout << "res (m x 1) = A (m x n) * v (n x 1)" << endl;
    cout << "Vector res =";
    for(int i=0; i<res2.size(); i++)
    {
        cout << " " << res2[i];
    }
    cout << endl << endl;

    // Column Vector by Row Vector multiplication
    cout << "4. Testing Column Vector by Row Vector multiplication:" << endl << endl;

    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, -1};
    cout << "Vector a =";
    for(int i=0; i<a.size(); i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
    cout << "Vector b =";
    for(int i=0; i<b.size(); i++)
    {
        cout << " " << b[i];
    }
    cout << endl << endl;

    cout << "R = a (m x 1) * b (1 x m)" << endl;
    Matrix<int> R(3, 3, 0);
    R = R.columnVectorByRowVector(a, b);
    R.printMatrix();

    // ERROR in vectors multiplication
    cout << "5. Testing Column Vector by Row Vector multiplication:" << endl << endl;

    vector<int> c = {1, 2, 3, 4};
    cout << "Vector c =";
    for(int i=0; i<c.size(); i++)
    {
        cout << " " << c[i];
    }
    cout << endl;

    cout << "R = a (m x 1) * c (1 x n)" << endl;
    R = R.columnVectorByRowVector(a, c);
    R.printMatrix();

    // Row vector by matrix multiplication
    cout << "6. Testing Row Vector by Matrix multiplication:" << endl << endl;

    Matrix<int> H(3, 2, 2);
    H.updateElement(2, 0, 1);
    H.updateElement(1,1, 0);
    cout << "Matrix size = " << H.getRows() << " x " << H.getColumns() << endl;
    H.printMatrix();
    
    vector<int> x = {1, 2, -1};
    cout << "Vector x =";
    for(int i=0; i<x.size(); i++)
    {
        cout << " " << x[i];
    }
    cout << endl << endl;

    vector<int> y = H.rowVectorByMatrix(x);
    cout << "y (1 x n) = x (1 x m) * H (m x n)" << endl;
    cout << "Vector y =";
    for(int i=0; i<y.size(); i++)
    {
        cout << " " << y[i];
    }
    cout << endl << endl;

    cout << "7. Testing transpose matrix:" << endl << endl;

    cout << "Transpose of H = " << endl << endl;
    H = H.transpose();
    H.printMatrix();

    cout << "Test Completed" << endl;

    return 0;
}