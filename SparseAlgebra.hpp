//
// Created by Lars Gebraad on 14-8-17.
//

#ifndef LINEARALGEBRA_MATRIX_H_H
#define LINEARALGEBRA_MATRIX_H_H


#include <utility>
#include <iostream>
#include "SparseVector.hpp"
#include "SparseMatrix.hpp"

//class SparseRow;
//
//class SparseColumn;


SparseMatrix MatrixMultiplication(const SparseMatrix &A, const SparseMatrix &B);

SparseVector operator*(const SparseMatrix &A, const SparseVector &U);

double operator*(const SparseVector &U, const SparseVector &V);

SparseVector operator+(const SparseVector &U, const SparseVector &V);

SparseVector operator-(const SparseVector &U, const SparseVector &V);

SparseVector operator*(const SparseVector &U, double m);

SparseVector operator*(double m, const SparseVector &U);

SparseVector operator/(const SparseVector &U, double m);

//std::ostream &operator<<(std::ostream &stream, const SparseVector &SparseVector);

#endif //LINEARALGEBRA_MATRIX_H_H
