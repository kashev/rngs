/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "mt19937.h"

namespace  rng
{
    MT19937::MT19937() :
        RandomNumberGenerator(),
        state_array(),
        index()
    {}

    /*
     * http://en.wikipedia.org/wiki/Mersenne_twister#Pseudocode
     */

    void MT19937::seed(fuint seed_num) {
        state_array[0] = seed_num;

        for(size_t i = 1; i < state_size; ++i)
        {
            state_array[i] =
                static_cast<fuint>(1812433253 * (state_array[i-1] ^ ((static_cast<uint64_t>(state_array[i-1])) >> 30)) + i);
        }
    }

    fuint MT19937::operator()() {
        if (index == 0)
        {
            generate_numbers();
        }

        fuint y = state_array[index];

        y = y ^ (y >> 11);
        y = y ^ ((y << 7) & 2636928640);
        y = y ^ ((y << 15) & 4022730752);
        y = y ^ (y >> 18);

        index = (index + 1) % state_size;

        return y;
    }

    void MT19937::generate_numbers(){
        for (size_t i = 0; i < state_size; ++i)
        {
            fuint y = (state_array[i] & 0x80000000)
                      + (state_array[(i + 1) % state_size] & 0x7fffffff);
            state_array[i] = state_array[(i + 397) % state_size] ^ (y >> 1);

            if (y % 2 != 0)
            {
                state_array[i] = state_array[i] ^ 2567483615;
            }
        }
    }

}
