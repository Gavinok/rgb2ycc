#!/bin/sh

make clean
make "CFLAGS=-std=c99 -O3"
valgrind --tool=callgrind ./rgb2ycc
callgrind_annotate callgrind.out.*
rm callgrind.out.*
