cmake_minimum_required(VERSION 3.7)
project(LinearAlgebra)

#set(CMAKE_CXX_FLAGS "-O4")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES SparseAlgebra.cpp SparseVector.cpp SparseMatrix.cpp)
add_library(LinearAlgebra ${SOURCE_FILES})

set(SOURCE_FILES main.cpp SparseAlgebra.cpp SparseVector.cpp SparseMatrix.cpp)
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
