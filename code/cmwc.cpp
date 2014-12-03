/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "cmwc.h"

/*
 * PHI is a hashing constant which makes seeding easier.
 * http://stackoverflow.com/a/4948967/1473320
 * phi = (1 + sqrt(5)) / 2
 * 2^32 / phi = 0x9e3779b9
 */
#define PHI 0x9e3779b9

namespace rng
{
    CMWC::CMWC() :
        RandomNumberGenerator(),
        state(),
        c(362436)
    {}

    void CMWC::seed(fuint seed_num) {
        state[0] = seed_num;
        state[1] = seed_num + PHI;
        state[2] = seed_num + PHI;

        for (fuint i = 3; i < static_cast<fuint>(r); ++i)
        {
            state[i] = state[i - 3] ^ state[i - 2] ^ PHI ^ i;
        }
    }

    fuint CMWC::operator()() {
        static fuint i = 4095;
        uint64_t t;

        i = (i + 1) & 4095;
        t = (a * state[i]) + c;
        c = t >> 32;
        state[i] = 0xfffffffe - t;

        return state[i];
    }
}
