/*! \file FullAlgebra.hpp
 * \brief Functions for AlgebraLib acting on const full matrices and vectors.
 *
 * \author Lars Gebraad
 *
 * \date August 2017
 *
 * Assorted function which combine full algebra classes within the library
 * to execute typical linear algebra functions. Most of the inputs here are const, and
 * the functions won't alter the input.
 *
 */


#ifndef LINEARALGEBRA_FULLALGEBRA_HPP
#define LINEARALGEBRA_FULLALGEBRA_HPP

#include "globals.hpp"
#include "vector.hpp"
#include "matrix.hpp"

namespace algebra_lib {
    /**
     *  \brief Matrix matrix product.
     * @param A \f$ m \times n \f$ matrix
     * @param B \f$ n \times l \f$ matrix
     * @return \f$ m \times l \f$ matrix
     * @throw std::length_error A and B are not of compatible dimension.
     */
    matrix operator*(const matrix &A, const matrix &B);

    matrix operator*(const matrix &A, const double &b);

    matrix operator*(const double &b, const matrix &A);

    matrix operator+(const matrix &A, const matrix &B);

    matrix operator-(const matrix &A, const matrix &B);

    /**
     *  \brief Matrix vector product.
     * @param A \f$ m \times n \f$ matrix
     * @param U \f$ n \times 1 \f$ (column) vector
     * @return \f$ m \times 1 \f$ (column) vector
     * @throw std::length_error A and U are not of compatible dimension.
     * @throw std::invalid_argument U is not a column vector.
     */
    vector operator*(const matrix &A, const vector &U);

    /**
     *  \brief Vector matrix product.
     * @param U \f$ 1 \times n \f$ (row) vector
     * @param A \f$ n \times l \f$ matrix
     * @return \f$ 1 \times l \f$ (row) vector
     * @throw std::length_error U and A are not of compatible dimension.
     * @throw std::invalid_argument U is not a row vector.
     */
    vector operator*(const vector &U, const matrix &A);

    /**
     * \brief Vector dot product.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param V \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @return scalar
     * @throw std::length_error U and V are not of compatible dimension.
     */
    double operator*(const vector &U, const vector &V);

    /**
     * \brief Vector sum.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param V \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     * @throw std::length_error U and V are not of compatible dimension.
     */
    vector operator+(const vector &U, const vector &V);

    /**
     * \brief Vector difference.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param V \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     * @throw std::length_error U and V are not of compatible dimension.
     */
    vector operator-(const vector &U, const vector &V);

    /**
     * \brief Vector scalar product.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param m scalar
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     */
    vector operator*(const vector &U, double m);

    /**
     * \brief Vector scalar product.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param m scalar
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     *
     * reverse order of operator*(const SparseVector &U, double m). Functions are identical.
     *
     */
    vector operator*(double m, const vector &U);

    /**
     * \brief Vector scalar division.
     * @param U \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector
     * @param m scalar
     * @return \f$ 1 \times n \f$ or \f$ n \times 1 \f$ vector, same as U
     */
    vector operator/(const vector &U, double m);

    vector ElementWiseMultiplication(const vector &U, const vector &V);

    vector ElementWiseDivision(double d, const vector &V, bool preserveZero = true);

    matrix ElementWiseDivision(double d, const matrix &V, bool preserveZero = true);

    matrix VectorToDiagonal(vector &U, int offset = 0);

    matrix VectorToDiagonal(const vector &Vector, int offset = 0);

    matrix ReadMatrix(const char *filename);

    void WriteMatrix(matrix M, const char *filename);

    vector ReadVector(const char *filename);

    void WriteVector(vector U, const char *filename);
};

#endif //LINEARALGEBRA_FULLALGEBRA_HPP
