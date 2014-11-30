/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "xorshift.h"

namespace rng
{
    Xorshift::Xorshift() :
            RandomNumberGenerator(),
            x(0),
            y(0),
            z(0),
            w(0)
    {}

    void Xorshift::seed(fuint seed_num) {
        static constexpr uint64_t g = 48271;
        static constexpr uint64_t n = (1UL << 31UL) - 1UL; // 2^32 - 1
        x = seed_num;
        /*
         * Use MINSTD to finish populating state.
         */
        y = static_cast<fuint>((static_cast<uint64_t>(x) * g) % n);
        z = static_cast<fuint>((static_cast<uint64_t>(y) * g) % n);
        w = static_cast<fuint>((static_cast<uint64_t>(z) * g) % n);
    }

    fuint Xorshift::operator()() {
        fuint t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        w = w ^ (w >> 19) ^ t ^ (t >> 8);
        return w;
    }
}
