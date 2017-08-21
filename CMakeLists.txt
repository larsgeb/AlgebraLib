cmake_minimum_required(VERSION 3.7)
project(LinearAlgebra)

set(CMAKE_CXX_FLAGS "-O4")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES src/algebra_lib/sparse_algebra.cpp src/algebra_lib/sparse_vector.cpp src/algebra_lib/sparse_matrix.cpp src/algebra_lib/matrix.cpp src/algebra_lib/matrix.hpp src/algebra_lib/vector.cpp src/algebra_lib/vector.hpp src/algebra_lib/algebra_lib.hpp src/algebra_lib/full_algebra.cpp src/algebra_lib/full_algebra.hpp src/algebra_lib/globals.hpp)
add_library(LinearAlgebra ${SOURCE_FILES})

set(SOURCE_FILES main.cpp src/algebra_lib/sparse_algebra.cpp src/algebra_lib/sparse_vector.cpp src/algebra_lib/sparse_matrix.cpp src/algebra_lib/matrix.cpp src/algebra_lib/matrix.hpp src/algebra_lib/vector.cpp src/algebra_lib/vector.hpp src/algebra_lib/algebra_lib.hpp src/algebra_lib/full_algebra.cpp src/algebra_lib/full_algebra.hpp src/algebra_lib/globals.hpp)
add_executable(testSuite ${SOURCE_FILES})

#set(SOURCE_FILES SparseAlgebra.cpp SparseMatrix.cpp SparseVector.cpp SparseParallelAlgebra.cpp)
#add_library(LinearParallelAlgebra ${SOURCE_FILES})
#
#set(SOURCE_FILES main.cpp SparseAlgebra.cpp SparseMatrix.cpp SparseVector.cpp SparseParallelAlgebra.cpp)
#add_executable(testParallelSuite ${SOURCE_FILES})
#
#set_target_properties(testParallelSuite PROPERTIES COMPILE_FLAGS "-lpthread")

#set_target_properties( LinearParallelAlgebra PROPERTIES CMAKE_CXX_FLAGS "-lpthread -o" )
#set_target_properties( testParallelSuite PROPERTIES CMAKE_CXX_FLAGS "-lpthread -o" )
