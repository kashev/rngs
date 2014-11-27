/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef RNG_H
#define RNG_H

#include <cstdint> // for uint_fast32_t

/*
 * Convenience typedef for Fast 32 Unsigned Integer Type. Fast Uints are used internally, even though they must be
 * converted to a type that ensures exactly 32 bits to be passed to dieharder. On 32 bit systems, this conversion
 * won't be anything, but on 64 bit systems, fast 32 bit integers are usually 64 bits.
 */
typedef uint_fast32_t fuint;

namespace rng
{
    class RandomNumberGenerator {
    public:
        RandomNumberGenerator(){};
        virtual void seed(fuint seed_num) = 0;
        virtual fuint operator()() = 0;
    };
}

#endif /* RNG_H */