/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef XORSHIFT_H
#define XORSHIFT_H

#include "rng.h"

namespace rng
{
    class Xorshift : public RandomNumberGenerator {
    public:
        Xorshift();
        void seed(fuint seed_num);
        fuint operator()();
    private:
        fuint x, y, z, w;
    };
}

#endif /* XORSHIFT_H */
