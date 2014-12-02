/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "ranlux32.h"

namespace rng
{
    RANLUX32::RANLUX32() :
        RandomNumberGenerator(),
        state(),
        index(0)
    {}

    void RANLUX32::seed(fuint seed_num) {
        state[0] = seed_num;

        /*
         * Initialize seed vector using MINSTD
         */
        static constexpr uint64_t g = 48271;
        static constexpr uint64_t n = (1UL << 31UL) - 1UL; // 2^32 - 1
        for(size_t i = 1; i < state.size(); ++i)
        {
            state[i] = static_cast<fuint>((static_cast<uint64_t>(state[i-1]) * g) % n);
        }
    }

    fuint RANLUX32::operator()() {
        fuint output = state[mod(index-s, r)] - state[index];
        state[index] = output;
        index = (index + 1) % r;
        return output;
    }
}
