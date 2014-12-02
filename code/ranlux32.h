/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef RANLUX32_H
#define RANLUX32_H

#include "rng.h"

#include <array>

namespace rng
{
    class RANLUX32 : public RandomNumberGenerator {
    public:
        RANLUX32();
        void seed(fuint seed_num);
        fuint operator()();
    private:
        /*
         * A modulo function that works with negative numbers.
         * http://stackoverflow.com/a/12277233/1473320
         */
        fuint mod(fuint a, fuint b){
            return ((a % b )+ b) % b;
        }

        static constexpr fuint r = 37;
        static constexpr fuint s = 24;
        std::array<fuint, r> state;
        size_t index;
    };
}

#endif /* RANLUX32_H */
