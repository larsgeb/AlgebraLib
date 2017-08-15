//
// Created by Lars Gebraad on 14-8-17.
//

#include "SparseAlgebra.hpp"
#include <cmath>
#include <ctime>

int main() {

    std::clock_t start;
    start = std::clock();

    SparseMatrix Mat1(200000000, 2000);
    SparseMatrix Mat2(2000, 20);

    Mat1[0][0] = 1;
    Mat1[0][1] = 2;
    Mat1[1][0] = 3;
    Mat1[1][1] = 4;

    Mat2[0][0] = 2;
    Mat2[0][1] = 0;
    Mat2[1][0] = 1;
    Mat2[1][1] = 2;


    std::cout << std::endl << "Time: " << (std::clock() - start) / (double) (CLOCKS_PER_SEC) << " s" << std::endl;

    return EXIT_SUCCESS;
}