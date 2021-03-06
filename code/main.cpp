/*
 * rngs
 * ECE 541 Project 2
 * Kashev Dalmia - dalmia3
 * David Huang   - huang157
 */

#include <iostream>
#include <signal.h>

#include "stl_rng.h"
#include "mt19937.h"
#include "randu.h"
#include "minstd.h"
#include "r250.h"
#include "xorshift.h"
#include "ranlux.h"
#include "cmwc.h"
#include "tinymt.h"

using namespace std;
using namespace rng;

static RandomNumberGenerator* randgen_ptr = nullptr;

/*
 * Function for cleaning up allocated memory for the RNG.
 */
void clean_up_rng(int signum) {
    delete randgen_ptr;
    randgen_ptr = nullptr;

    exit(signum);
}

int main(int argc, char *argv[]) {

    unsigned int rng = 2;

    if (argc >= 2)
    {
        rng = stoi(argv[1]);
    }

    switch(rng)
    {
        case 0: { // STL RNG using std::mt19937. For testing only.
            randgen_ptr = new StlRng();
            break;
        }
        case 1: { // MT19937
            randgen_ptr = new MT19937();
            break;
        }
        case 2: { // RANDU
            randgen_ptr = new RANDU();
            break;
        }
        case 3: { // MINSTD
            randgen_ptr = new MINSTD();
        }
        case 4: { // R250
            randgen_ptr = new R250();
            break;
        }
        case 5: { // Subtract with Carry with Discard (RANLUX)
            randgen_ptr = new RANLUX();
            break;
        }
        case 6: { // Xorshift
            randgen_ptr = new Xorshift();
            break;
        }
        case 7: { // Complimentary Multiply with Carry
            randgen_ptr = new CMWC();
            break;
        }
        case 8: { // TinyMT
            randgen_ptr = new TinyMT();
            break;
        }
        /*
         * Add more RNG types here! Remember to update rngs.py.
         */
        default: {
            cerr << rng << " is not a supported RNG value." << endl;
            exit(1);
        }
    }

    randgen_ptr->seed(0xDEADBEEF);

    /*
     * Clean Up the RNG reference when the pipe to dieharder is closed,
     * or when the user sends ctrl+c to the program.
     * See rngs.py for more calling details.
     */
    signal(SIGPIPE, clean_up_rng);
    signal(SIGINT,  clean_up_rng);

    uint32_t x = 0;
    while(true)
    {
        x = static_cast<uint32_t>((*randgen_ptr)());
        cout.write(reinterpret_cast<const char*>(&x), sizeof x);
    }

    return 0;
}
