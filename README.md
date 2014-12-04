rngs
====

    /*
     * rngs
     * ECE 541 Project 2
     * Kashev Dalmia - dalmia3
     * David Huang   - huang157
     */

A project for ECE 541 Project #2 @ UIUC. Investigating Random Number Generators.


This project uses the [Dieharder](https://www.phy.duke.edu/~rgb/General/dieharder.php) project to test random number generators implemented in C++. More information can be found in the `proposal`, `report`, and `presentation` folders. The final version of the paper in this repository which explains much of the theory behind this project can be found [here](https://github.com/kashev/rngs/raw/master/report/report.pdf).


This project requires `dieharder`. Obtain it from the link above, install it with your package manager, or on ubuntu, run `code/install_deps.sh`.

To build the project without the use of an IDE, run:

    cd code && cmake . && make

Example usage of Python calling script:

    ./rngs.py stl -d 0
    ./rngs.py mt19937 -a
    ./rngs.py --file all -a

Note that the only flag that's passed to `dieharder` by default is `-g 200`, to tell it to use `std_in_raw`. All other `dieharder` options, like the `-a` flag to run all tests, or the `-d` flag to run specific tests. For more information on `dieharder` options, run `man dieharder`.

Also note that running a single RNG through all the `dieharder` tests take a little under an hour on my laptop. So running all of them will take a long time. User beware!

## Implemented RNGs
- [Mersenne Twister](http://en.wikipedia.org/wiki/Mersenne_twister)
- [RANDU](http://en.wikipedia.org/wiki/RANDU)
- [MINSTD](http://en.wikipedia.org/wiki/Lehmer_random_number_generator#Parameters_in_common_use)
- [R250](http://fossies.org/dox/gsl-1.16/r250_8c_source.html)
- [RANLUX](https://github.com/LuaDist/gsl/blob/master/rng/ranlux.c)
- [Xorshift](http://en.wikipedia.org/wiki/Xorshift)
- [CMWC](http://en.wikipedia.org/wiki/Multiply-with-carry#Implementation)
- [TinyMT](http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/TINYMT/index.html)
