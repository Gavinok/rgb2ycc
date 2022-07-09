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

RGBPixel quality_check(RGBPixel p){
  return ycbcr_to_rgb(rgb_to_ycbcr(p));
}

int main() {
  PPMImage *image;
  image = readPPM("img_forest.ppm");
  applyModifierPPM(&quality_check, image);
  writePPM("img_forest2.ppm", image);
  printf("Press any key...");
  getchar();
}
