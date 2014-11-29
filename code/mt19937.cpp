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

        for(size_t i = 1; i < n; ++i)
        {
            state_array[i] = static_cast<fuint>(
                f * (state_array[i - 1] ^ ((static_cast<uint64_t>(
                state_array[i - 1])) >> 30)) + i);
        }
    }

    fuint MT19937::operator()() {
        if (index == 0)
        {
            generate_numbers();
        }

        fuint y = state_array[index];

        y = y ^ (y >> u);
        y = y ^ ((y << s) & b);
        y = y ^ ((y << t) & c);
        y = y ^ (y >> l);

        index = (index + 1) % n;

        return y;
    }

    void MT19937::generate_numbers(){
        for (size_t i = 0; i < n; ++i)
        {
            fuint y = (state_array[i] & rmask)
                      + (state_array[(i + 1) % n] & rprime);
            state_array[i] = state_array[(i + m) % n] ^ (y >> 1);

            if (y % 2 != 0)
            {
                state_array[i] = state_array[i] ^ a;
            }
        }
    }

}
