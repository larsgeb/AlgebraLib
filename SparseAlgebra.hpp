//
// Created by lars on 14-8-17.
//

#ifndef LINEARALGEBRA_MATRIX_H_H
#define LINEARALGEBRA_MATRIX_H_H


#include <utility>
#include <map>
#include <iostream>
#include <future>

//class SparseRow;
//
//class SparseColumn;

class SparseMatrix;

class SparseVector {
private:
protected:
public:
    std::map<int, double> _entries;
    int _numElements;

    SparseVector();

    explicit SparseVector(int columns);

    // Getters and setters using operators
    double &operator[](int i);

    double &operator()(int i);

    // Output operator overload
    friend std::ostream &operator<<(std::ostream &stream, const SparseVector &SparseVector);
};

class SparseMatrix {
public:
    // Typedefs
//    typedef std::map<int, double> SparseRow;
    typedef std::map<int, SparseVector> MatrixMap;

    // Fields
    MatrixMap _M;
    int _rows;
    int _columns;

    // Constructors and destructors
    SparseMatrix(int rows, int columns);

    SparseVector &operator[](int i);

    SparseVector &operator()(int i);


    // Get details of matrix
    int GetRows();

    int GetColumns();

};

SparseMatrix MatrixMultiplication(const SparseMatrix &A, const SparseMatrix &B);

SparseVector operator*(const SparseMatrix &A, const SparseVector &U);

SparseVector ParallelMatrixVector(const SparseMatrix &A, const SparseVector &U);

double DotProduct(const SparseVector &U, const SparseVector &V);
double operator*(const SparseVector &U, const SparseVector &V);

SparseVector operator+(const SparseVector &U, const SparseVector &V);

SparseVector operator-(const SparseVector &U, const SparseVector &V);

SparseVector operator*(const SparseVector &U, const double m);

SparseVector operator*(const double m, const SparseVector &U);

SparseVector operator/(const SparseVector &U, const double m);

std::ostream &operator<<(std::ostream &stream, const SparseVector &SparseVector);

#endif //LINEARALGEBRA_MATRIX_H_H
