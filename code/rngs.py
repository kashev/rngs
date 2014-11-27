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
    stl = 0
    mt19937 = 1
    # add more generator types here!


def check_generator_type(value):
    for gen in Generator:
        if (gen.name == value) or (gen.value == int(value)):
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

    parser.add_argument('args', nargs=argparse.REMAINDER)

    args = parser.parse_args()

    print("Using generator {}...".format(args.generator.name))

    subprocess.call("./bin/rngs {} | dieharder -g 200 {}"
                    .format(args.generator.value, " ".join(args.args)),
                    shell=True)

if __name__ == '__main__':
    main()
