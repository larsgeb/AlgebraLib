//
// Created by Lars Gebraad on 14-8-17.
//

#include <thread>
#include <cmath>
#include "sparse_algebra.hpp"
#include "sparse_parallel_algebra.hpp"

namespace algebra_lib {
    sparse_matrix ParallelMatrixProduct(const sparse_matrix &A, const sparse_matrix &B) {
        if (A.columns() != B.rows()) {
            throw std::length_error("Matrices are not compatible in dimension");
        }
        sparse_matrix P(A.rows(), B.columns());
        sparse_matrix *Ppoint = &P;


        unsigned concThreads = std::thread::hardware_concurrency();
        if (concThreads <= 1) concThreads = 2;

        std::vector<unsigned> rowsPerCore(concThreads, (unsigned) floor(A.rows() / concThreads));
        std::vector<unsigned> startingRow(concThreads, 0);
        std::vector<unsigned> endingRow(concThreads, 0);

        if (A.rows() % concThreads > 0)
            rowsPerCore[0]++;

        endingRow[0] = rowsPerCore[0] - 1;

        for (auto it = rowsPerCore.begin() + 1; it != rowsPerCore.end(); it++) {
            if (A.rows() % concThreads > (it - rowsPerCore.begin()))
                rowsPerCore[it - rowsPerCore.begin()]++;

            startingRow[it - rowsPerCore.begin()] = endingRow[it - rowsPerCore.begin() - 1] + 1;
            endingRow[it - rowsPerCore.begin()] = startingRow[it - rowsPerCore.begin()] + *(it) - 1;
        }

        std::vector<std::thread> workers;

        for (int i = 0; i < startingRow.size(); i++) {
            workers.emplace_back(
                    std::thread([&]() mutable {
                        for (int jRow = startingRow[i]; jRow < endingRow[i]; ++jRow) {
//                            Ppoint->operator[](jRow).operator[](1) = 1;
                        }
                    }));
        }

        // Wrap up
        std::cout << "Main thread!" << std::endl;
        for (std::thread &e : workers) {
            e.join();
        }

        return P;
    }
}