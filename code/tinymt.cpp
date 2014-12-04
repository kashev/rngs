/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "tinymt.h"

namespace rng
{
    TinyMT::TinyMT() :
        RandomNumberGenerator(),
        state(),
        mat1(0x8f7011ee),
        mat2(0xfc78ff1f),
        tmat(0x3793fdff)
    {}

    void TinyMT::seed(fuint seed_num) {
        state[0] = seed_num;
        state[1] = mat1;
        state[2] = mat2;
        state[3] = tmat;
        for(uint i = 1; i < 8; ++i) {
            state[i&3] ^= i + 1812433253 * (state[(i-1)&3] ^ state[(i-1)&3] >> 30);
        }
        for(uint i = 0; i < 8; ++i) {
            next_state();
        }
    }

    fuint TinyMT::operator()() {
        next_state();
        fuint t0, t1;
        t0 = state[3];
        t1 = state[0] + (state[2] >> sh8);
        t0 ^= t1;
        t0 ^= -(static_cast<int32_t>(t1 & 1)) & tmat;
        return t0;
    }
}
