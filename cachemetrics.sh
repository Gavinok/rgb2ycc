#!/bin/sh
make clean
make "CFLAGS=-std=c99 -O3"
rm cachegrind.out.*
valgrind --tool=cachegrind ./rgb2ycc
cg_annotate --auto=yes cachegrind.out.*
