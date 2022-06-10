#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{

  /* ----CLI ARG VALIDATION-----  */
  /* check that arguments */
  if ( (argc < 1) ) {
    fprintf(stderr, "Invalid Usage, expected: rgb2ycc {filename}\n");
    exit(4);
  }
  /* OPEN FILE  */
  const char *filename = argv[1];
  /* check if the filename is completely empty*/
  if ( !strcmp(filename, "") ) {
    printf("Error: No input file specified!\n");
    exit(1);
  }
  FILE *file_pointer = fopen(filename, "r");
  if (file_pointer == NULL) {
    printf("Read error: file not found or cannot be read\n");
    exit(2);
  }

  printf("hello world");
}
