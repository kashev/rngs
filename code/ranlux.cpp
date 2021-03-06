/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "ranlux.h"

namespace rng
{
    RANLUX::RANLUX() :
        RandomNumberGenerator(),
        prev(0),
        count(0),
        state(),
        index(0)
    {}

    void RANLUX::seed(fuint seed_num) {
        state[0] = seed_num;

        /*
         * Initialize seed vector using MINSTD
         */
        static constexpr uint64_t g = 48271;
        static constexpr uint64_t n = (1UL << 32UL) - 1UL; // 2^32 -1
        fuint first, second = seed_num;

        for(size_t i = 1; i < state.size(); ++i)
        {
            first = static_cast<fuint>((static_cast<uint64_t>(second) * g) % n);
            second = static_cast<fuint>((static_cast<uint64_t>(first) * g) % n);
            state[i] = ((static_cast<uint64_t>(first)) << 32) | static_cast<uint64_t>(second);
        }
    }

    fuint RANLUX::operator()() {
        if(count == discard)
        {
            count = 0;
            for(fuint i = 0; i < block_size-discard; ++i)
            {
                next_state();
            }
        }
        uint64_t output = next_state();
        count++;
        return static_cast<fuint>(output);
    }
}
