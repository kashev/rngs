/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef CMWC_H
#define CMWC_H

#include "rng.h"

#include <array>

namespace rng
{
    class CMWC : public RandomNumberGenerator {
    public:
        CMWC();
        void seed(fuint seed_num);
        fuint operator()();

    private:
        static constexpr fuint a = 18705ULL;
        static constexpr size_t r = 4096;

        std::array<fuint, r> state;
        fuint c;
    };
}

#endif /* CMWC_H */
