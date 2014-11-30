/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "randu.h"

namespace rng
{
    RandU::RandU() :
        RandomNumberGenerator(),
        state(0U)
    {}

    void RandU::seed(fuint seed_num) {
        state = seed_num;
    }

    fuint RandU::operator()() {
        fuint temp = static_cast<fuint>((static_cast<uint64_t>(state) * multiplier) % modulator);
        state = temp;
        return state;
    }
}
