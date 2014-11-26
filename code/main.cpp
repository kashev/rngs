/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include <iostream>

#include "stl_rng.h"

using namespace std;
using namespace rng;

int main() {

    StlRng randgen;
    randgen.seed(42);

    fuint x = 0;
    while(true)
    {
        x = randgen();
        std::cout.write(reinterpret_cast<const char*>(&x), sizeof x);
    }

    return 0;
}