/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "randu.h"

namespace rng
{
    RANDU::RANDU() :
        RandomNumberGenerator(),
        state(0U)
    {}

    void RANDU::seed(fuint seed_num) {
        state = seed_num;
    }

    fuint RANDU::operator()() {
        state = static_cast<fuint>((static_cast<uint64_t>(state) * g) % n);
        return state;
    }
}
