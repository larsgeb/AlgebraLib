cmake_minimum_required(VERSION 3.7)
project(LinearAlgebra)

#set(CMAKE_CXX_FLAGS "-O4")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES src/algebra_lib/sparse_algebra.cpp src/algebra_lib/sparse_vector.cpp src/algebra_lib/sparse_matrix.cpp src/algebra_lib/matrix.cpp src/algebra_lib/matrix.hpp src/algebra_lib/vector.cpp src/algebra_lib/vector.hpp src/algebra_lib/algebra_lib.hpp src/algebra_lib/full_algebra.cpp src/algebra_lib/full_algebra.hpp src/algebra_lib/globals.hpp src/algebra_lib/sparse_parallel_algebra.cpp)
add_library(LinearAlgebra ${SOURCE_FILES})

set(SOURCE_FILES main.cpp src/algebra_lib/sparse_algebra.cpp src/algebra_lib/sparse_vector.cpp src/algebra_lib/sparse_matrix.cpp src/algebra_lib/matrix.cpp src/algebra_lib/matrix.hpp src/algebra_lib/vector.cpp src/algebra_lib/vector.hpp src/algebra_lib/algebra_lib.hpp src/algebra_lib/full_algebra.cpp src/algebra_lib/full_algebra.hpp src/algebra_lib/globals.hpp)
add_executable(testSuite ${SOURCE_FILES})

set(SOURCE_FILES src/algebra_lib/sparse_algebra.cpp src/algebra_lib/sparse_parallel_algebra.cpp src/algebra_lib/sparse_vector.cpp src/algebra_lib/sparse_matrix.cpp src/algebra_lib/matrix.cpp src/algebra_lib/matrix.hpp src/algebra_lib/vector.cpp src/algebra_lib/vector.hpp src/algebra_lib/algebra_lib.hpp src/algebra_lib/full_algebra.cpp src/algebra_lib/full_algebra.hpp  src/algebra_lib/sparse_parallel_algebra.hpp src/algebra_lib/globals.hpp)
add_library(LinearPAlgebra ${SOURCE_FILES})

set(SOURCE_FILES main.cpp src/algebra_lib/sparse_algebra.cpp src/algebra_lib/sparse_parallel_algebra.cpp
        src/algebra_lib/sparse_vector.cpp src/algebra_lib/sparse_matrix.cpp src/algebra_lib/matrix.cpp src/algebra_lib/matrix.hpp src/algebra_lib/vector.cpp src/algebra_lib/vector.hpp src/algebra_lib/algebra_lib.hpp src/algebra_lib/full_algebra.cpp src/algebra_lib/full_algebra.hpp  src/algebra_lib/sparse_parallel_algebra.hpp src/algebra_lib/globals.hpp)
add_executable(testPSuite ${SOURCE_FILES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(testPSuite Threads::Threads)

set_target_properties( LinearPAlgebra PROPERTIES CMAKE_CXX_FLAGS "-lpthread -o" )
set_target_properties( testPSuite PROPERTIES CMAKE_CXX_FLAGS "-lpthread -o" )

