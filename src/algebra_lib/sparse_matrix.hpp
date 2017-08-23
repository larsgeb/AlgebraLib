#ifndef LINEARALGEBRA_sparse_matrix_H
#define LINEARALGEBRA_sparse_matrix_H

#include "globals.hpp"
#include "sparse_vector.hpp"

namespace algebra_lib {
    /*!
     * \brief Class for sparse matrices.
     */
    // Type definitions
    typedef std::map<int, sparse_vector> sparseContentMatrixDouble;
    class sparse_matrix {
    public:
        // todo Create non-zero column index in sparse_matrix to speed up the iterations here, possibly during reference access.

        // Constructors
        sparse_matrix(int rows, int columns);

        // Getters and setters using operators
        sparse_vector operator[](int i);

        const sparse_vector operator[](int i) const;

        sparse_vector &operator()(int i);

        const sparse_vector operator()(int i) const;

        sparse_vector GetSparseColumn(int column);

        const sparse_vector GetSparseColumn(int column) const;

        sparse_matrix SetSparseColumnSelf(sparse_vector Vector, int column);

        sparse_matrix SetSparseColumn(sparse_vector Vector, int column);

        sparseContentMatrixDouble::const_iterator begin() const;

        sparseContentMatrixDouble::const_iterator end() const;

        sparseContentMatrixDouble::reverse_iterator rbegin();

        sparseContentMatrixDouble::reverse_iterator rend();

        sparseContentMatrixDouble::const_iterator cbegin() const noexcept;

        sparseContentMatrixDouble::const_iterator cend() const noexcept;

        sparseContentMatrixDouble::const_reverse_iterator crbegin() const noexcept;

        sparseContentMatrixDouble::const_reverse_iterator crend() const noexcept;

        // Member functions
        int rows() const;

        int columns() const;

        sparse_matrix Transpose();

        const sparse_matrix Transpose() const;

        sparse_matrix TransposeSelf();

        // Member functions
        sparse_matrix InvertLowerTriangular();
        sparse_matrix InvertLowerTriangular() const;
        sparse_matrix InvertMatrixElements(bool preserveZero = false);
        sparse_matrix InvertMatrixElements(bool preserveZero = false) const;
        sparse_matrix & InvertMatrixElementsSelf(bool preserveZero = false);
        sparse_vector Trace(int offset = 0);
        sparse_vector Trace(int offset = 0) const;
        sparse_matrix CholeskyDecompose();
        sparse_matrix CholeskyDecompose() const;
        sparse_vector SolveLowerTriangular(sparse_vector &Y);
        sparse_vector SolveLowerTriangular(sparse_vector &Y) const;
        sparse_matrix & Unit();

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const sparse_matrix &sparse_matrix);

    private:
        sparseContentMatrixDouble _matrixMap;
        int _rows;
        int _columns;


    };

}
#endif //LINEARALGEBRA_sparse_matrix_H
