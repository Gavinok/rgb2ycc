#ifndef READ_PPM
#define READ_PPM
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

#define RGB_COMPONENT_COLOR 255
#define CREATOR "bmazerolle"

PPMImage *readPPM(const char *filename);

void writePPM(const char *filename, PPMImage *img);

void applyModifierPPM(RGBPixel modifier(RGBPixel),  PPMImage *img);
#endif
