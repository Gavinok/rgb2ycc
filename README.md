# Project overview: 
  main.c: Central calling function for all steps
  Read_PPM.c: Reading/writing PPM images, iterative calling of conversion functions
  colors.c: Color space conversion functions
  
  
# Building the project

## Building the project for arm

    make

## Building the project locally

    make CC=gcc

## Generating .s files

    make color.s

Replace `color` with whatever file you would like 

# Usage

To convert the included image run

    make
    ./rgb2ycc

by default this will create an arm binary

# Testing

To check how accurate the color conversion is simply run

    make test

# Cleaning the project

If conflicting artifacts exist e.g. .o files exist run

    make clean
