# DOCUMENTATION 

Simple **Matrix template class** in C++ with a few general utilities and mathematical operations. The objective of this class is to have a structured matrix data type that can be added to any project and allows for easy data storing, carrying and accessing in matrix form, as well as performing algebraic calculations on such data. 

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

**D. Printing the matrix in the console.**

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

#### 2.4.2. Matrix Transformations

**A. Transpose.**

 - `Matrix<T> transpose();`

Returns the transpose of the original matrix.

**B. Inverse.**

_To be implemented_.

## AUTHOR

 - Carlos Viescas.
 - cavie17@student.sdu.dk
 - MSc Robot Systems, University of Southern Denmark.

## REFERENCES

 - [Math Insight](https://mathinsight.org/matrix_vector_multiplication).
 - [QuantStart](https://www.quantstart.com/articles/Matrix-Classes-in-C-The-Header-File)