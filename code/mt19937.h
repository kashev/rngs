/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef MT19937_H
#define MT19937_H

#include "rng.h"

#include <array>

namespace rng
{
    class MT19937 : public RandomNumberGenerator {
    public:
        MT19937();
        void seed(fuint seed_num);
        fuint operator()();
    private:
        void generate_numbers();

        /*
         * Algorithmic Constants
         */
        static constexpr size_t w = 32;
        static constexpr size_t n = 624;
        static constexpr size_t m = 397;
        static constexpr size_t r = 31;
        static constexpr fuint rmask = 0x80000000; // bit 31
        static constexpr fuint rprime = 0x7fffffff; // bits 0-30
        static constexpr fuint a = 0x9908b0df;
        static constexpr size_t u = 11;
        static constexpr fuint d = 0xffffffff;
        static constexpr size_t s = 7;
        static constexpr fuint b = 0x9d2c5680;
        static constexpr size_t t = 15;
        static constexpr fuint c = 0xefc60000;
        static constexpr size_t l = 18;
        static constexpr fuint f = 1812433253;

        std::array<fuint, n> state_array;
        size_t index;
    };
}

#endif /* MT19937_H */
