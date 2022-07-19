#ifndef COLORS
#define COLORS
#include <stdio.h>
#include "util.h"
#define Y_SCALING 16
#define C_SCALING 128
#define RGB_CLAMP_LIMIT 235

// Doing x << INT_SHIFT is the same as x * 2^INT_SHIFT
#define INT_SHIFT 10

// rgb->ycc
#define RGB_Y_DOT   1191 // was 1.164
#define RGB_R_DOT   1634 // was 1.596
#define RGB_G_R_DOT 832  // was 0.813
#define RGB_G_B_DOT 400  // was 0.391
#define RGB_B_DOT   2066 // was 2.018

// ycc->rgb
#define YCC_R_R_DOT 263  // was 0.257
#define YCC_R_G_DOT 516  // was 0.504
#define YCC_R_B_DOT 100  // was 0.098
#define YCC_G_R_DOT -151 // was -0.148
#define YCC_G_G_DOT 297  // was 0.291
#define YCC_G_B_DOT 449  // was 0.439
#define YCC_B_R_DOT 449  // was 0.439
#define YCC_B_G_DOT 376  // was 0.368
#define YCC_B_B_DOT 72   // was 0.071

YCCPixel rgb_to_ycbcr(RGBPixel color);
RGBPixel ycbcr_to_rgb(YCCPixel color);
YCCPixel2 rgb_to_ycbcr2(RGBPixel* pixels);
RGBPixel* ycbcr_to_rgb2(YCCPixel2 color, RGBPixel* pixels);
#endif
