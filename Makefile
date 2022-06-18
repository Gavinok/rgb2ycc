CC=clang
# These are mostly here to on to cover our buts during the base setup
DEVFLAGS= -Wall -Wextra -fsanitize=address -fsanitize=undefined # -Werror
CLANGFLAGS=-MJ tmp.json
CFLAGS=$(DEVFLAGS)
SRC = Read_PPM.c main.c
OBJ = ${SRC:.c=.o}

all: rgb2ycc

compile_commands.json: tmp.json
	echo '[' > $@
	cat $< >> $@
	echo ']' >> $@

tmp.json: main.c
	$(CC) $(CLANGFLAGS) $(CFLAGS) $< -o $@

# Create the libraries
.c.o:
	$(CC) -c $(CFLAGS) $<

rgb2ycc: main.c
	$(CC) $(CFLAGS) $< -o $@
# Generate the final executable
rgb2ycc: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

test: rgb2ycc
	./$< sample_640×426.bmp # > output_sample_640×426.bmp

clean:
	$(RM) output_sample_640×426.bmp
