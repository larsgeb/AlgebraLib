/*! \file SparseAlgebra.hpp
 * \brief Functions for SparseLinearAlgebra acting on const matrices and vectors.
 *
 * \author Lars Gebraad
 *
 * \date August 2017
 *
 * <P>Assorted function which combine different classes of the SparseLinearAlgebra library
 * to execute typical linear algebra functions. Most of the inputs here are const, and
 * the functions won't alter the input.</P><P>Including just this file in your main file
 * will take care of the rest.</P>
 *
 */

#ifndef LINEARALGEBRA_MATRIX_H_H
#define LINEARALGEBRA_MATRIX_H_H

#include "SparseMatrix.hpp"


namespace AlgebraLib {
    /**
     *  \brief Matrix matrix product.
     * @param A \f$ m \times n \f$ matrix
     * @param B \f$ n \times l \f$ matrix
     * @return \f$ m \times l \f$ matrix
     * @throw std::length_error A and B are not of compatible dimension.
     */
    SparseMatrix operator*(const SparseMatrix &A, const SparseMatrix &B);

    /**
     *  \brief Matrix vector product.
     * @param A \f$ m \times n \f$ matrix
     * @param U \f$ n \times 1 \f$ (column) vector
     * @return \f$ m \times 1 \f$ (column) vector
     * @throw std::length_error A and U are not of compatible dimension.
     * @throw std::invalid_argument U is not a column vector.
     */
    SparseVector operator*(const SparseMatrix &A, const SparseVector &U);

    /**
     *  \brief Vector matrix product.
     * @param U \f$ 1 \times n \f$ (row) vector
     * @param A \f$ n \times l \f$ matrix
     * @return \f$ 1 \times l \f$ (row) vector
     * @throw std::length_error U and A are not of compatible dimension.
     * @throw std::invalid_argument U is not a row vector.
     */
    SparseVector operator*(const SparseVector &U, const SparseMatrix &A);

    /**
     * \brief Vector dot product.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param V \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @return scalar
     * @throw std::length_error U and V are not of compatible dimension.
     */
    double operator*(const SparseVector &U, const SparseVector &V);

    /**
     * \brief Vector sum.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param V \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     * @throw std::length_error U and V are not of compatible dimension.
     */
    SparseVector operator+(const SparseVector &U, const SparseVector &V);

    /**
     * \brief Vector difference.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param V \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     * @throw std::length_error U and V are not of compatible dimension.
     */
    SparseVector operator-(const SparseVector &U, const SparseVector &V);

    /**
     * \brief Vector scalar product.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param m scalar
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     */
    SparseVector operator*(const SparseVector &U, double m);

    /**
     * \brief Vector scalar product.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param m scalar
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     *
     * reverse order of operator*(const SparseVector &U, double m). Functions are identical.
     *
     */
    SparseVector operator*(double m, const SparseVector &U);

    /**
     * \brief Vector scalar division.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param m scalar
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     */
    SparseVector operator/(const SparseVector &U, double m);
}
#endif //LINEARALGEBRA_MATRIX_H_H
