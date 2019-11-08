# DOCUMENTATION 

Simple **Matrix template class** in C++ with a few general utilities and mathematical operations. The objective of this class is to have a structured matrix data type that can be added to any project, allowing easy data storing, carrying and accessing in matrix form, as well as performing algebraic calculations on such data.

The Matrix Class **.h** and **.cpp** templates are in _include/_. The folder _src/_ contains source to test programs. The output of this tests can be seen in the .txt files in _genfiles/_ and used for checking that the class compiled fine.

## 1. Build and Compile

### 1.1. Compilation

```sh
# Clone repo
$ git clone <url> Matrix

# Create building directories and compile with CMake
$ mkdir build bin lib
$ cd build/
$ cmake ../
$ make
```

### 1.2. Running test

```sh
$ cd ../bin
$ ./test_matrix #For running the basic initialization test
```

### 1.3. Adding the matrix class to another project

In the project's root folder create a new directory called **_include_**. Then, Copy the files **_Matrix.h_** and **_Matrix.cpp_** to it. Create an empty directory called lib in the root folder.

In the CMake file of the project add the following lines:
```cmake
# At the beginning, after setting the CMakeLists version and project name
INCLUDE_DIRECTORIES(include) 
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Build Shared Libraries
add_library(Matrix SHARED include/Matrix.cpp)


# Add the library to your executables:
add_executable(exec_name src/source_code.cpp)
target_link_libraries(exec_name Matrix)
```

## 2. Description:

### 2.1. The Matrix class

#### 2.1.2. Initialization

**A. Constructor**

 - `Matrix(int rows, int columns, const T& init);`

Requires the number of rows and columns and an intial value to fill the matrix up. As it is a template, requires specifiying the data type inside the matrix:

```c++
// Initialization
Matrix<int> M(2, 3, 0);
```

**B. Copy constructor**

 - `Matrix(const Matrix<T>& A);`

Requires another matrix as argument.

### 2.2. General Purpose Methods

#### 2.2.1. Accessing elements and matrix parameters.

**A. Matrix size.**

Get the number of rows and columns of the matrix:

 - `int getRows() const;`
 - `int getColumns() const;` 

Member functions that do not modify the class instance should be declared as **_const_**. Functions that are useful to resize new matrices and vectors resulting from mathematical operations.

**B. Accessing individual elements.**

 - `T& getElement(int row, int col);`

Returns the element at selected row and column.

**C. Updating individual elements.**

 - `void updateElement(int row, int col, T value);`

Updates the value of the element at the selected row and column.

#### 2.2.2. Other.

**A. Printing the matrix in the console.**

 - `printMatrix();`

Just outputs it as:

```sh
Matrix[3][3]:

1,2,-1
2,4,-2
3,6,-3
```

### 2.3. Operators

#### 2.3.1. Accessing elements

**A. Using ( ) to acces matrix element.**

 - `T& operator()(const int& row, const int& col);`

Returns the element **M(row, col)**.

 - `const T& operator()(const unsigned& row, const unsigned& col) const`

Returns **const** element at the selected row and column.

#### 2.3.2. Algebraic operators

**A. Assignment operator.**
 
 - `Matrix<T>& operator=(const Matrix<T>& A);`

This operation is needed to produce new matrices resulting from the below operations (like C = A + B).  

**B. Sum operator.**

 - `Matrix<T> operator+(const Matrix<T>& A);`

Sum of two matrices.

**C. Substraction operator.**

 -`Matrix<T> operator-(const Matrix<T>& A);`

Substraction of two matrices.

**D. Multiplication operator.**

 -`Matrix<T> operator*(const Matrix<T>& A);` 

Multiplication of two matrices.

### 2.4. Algebraic Operations

#### 2.4.1. Matrix Multiplications

**A. Product of a matrix times a column vector.**

 - `vector<T> matrixByColumnVector(vector<T> vec);`

Returns the vector **z** resulting from the operation **z [m x 1] = A [m x n] * v [n x 1]**.
If the number of columns in **A** and the size of **v** do not match, returns a vector of zeros and an error message.

