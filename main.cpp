//
// Created by lars on 14-8-17.
//

#include "SparseAlgebra.hpp"
#include <cmath>

int main() {

    SparseVector Vector1(50000);
    SparseMatrix Matrix1(500000, 50000);

    for (int i = 0; i < Matrix1._columns; i += 5) {
        Matrix1[i][i] = i * 4 + 20;
        Vector1[i] = i - 8.0;
    }

    std::clock_t start;
    start = std::clock();

    std::cout << ParallelMatrixVector(Matrix1, Vector1);

    std::cout << std::endl << "Time: " << (std::clock() - start) / (double) (CLOCKS_PER_SEC) << " s" << std::endl;

    return EXIT_SUCCESS;
}