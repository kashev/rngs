/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef TINYMT_H
#define TINYMT_H

#include "rng.h"

#include <array>

namespace rng
{
    class TinyMT : public RandomNumberGenerator {
    public:
        TinyMT();
        void seed(fuint seed_num);
        fuint operator()();

    private:
        static constexpr size_t mexp = 127;
        static constexpr size_t sh0 = 1;
        static constexpr size_t sh1 = 10;
        static constexpr size_t sh8 = 8;
        static constexpr fuint mask = 0x7fffffff;

        void next_state() {
            fuint x, y;
            y = state[3];
            x = (state[0] & mask) ^ state[1] ^ state[2];
            x ^= (x << sh0);
            y ^= (y >> sh0) ^ x;
            state[0] = state[1];
            state[1] = state[2];
            state[2] = x ^ (y << sh1);
            state[3] = y;
            state[1] ^= -(static_cast<int32_t>(y & 1)) & mat1;
            state[2] ^= -(static_cast<int32_t>(y & 1)) & mat2;
        }

        std::array<fuint, 4> state;
        fuint mat1;
        fuint mat2;
        fuint tmat;
    };
}

#endif /* TINYMT_H */
