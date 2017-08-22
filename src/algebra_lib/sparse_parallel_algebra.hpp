//
// Created by Lars Gebraad on 14-8-17.
//

#ifndef LINEARALGEBRA_SPARSEPARALLELALGEBRA_HPP
#define LINEARALGEBRA_SPARSEPARALLELALGEBRA_HPP

#include "globals.hpp"
#include "sparse_vector.hpp"
#include "sparse_matrix.hpp"

namespace algebra_lib {
//    sparse_vector ParallelMatrixVector(const sparse_matrix &A, const sparse_vector &U);

    sparse_matrix ParallelMatrixProduct(const sparse_matrix &A, const sparse_matrix &B);

}
#endif //LINEARALGEBRA_SPARSEPARALLELALGEBRA_HPP
