# Be sure to change this to gcc when we move to arm
CC=clang
# These are mostly here to on to cover our buts during the base setup
DEVFLAGS= -Wall -Wextra -fsanitize=address -fsanitize=undefined
CFLAGS=$(DEVFLAGS)
SRC = Read_PPM.c main.c
OBJ = ${SRC:.c=.o}

all: rgb2ycc

# This is just here to generate a json file for your text editor to
# use. Simply run `make compile_commands.json`
ifeq ($(CC), clang)
CLANGFLAGS=-MJ tmp.json
CFLAGS=$(DEVFLAGS) $(CLANGFLAGS)

# Produce file for use with editor
compile_commands.json: tmp.json
	echo '[' > $@
	cat $< >> $@
	echo ']' >> $@

# Create a temperary file to store the flags in
tmp.json: rgb2ycc

endif

# Create the libraries
.c.o:
	$(CC) -c $(CFLAGS) $<

# Generate the final executable
rgb2ycc: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# TODO Implement testcases
# test: test/test.c $(OBJ)

clean:
	$(RM) output_sample_640×426.bmp
