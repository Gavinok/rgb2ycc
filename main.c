#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 41

#define DEBUG
#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

#define dbp()
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

  /* FILE IS NOW OPEN */
  /* char buffer[BUFFERSIZE]; /\* buffer for storing the string from the file  *\/ */
  char place_holder; /* char used to hold the current character for checking its value */
  int length = BUFFERSIZE;

  int i = 0;
  /* place_holder = fgetc(file_pointer); */
  /* header */
  for (int j = 0; i-j < 2; i ++ ){
    DEBUG_PRINT(("place_holder: %d %c\n", j , fgetc(file_pointer)));
  }
  for (int j = i; i-j < 2; i ++ ){
    DEBUG_PRINT(("place_holder: %d %c\n", j , fgetc(file_pointer)));
  }
  while ( i <= length ) {
    place_holder = fgetc(file_pointer);
    /* DEBUG_PRINT(("place_holder: %c", place_holder)); */
    i = 1 + length;
    /* if ( place_holder == EOF ){ */
    /*   buffer[i] = '\0'; */
    /*   break; */
    /* } */
    /* if ( isupper(place_holder) || isdigit(place_holder) ){ */
    /*   buffer[i] = place_holder; */
    /*   i++; */
    /* } else { */
    /*   /\* make sure the rest of the fomating is correct*\/ */
    /*   while ( place_holder != EOF ) { */
    /* 	if ( !isspace(place_holder) ) { */
    /* 	  printf("Error: Invalid format\n"); */
    /* 	  exit(3); */
    /* 	} */
    /* 	place_holder = fgetc(file_pointer); */
    /*   } */
    /*   buffer[i] = '\0'; */
    /*   break; /\* formatting is correct so exit loop *\/ */
    /* } */
  }

  /* DO SOME STUFF */
  fclose(file_pointer);
}
