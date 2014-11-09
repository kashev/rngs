/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#ifndef RNG_H
#define RNG_H

#include <random>

namespace rng
{
    class RandomNumberGenerator {
    public:
        RandomNumberGenerator();
        virtual void seed(int seed_num) = 0;
        virtual double operator()() = 0;
    protected:
        std::uniform_real_distribution<double> dist;
    };
}

#endif /* RNG_H */