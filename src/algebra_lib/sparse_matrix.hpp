#ifndef LINEARALGEBRA_sparse_matrix_H
#define LINEARALGEBRA_sparse_matrix_H

#include "globals.hpp"
#include "sparse_vector.hpp"

namespace algebra_lib {
    /*!
     * \brief Class for sparse matrices.
     */
    class sparse_matrix {
    public:
        // Type definitions
        typedef std::map<int, sparse_vector> MatrixMap;

        // Fields
        MatrixMap _matrixMap;
        int _rows;
        int _columns;
        /// \todo Create non-zero column index in sparse_matrix to speed up the iterations here, possibly during reference access.

        // Constructors
        sparse_matrix(int rows, int columns);

        // Getters and setters using operators
        sparse_vector operator[](int i);

        const sparse_vector &operator[](int i) const;

        sparse_vector &operator()(int i);

        const sparse_vector &operator()(int i) const;

        /*
         * Cannot get reference for columns, as that would require us to
         * create the entire getColumn, effectively creating every row and
         * defeating the whole purpose of sparse algebra. Workaround;
         * separate setters and getters for columns.
         */
        sparse_vector GetSparseColumn(int column);

        const sparse_vector GetSparseColumn(int column) const;

        sparse_matrix SetSparseColumnSelf(sparse_vector Vector, int column);

        sparse_matrix SetSparseColumn(sparse_vector Vector, int column);

        // Member functions
        int GetRows();

        int GetColumns();

        sparse_matrix Transpose();

        sparse_matrix TransposeSelf();

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const sparse_matrix &sparse_matrix);
    };

}
#endif //LINEARALGEBRA_sparse_matrix_H
