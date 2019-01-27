#!/bin/bash
export CC=/usr/local/bin/gcc-8
export CXX=/usr/local/bin/g++-8

mkdir build
mkdir build/bin

cd build
cmake ..
make