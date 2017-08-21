#ifndef LINEARALGEBRA_SPARSEMATRIX_H
#define LINEARALGEBRA_SPARSEMATRIX_H

#include "globals.hpp"
#include "sparse_vector.hpp"

namespace algebra_lib {
    /*!
     * \brief Class for sparse matrices.
     */
    class SparseMatrix {
    public:
        // Type definitions
        typedef std::map<int, SparseVector> MatrixMap;

        // Fields
        MatrixMap _matrixMap;
        int _rows;
        int _columns;
        /// \todo Create non-zero column index in SparseMatrix to speed up the iterations here, possibly during reference access.

        // Constructors
        SparseMatrix(int rows, int columns);

        // Getters and setters using operators
        SparseVector &operator[](int i);

        const SparseVector &operator[](int i) const;

        SparseVector &operator()(int i);

        const SparseVector &operator()(int i) const;

        /*
         * Cannot get reference for columns, as that would require us to
         * create the entire getColumn, effectively creating every row and
         * defeating the whole purpose of sparse algebra. Workaround;
         * separate setters and getters for columns.
         */
        SparseVector GetSparseColumn(int column);

        const SparseVector GetSparseColumn(int column) const;

        SparseMatrix SetOwnSparseColumn(SparseVector Vector, int column);

        SparseMatrix SetSparseColumn(SparseVector Vector, int column);

        // Member functions
        int GetRows();

        int GetColumns();

        SparseMatrix Transpose();

        SparseMatrix TransposeSelf();

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const SparseMatrix &SparseMatrix);
    };

}
#endif //LINEARALGEBRA_SPARSEMATRIX_H
