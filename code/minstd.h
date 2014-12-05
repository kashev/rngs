/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef MINSTD_H
#define MINSTD_H

#include "rng.h"

namespace rng
{
    class MINSTD : public RandomNumberGenerator {
    public:
        MINSTD();
        void seed(fuint seed_num);
        fuint operator()();

    private:
        static constexpr uint64_t g = 48271;
        static constexpr uint64_t n = (1UL << 32UL) - 1UL; // 2^32 - 1

        fuint state;
    };
}

#endif /* MINSTD_H */
