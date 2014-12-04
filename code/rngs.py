#!/usr/bin/env python3
# rngs
# ECE 541 Project 2
# Kashev Dalmia - dalmia3
# David Huang   - huang157

""" The called script for this project. Wraps the C++ based RNG, passes
    necessary options to it, and then pipes the output to dieharder. Note that
    this script requires Python3.
"""

import argparse
import enum
import os
import subprocess


@enum.unique
class Generator(enum.Enum):
    all = -1
    stl = 0
    mt19937 = 1
    randu = 2
    minstd = 3
    r250 = 4
    ranlux = 5
    xorshift = 6
    cmwc = 7
    # Add more generator types here! Remember to update main.cpp.


def check_generator_type(value):
    try:
        ival = int(value)
        for gen in Generator:
            if gen.value == ival:
                return gen
    except ValueError:
        for gen in Generator:
            if gen.name == value:
                return gen

    raise argparse.ArgumentTypeError(
        "{} is an invalid generator type.".format(value))


def main():
    """ Parse command line arguments, pass appropriate ones to the RNG,
        and pipe to dieharder.
    """

    # Change to script directory
    abspath = os.path.abspath(__file__)
    dname = os.path.dirname(abspath)
    os.chdir(dname)

    parser = argparse.ArgumentParser(
        description="Wrapper script for RNGs. Sets up C++ RNG and pipes to"
                    "dieharder for analysis.",
        formatter_class=argparse.RawTextHelpFormatter)

    helpstring = "The generator can be any specified number or name:\n"
    for gen in Generator:
        helpstring += "{} | {}\n".format(gen.value, gen.name)

    parser.add_argument("generator", type=check_generator_type,
                        help=helpstring)
    parser.add_argument("--directory", type=str,
                        help="Directory to output files to",
                        action='store', default="results")
    parser.add_argument("--file", action='store_true',
                        help="Output to file or not.")

    parser.add_argument('args', nargs=argparse.REMAINDER)

    args = parser.parse_args()

    # Create Results Directory if it doesn't exist, if the file option is
    # turned on
    if args.file and not os.path.exists(args.directory):
        os.makedirs(args.directory)

    # Check for running all generators.
    if args.generator == Generator.all:
        print("Using all generators...")
        for gen in Generator:
            if gen != Generator.all:
                if args.file:
                    pipestring = " > {}/{}.txt".format(args.directory, gen.name)
                else:
                    pipestring = ""
                print("Running generator {}...".format(gen.name))
                subprocess.call("./bin/rngs {} | dieharder -g 200 {}{}"
                                .format(gen.value,
                                        " ".join(args.args),
                                        pipestring),
                                shell=True)

    # Run a single generator.
    else:
        if args.file:
            pipestring = " > {}/{}.txt".format(args.directory,
                                               args.generator.name)
        else:
            pipestring = ""
        print("Using generator {}...".format(args.generator.name))
        subprocess.call("./bin/rngs {} | dieharder -g 200 {}{}"
                        .format(args.generator.value,
                                " ".join(args.args),
                                pipestring),
                        shell=True)

if __name__ == '__main__':
    main()
