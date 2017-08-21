//
// Created by Lars Gebraad on 14-8-17.
//

#ifndef LINEARALGEBRA_SPARSEPARALLELALGEBRA_HPP
#define LINEARALGEBRA_SPARSEPARALLELALGEBRA_HPP

#include <vector>
#include <thread>
#include "sparse_algebra.hpp"

sparse_vector ParallelMatrixVector(const sparse_matrix &A, const sparse_vector &U);

#endif //LINEARALGEBRA_SPARSEPARALLELALGEBRA_HPP
