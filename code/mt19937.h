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

        static constexpr size_t state_size = 624;
        std::array<fuint, state_size> state_array;
        size_t index;
    };
}

#endif /* MT19937_H */
