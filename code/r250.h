/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef R250_H
#define R250_H

#include "rng.h"

#include <array>

namespace rng
{
    class R250 : public RandomNumberGenerator {
    public:
        R250();
        void seed(fuint seed_num);
        fuint operator()();
    private:
        static constexpr fuint state_size = 250;

        std::array<fuint, state_size> state;
        size_t index;
    };
}

#endif /* R250_H */
