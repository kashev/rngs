/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "stl_rng.h"

namespace rng
{
    StlRng::StlRng() :
        RandomNumberGenerator()
    {}

    void StlRng::seed(fuint seed_num) {
        gen = std::mt19937(seed_num);
    }

    fuint StlRng::operator()() {
        return gen();
    }

}