**B. Product of a column vector times a row vector.**

- `Matrix<T> columnVectorByRowVector(vector<T> a, vector<T> b);`

Returns the matrix **R** resulting from the operation **R [m x m] = a [m x 1] * b [1 x m]**.
If the size of **a** and **b** do not match, returns a matrix of zeros and an error message.

**C. Product of a row vector times a matrix.**

 - `Matrix<T> columnVectorByRowVector(vector<T> a, vector<T> b);`

 Returns the vector **y** resulting from the operation **y (1 x n) = x (1 x m) * H (m x n)**.
If the size of **x** does not match with the number of rows in **H**, returns a vector of zeros and an error message.

#### 2.4.2. Numerical Operations.

**A. Determinant of the matrix.**

 - `void getCoFactors(vector<vector<T> > array, vector<vector<T> >& temp, int size, int r, int c);` 

Calculates co-factors at a given matrix position and stores them in a vector. 

 - `T iterateDet(vector<vector<T> > array, int size);` 

Performs the iteration over the several co-factors needed to get the determinant of the matrix.

 - `T getDeterminant(int size);` 

Calls both of the previous functions and returns the final value of the determinant. Returns error and an empty matrix if it is not square. See [this video](https://www.youtube.com/watch?v=KLaAE22fk60) for more details on how to calculate the determinant of a large matrix.

**B. Multiplication of a matrix by a scalar.**

 - `Matrix<T> scalarTimesMatrix(T scalar);`

Returns a matrix resulting for multiplying a single scalar times itself. 
Use it to perform scalar division as **Matrix * 1/scalar**.

**B. Sum of a matrix by a scalar.**

 - `Matrix<T> scalarPlusMatrix(T scalar);`

Returns a matrix resulting for adding a single scalar to it. 

**D. Substraction of a matrix by a scalar.**

 - `Matrix<T> scalarMinusMatrix(T scalar);`

Returns a matrix resulting for substracting a single scalar to it. 

**E. Diagonal Vector.**

 - `vector<T> diagonalVector();` 

Returns a vector with the diagonal components of the square matrix. 

#### 2.4.3. Matrix Transformations

**A. Identity Matrix.**

 - `Matrix<T> identity();`

Returns the identity matrix of the size used to construct the matrix.

**B. Transpose Matrix.**

 - `Matrix<T> transpose();`

Returns the transpose of the original matrix.

**C. Adjoint Matrix.**

 - `Matrix<T> adjoint();`

Returns the adjoint matrix of the input one. Returns error and an empty matrix if it is not square. See more details about the adjoint matrix [here](https://en.wikipedia.org/wiki/Adjugate_matrix).

**D. Inverse of the Matrix.**

 - `Matrix<T> inverse();`

Returns the inverse of the given matrix A: **inv(A) = adj(A) * 1/det(A)** . Returns error and an empty matrix if it is not square.

#### 2.4.3. Upcoming features.

**New methods for:**

  - Computation of rotation matrices from RPY angles.
  - Computation of RPY vectors from rotation matrices.
  - Computation of Homogeneous Transform matrices from translation + RPY vectors.
  - Computation of Homogeneous Transfrom matrices from translation vector + rotation matrix.
  - Hadamard product between 2 matrices.
  - Hadamard product between 2 vectors.

**Integration improvements:**

  - Encapsulation of the matrix class under the namespace **matrixTemplateClass**.
  - Install source from CMake, so that the package binary can be integrated in any project with `find_package()`.

## AUTHOR

 - Carlos Viescas.
 - cavie17@student.sdu.dk
 - MSc Robot Systems, University of Southern Denmark.

## REFERENCES

 - [Math Insight](https://mathinsight.org/matrix_vector_multiplication).
 - [QuantStart](https://www.quantstart.com/articles/Matrix-Classes-in-C-The-Header-File)
 - [Determinant](https://www.geeksforgeeks.org/determinant-of-a-matrix/) of large matrices.
