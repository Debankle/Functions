# Installation instructions

## Compiling
This program uses CMake to compile and install, so it takes a few steps to compile and install Functions 

Step 1: export your GCC and G++ compiler to the usual variables. Others can be used if you want, but remember them for later
```
export CC=/usr/local/bin/gcc
export CXX=/usr/local/bin/g++
```

Step 2: Enter the build directory and compile the program
```
mkdir build
cd build
cmake ..
make
````