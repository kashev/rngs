/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "minstd.h"

namespace rng
{
    MINSTD::MINSTD() :
            RandomNumberGenerator(),
            state(0U)
    {}

    void MINSTD::seed(fuint seed_num) {
        state = seed_num;
    }

    fuint MINSTD::operator()() {
        state = static_cast<fuint>((static_cast<uint64_t>(state) * g) % n);
        return state;
    }
}
