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
    class RANDU : public RandomNumberGenerator {
    public:
        RANDU();
        void seed(fuint seed_num);
        fuint operator()();

    private:
        static constexpr uint64_t g = 65539;
        static constexpr uint64_t n = (1UL << 31UL); // 2^31

        fuint state;
    };
}

#endif /* RANDU_H */
