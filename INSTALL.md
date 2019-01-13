# Installation instructions

## Compiling
To compile use the `make` command. There is only one compiling option, to specify your gcc location. This is optional, and will automatically detect if not specified

Use the make command to compile it

```
make
```
or 
```
make GCC_LOC=/usr/local/bin/gcc
```

## Installing

To install the functions program, use the `make install` command, to move it to `/usr/local/bin`.

```
make install
```