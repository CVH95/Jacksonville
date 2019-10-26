//
// Created by CVH on 27/10/2019
//

#include "Matrix.h"

using namespace std;

int main()
{
    cout << "TRANSFORM MATRIX OPERATIONS - COMMAND LINE TOOL" << endl << endl;

    vector<float> xyz, rpy;
    xyz.resize(3);
    rpy.resize(3);

    cout << "Introduce the first matrix in the form of XYZ (meters) and RPY (radians) vector." << endl;
    cout << "Input value for x: ";
    cin >> xyz.at(0);
    cout << "Input value for y: ";
    cin >> xyz.at(1);
    cout << "Input value for z: ";
    cin >> xyz.at(2);
    cout << "Input value for roll: ";
    cin >> rpy.at(0);
    cout << "Input value for pitch: ";
    cin >> rpy.at(1);
    cout << "Input value for yaw: ";
    cin >> rpy.at(2);

    vector<float> xyz2, rpy2;
    xyz2.resize(3);
    rpy2.resize(3);

    cout << "Introduce the second matrix in the form of XYZ (meters) and RPY (radians) vector." << endl;
    cout << "Input value for x: ";
    cin >> xyz2.at(0);
    cout << "Input value for y: ";
    cin >> xyz2.at(1);
    cout << "Input value for z: ";
    cin >> xyz2.at(2);
    cout << "Input value for roll: ";
    cin >> rpy2.at(0);
    cout << "Input value for pitch: ";
    cin >> rpy2.at(1);
    cout << "Input value for yaw: ";
    cin >> rpy2.at(2);

    Matrix<float> M1(4, 4, 0);
    Matrix<float> M2(4, 4, 0);

    M1 = M1.getTransformMatrix(xyz, rpy, true);
    M2 = M2.getTransformMatrix(xyz2, rpy2, true);

    Matrix<float> X = M1*M2;

    vector<float> final_xyz = X.getTranslationVector(X);
    vector<float> final_rpy = X.getRpyVector(X);

    cout << "XYZ = ";
    X.printVector(final_xyz);
    cout << "RPY = ";
    X.printVector(final_rpy);

    cout << "Designed by @CVH95" << endl;
    return 0;
}
