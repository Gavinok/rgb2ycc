#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Read_PPM.h"

#define DEBUG
#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

#define dbp()
int main(int argc, char* argv[]) {
  PPMImage *image;
  image = readPPM("img_forest.ppm");
  changeColorPPM(image);
  writePPM("img_forest2.ppm", image);
  printf("Press any key...");
  getchar();
}
