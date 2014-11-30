/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "r250.h"

namespace rng
{
    R250::R250() :
        RandomNumberGenerator(),
        state(),
        index(0)
    {}

    void R250::seed(fuint seed_num) {
        state[0] = seed_num;

        /*
         * Initialize RNG State
         */
        for(size_t i = 1; i < state.size(); ++i)
        {
            state[i] = ((69069 * state[i - 1]) & 0xffffffff);
        }

        /*
         * Ensure linear independence.
         */
        uint32_t msb = 0x80000000;
        uint32_t mask = 0xffffffff;
        for(uint i = 0; i < 32; ++i)
        {
            uint k = 7 * i + 3;
            state[k] &= mask;
            state[k] |= msb;

            mask >>= 1;
            msb >>= 1;
        }
    }

    fuint R250::operator()() {
        fuint output = state[index] ^ state[mod(index - 147, state_size)];
        state[index] = output;
        index = (index + 1) % state_size;
        return output;
    }
}
