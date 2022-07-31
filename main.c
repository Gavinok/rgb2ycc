#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Read_PPM.h"
#include "colors.h"

#define DEBUG
#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

#define dbp()

int main() {
  PPMImage *image;
  image = readPPM("img_forest.ppm");
  applyModifierPPM(image);
  writePPM("img_forest2.ppm", image);
}
