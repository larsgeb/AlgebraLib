//
// Created by Lars Gebraad on 14-8-17.
//

#include <ctime>
#include "src/AlgebraLib/AlgebraLib.hpp"


int main() {

    std::clock_t start;

    AlgebraLib::Vector A(4, true);
    AlgebraLib::Matrix B(4, 9);

    std::cout << A;
    std::cout << B;

    std::cout << std::endl << "Time: " << (std::clock() - start) / (double) (CLOCKS_PER_SEC) << " s" << std::endl;


    return EXIT_SUCCESS;
}