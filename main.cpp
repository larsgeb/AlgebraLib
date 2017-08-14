//
// Created by Lars Gebraad on 14-8-17.
//

#include "SparseAlgebra.hpp"
#include <cmath>
#include <ctime>

int main() {

    SparseVector Vector1(500);
    SparseMatrix Matrix1(500, 500);

    for (int i = 0; i < Matrix1._columns; i += 5) {
        Matrix1[i][0] = 1;
        Vector1[i] = i+2;
    }

    std::clock_t start;
    start = std::clock();

    std::cout << Matrix1 * Vector1;

    std::cout << std::endl << "Time: " << (std::clock() - start) / (double) (CLOCKS_PER_SEC) << " s" << std::endl;

    return EXIT_SUCCESS;
}