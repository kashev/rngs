/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include "rng.h"

namespace rng
{
    RandomNumberGenerator::RandomNumberGenerator() {
        dist = std::uniform_real_distribution<double>(0, 1);
    }
}