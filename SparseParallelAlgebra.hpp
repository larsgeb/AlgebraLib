//
// Created by Lars Gebraad on 14-8-17.
//

#ifndef LINEARALGEBRA_SPARSEPARALLELALGEBRA_HPP
#define LINEARALGEBRA_SPARSEPARALLELALGEBRA_HPP

#include <vector>
#include <thread>
#include "SparseAlgebra.hpp"

SparseVector ParallelMatrixVector(const SparseMatrix &A, const SparseVector &U);

#endif //LINEARALGEBRA_SPARSEPARALLELALGEBRA_HPP
