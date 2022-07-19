#ifndef COLORS
#define COLORS
#include <stdio.h>
#include "util.h"
#define Y_SCALING 16
#define C_SCALING 128
#define RGB_CLAMP_LIMIT 235
YCCPixel rgb_to_ycbcr(RGBPixel color);
RGBPixel ycbcr_to_rgb(YCCPixel color);
YCCPixel2 rgb_to_ycbcr2(RGBPixel* pixels);
RGBPixel* ycbcr_to_rgb2(YCCPixel2 color, RGBPixel* pixels);
#endif
