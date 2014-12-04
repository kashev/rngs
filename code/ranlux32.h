/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef RANLUX32_H
#define RANLUX32_H

#include "rng.h"

#include <array>

namespace rng
{
    class RANLUX32 : public RandomNumberGenerator {
    public:
        RANLUX32();
        void seed(fuint seed_num);
        fuint operator()();
    private:
        /*
         * A modulo function that works with negative numbers.
         * http://stackoverflow.com/a/12277233/1473320
         */
        fuint mod(fuint a, fuint b){
            return ((a % b )+ b) % b;
        }

        uint64_t next_state() {
            if(state[mod(index-s, r)] < state[index])
                prev = 1;
            else
                prev = 0;
            uint64_t output = state[mod(index-s, r)] - state[index] - prev;
            state[index] = output;
            index = (index + 1) % r;
            return output;
        }

        static constexpr fuint r = 12;
        static constexpr fuint s = 5;
        static constexpr fuint discard = 11;
        static constexpr fuint block_size = 389;
        size_t prev;
        fuint count;
        std::array<uint64_t, r> state;
        size_t index;
    };
}

#endif /* RANLUX32_H */
