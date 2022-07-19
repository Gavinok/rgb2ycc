#ifndef COLORS
#define COLORS
#include <stdio.h>
#include "util.h"
#define Y_SCALING 16
#define C_SCALING 128
#define RGB_CLAMP_LIMIT 235

// doing x << INT_SHIFT is the same as x * 2^INT_SHIFT
#define INT_SHIFT 10

// rgb->ycc
#define RGB_Y_DOT  (int)(1.164 << INT__SHIFT) // was 1164
/* #define RGB_Y_DOT (1164) // was 1164 */
#define RGB_R_DOT   (int)(1.596 << INT__SHIFT) // was 1596
#define RGB_G_R_DOT (int)(0.813 << INT__SHIFT) // was 813
#define RGB_G_B_DOT (int)(0.391 << INT__SHIFT) // was 813
#define RGB_B_DOT   (int)(2.018 << INT__SHIFT) // was 2018

// ycc->rgb
#define YCC_R_R_DOT (int)(0.257 << INT__SHIFT)
#define YCC_R_G_DOT (int)(0.504 << INT__SHIFT)
#define YCC_R_B_DOT (int)(0.098 << INT__SHIFT)
#define YCC_G_R_DOT (int)(-0.148 << INT__SHIFT)
#define YCC_G_G_DOT (int)(0.291 << INT__SHIFT)
#define YCC_G_B_DOT (int)(0.439 << INT__SHIFT)
#define YCC_B_R_DOT (int)(0.439 << INT__SHIFT)
#define YCC_B_G_DOT (int)(0.368 << INT__SHIFT)
#define YCC_B_B_DOT (int)(0.071 << INT__SHIFT)

YCCPixel rgb_to_ycbcr(RGBPixel color);
RGBPixel ycbcr_to_rgb(YCCPixel color);
YCCPixel2 rgb_to_ycbcr2(RGBPixel* pixels);
RGBPixel* ycbcr_to_rgb2(YCCPixel2 color, RGBPixel* pixels);
#endif
