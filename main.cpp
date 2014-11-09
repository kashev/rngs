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

    for(int i = 0; i < 10; ++i)
    {
        cout << randgen() << endl;
    }

    return 0;
}