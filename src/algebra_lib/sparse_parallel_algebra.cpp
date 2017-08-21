//
// Created by Lars Gebraad on 14-8-17.
//

#include "sparse_parallel_algebra.hpp"

sparse_vector ParallelMatrixVector(const sparse_matrix &A, const sparse_vector &U) {
    if (A._columns != U._numElements) {
        throw std::length_error("vector and matrix are not compatible in dimension");
    }
    sparse_vector P(A._rows);

    std::vector<std::thread> workers;
    int j = 0;

    /// \todo Linux (and possibly other platforms) can't handle unlimited number of threads. Divide and conquer.
    for (auto const &rowM : A._matrixMap) {
        workers.emplace_back(std::thread([](int i, const sparse_vector &row, const sparse_vector &rhs, double &pElement) {
            pElement = row * rhs;
        }, j++, std::ref(rowM.second), std::ref(U), std::ref(P[rowM.first])));
    }
    std::cout << "Main thread!" << std::endl;
    for (std::thread &e : workers) {
        e.join();
    }

    return P;
}