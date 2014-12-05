/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef RNG_H
#define RNG_H

#include <cstdint> // for fixed width integer types.
/*
 * Convenience typedef for the integer type being used.
 */
typedef uint32_t fuint;

namespace rng
{
    class RandomNumberGenerator {
    public:
        RandomNumberGenerator(){};
        virtual ~RandomNumberGenerator(){};
        virtual void seed(fuint seed_num) = 0;
        virtual fuint operator()() = 0;

    protected:
        /*
         * A modulo function that works with negative numbers.
         * http://stackoverflow.com/a/12277233/1473320
         */
        fuint mod(fuint a, fuint b) {
            return ((a % b )+ b) % b;
        }
    };
}

#endif /* RNG_H */
