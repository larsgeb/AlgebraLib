//
// Created by Lars Gebraad on 14-8-17.
//

#ifndef LINEARALGEBRA_SPARSEMATRIX_H
#define LINEARALGEBRA_SPARSEMATRIX_H

#include "SparseVector.hpp"

class SparseMatrix {
public:
    // Typedefs
//    typedef std::map<int, double> SparseRow;
    typedef std::map<int, SparseVector> MatrixMapOld;
    typedef std::pair<int, int> MatrixIndex;
    typedef std::map<MatrixIndex, double> MatrixMap;

    // Fields
    MatrixMapOld _M;
    int _rows;
    int _columns;

    // Constructors and destructors
    SparseMatrix(int rows, int columns);

    SparseVector &operator[](int i);

    SparseVector &operator()(int i);


    // Get details of matrix
    int GetRows();

    int GetColumns();

    SparseVector GetSparseColumn(int column);

};


#endif //LINEARALGEBRA_SPARSEMATRIX_H
