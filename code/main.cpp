/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include <iostream>

#include "stl_rng.h"
#include "mt19937.h"

using namespace std;
using namespace rng;

int main(int argc, char *argv[]) {

    if (argc != 2)
    {
        return 1;
    }

    RandomNumberGenerator* randgen_ptr = NULL;

    switch(stoi(argv[1]))
    {
        case 0: { // STL RNG using std::mt19937. For testing only.
            StlRng randgen = StlRng();
            randgen_ptr = &randgen;
            break;
        }
        case 1: {
            MT19937 randgen = MT19937();
            randgen_ptr = &randgen;
            break;
        }
        /*
         * Add more RNGs here!
         */
        default: {
            StlRng randgen = StlRng();
            randgen_ptr = &randgen;
            break;
        }
    }

    randgen_ptr->seed(42);

    uint32_t x = 0;
    while(true)
    {
        x = static_cast<uint32_t>((*randgen_ptr)());
        std::cout.write(reinterpret_cast<const char*>(&x), sizeof x);
    }

    return 0;
}
