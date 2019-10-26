cmake_minimum_required(VERSION 2.8.3)
project(test_matrix)

set (CMAKE_CXX_STANDARD 11)

# Includes
INCLUDE_DIRECTORIES(include)

# Set output paths
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Build Shared Libraries
add_library(Matrix SHARED include/Matrix.cpp)

# Build executables
add_executable(test_matrix src/basic_test.cpp)
target_link_libraries(test_matrix Matrix)

add_executable(test_numerical src/test_numerical.cpp)
target_link_libraries(test_numerical Matrix)

add_executable(test_operators src/test_operators.cpp)
target_link_libraries(test_operators Matrix)

# Build the command line matrix calculator
add_executable(mat_calculator src/command_line_matrix_tool.cpp)
target_link_libraries(mat_calculator Matrix)
