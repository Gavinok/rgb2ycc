CC=gcc
# These are mostly here to on to cover our buts during the base setup
DEVFLAGS=-Werror -Wall -Wextra -fsanitize=address -fsanitize=undefined
CFLAGS=$(DEVFLAGS)

all: rgb2ycc

rgb2ycc: main.c
	$(CC) $(CFLAGS) $< -o $@

test: rgb2ycc
	$< sample_640×426.bmp > output_sample_640×426.bmp

clean:
	$(RM) output_sample_640×426.bmp
