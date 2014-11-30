/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef RANDU_H
#define RANDU_H

#include "rng.h"

namespace rng
{
    class RandU : public RandomNumberGenerator {
    public:
        RandU();
        void seed(fuint seed_num);
        fuint operator()();
    private:
        static constexpr uint64_t multiplier = 65539;
        static constexpr uint64_t modulator = 1 << 31;

        fuint state;
    };
}

#endif /* RANDU_H */
