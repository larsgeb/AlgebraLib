//
// Created by Lars Gebraad on 16-8-17.
//

#ifndef LINEARALGEBRA_FULLALGEBRA_HPP
#define LINEARALGEBRA_FULLALGEBRA_HPP

#include "Matrix.hpp"

namespace AlgebraLib {
    /**
     *  \brief Matrix matrix product.
     * @param A \f$ m \times n \f$ matrix
     * @param B \f$ n \times l \f$ matrix
     * @return \f$ m \times l \f$ matrix
     * @throw std::length_error A and B are not of compatible dimension.
     */
    Matrix operator*(const Matrix &A, const Matrix &B);

    /**
     *  \brief Matrix vector product.
     * @param A \f$ m \times n \f$ matrix
     * @param U \f$ n \times 1 \f$ (column) vector
     * @return \f$ m \times 1 \f$ (column) vector
     * @throw std::length_error A and U are not of compatible dimension.
     * @throw std::invalid_argument U is not a column vector.
     */
    Vector operator*(const Matrix &A, const Vector &U);

    /**
     *  \brief Vector matrix product.
     * @param U \f$ 1 \times n \f$ (row) vector
     * @param A \f$ n \times l \f$ matrix
     * @return \f$ 1 \times l \f$ (row) vector
     * @throw std::length_error U and A are not of compatible dimension.
     * @throw std::invalid_argument U is not a row vector.
     */
    Vector operator*(const Vector &U, const Matrix &A);

    /**
     * \brief Vector dot product.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param V \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @return scalar
     * @throw std::length_error U and V are not of compatible dimension.
     */
    double operator*(const Vector &U, const Vector &V);

    /**
     * \brief Vector sum.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param V \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     * @throw std::length_error U and V are not of compatible dimension.
     */
    Vector operator+(const Vector &U, const Vector &V);

    /**
     * \brief Vector difference.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param V \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     * @throw std::length_error U and V are not of compatible dimension.
     */
    Vector operator-(const Vector &U, const Vector &V);

    /**
     * \brief Vector scalar product.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param m scalar
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     */
    Vector operator*(const Vector &U, double m);

    /**
     * \brief Vector scalar product.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param m scalar
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     *
     * reverse order of operator*(const SparseVector &U, double m). Functions are identical.
     *
     */
    Vector operator*(double m, const Vector &U);

    /**
     * \brief Vector scalar division.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param m scalar
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     */
    Vector operator/(const Vector &U, double m);
};


#endif //LINEARALGEBRA_FULLALGEBRA_HPP
