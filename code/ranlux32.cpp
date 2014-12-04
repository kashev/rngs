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
        prev(0),
        count(0),
        state(),
        index(0)
    {}

    void RANLUX32::seed(fuint seed_num) {
        state[0] = seed_num;

        /*
         * Initialize seed vector using MINSTD
         */
        static constexpr uint64_t g = 48271;
        static constexpr uint64_t n = (1UL << 48UL); // 2^49
        for(size_t i = 1; i < state.size(); ++i)
        {
            state[i] = static_cast<fuint>((static_cast<uint64_t>(state[i-1]) * g) % n);
        }
    }

    fuint RANLUX32::operator()() {
        if(count == discard) {
            count = 0;
            for(uint i = 0; i < block_size-discard; ++i) {
                next_state();
            }
        }
        uint64_t output = next_state();
        count++;
        return static_cast<fuint>(output);
    }
}
