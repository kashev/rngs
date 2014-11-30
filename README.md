rngs
====

    /*
     * rngs
     * ECE 541 Project 2
     * Kashev Dalmia - dalmia3
     * David Huang   - huang157
     */

A project for ECE 541 Project #2 @ UIUC. Investigating Random Number Generators.

This project uses the [Dieharder](https://www.phy.duke.edu/~rgb/General/dieharder.php) project to test random number generators implemented in C++. More information can be found in the `proposal`, `report`, and `presentation` folders.

This project requires `dieharder`. Obtain it from the link above, install it with your package manager, or on ubuntu, run `code/install_deps.sh`.

Example Usage:

    ./rngs.py stl -d 0
    ./rngs.py stl -a

Note that the only flag that's passed to `dieharder` by default is `-g 200`, to tell it to use `std_in_raw`. All other `dieharder` options, like the `-a` flag to run all tests, or the `-d` flag to run specific tests. For more information on `dieharder` options, run `man dieharder`.

## Implemented RNGs
- [Mersenne Twister](http://en.wikipedia.org/wiki/Mersenne_twister)
- [RANDU](http://en.wikipedia.org/wiki/RANDU)
