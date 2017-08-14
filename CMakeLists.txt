cmake_minimum_required(VERSION 3.8)
project(LinearAlgebra)

set (CMAKE_CXX_FLAGS "-O4 -pthread -o")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES  SparseAlgebra.cpp)
add_library(LinearAlgebra ${SOURCE_FILES})

set(SOURCE_FILES main.cpp SparseAlgebra.cpp)
add_executable(testSuite ${SOURCE_FILES})