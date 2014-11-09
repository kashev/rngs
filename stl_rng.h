/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef STL_RNG
#define STL_RNG

#include "rng.h"

namespace rng
{
    class StlRng : public RandomNumberGenerator {
    public:
        StlRng();
        void seed(int seed_num);
        double operator()();
    private:
        std::mt19937 gen;
    };
}

#endif /* STL_RNG */