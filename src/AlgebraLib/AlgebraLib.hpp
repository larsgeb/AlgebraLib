//
// Created by Lars Gebraad on 16-8-17.
//

/*! \mainpage Sparse Linear Algebra Documentation
 *
 * This rather simple library was built to speed up some calculations in Hamiltonian
 * Markov Chain sampling of functions. By building it in a separate library, I can
 * re-use this rather fast code in many projects. Nice, because C++ doesn't have any
 * good (standard) libraries. And it's fun to write!
 *
 * Right now, I've implemented some rather basic methods. C++ is new to me, and I
 * still often run into unexpected behaviour. Nevertheless, the speed improvement
 * is already quite large over my previous lubrary, based on the STL vectors.
 *
 * Most of the speed gain here is made by not storing zero values of matrices, but
 * instead relying on a nested map to store non-zero entries. In many of the associated
 * functions, this sparsity is exploited by only looping over non-zero functions. However, column access is still rather slow for complex matrices; as this index is
 * contained in the nested map. Therefore, to retrieve one column (with possibly only
 * one entry) one has to loop over all non-zero rows. A possibility would be to use a
 * single map with a pair as index. But then retrieval is more complicated, by matching
 * only one of the pairs.
 *
 * In the future, I will merge this library with another non-sparse library. This will
 * hopefully result in performance gains were required, but still the full functionality
 * of a complete set of linear algebra tools.
 *
 * I suggest to start browsing at SparseAlgebra.hpp, as it contains many common linear
 * algebra routines. The parallel files are more of a development challenge right now
 * than an actual working (and reliable) implementation.
 *
 * \author Lars Gebraad
 * \date August 2017
 */


#ifndef LINEARALGEBRA_ALGEBRALIB_HPP
#define LINEARALGEBRA_ALGEBRALIB_HPP

#include "SparseAlgebra.hpp"
#include "FullAlgebra.hpp"


#endif //LINEARALGEBRA_ALGEBRALIB_HPP
