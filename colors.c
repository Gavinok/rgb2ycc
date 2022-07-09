#include "colors.h"

YCCPixel rgb_to_ycbcr(RGBPixel color){
  // TODO See if this well ever even need to be clamped
  // TODO convert to integer arithmetic (should be relitively simple)
  int r = color.red;
  int g = color.green;
  int b = color.blue;
  YCCPixel p = {
    ((0.257 * r) + (0.504 * g) + (0.098 *b)) + Y_SCALING,
    ((-0.148 * r) - (0.291 * g) + (0.439 *b)) + C_SCALING,
    ((+0.439 * r) - (0.368 * g) - (0.071 *b)) + C_SCALING
  };
  return p;
}

RGBPixel ycbcr_to_rgb(YCCPixel color){
  int y_s = color.y - Y_SCALING;
  int c_b_s = color.c_b - C_SCALING;
  int c_r_s = color.c_r - C_SCALING;
  int r = ((1.164 * y_s) + (1.596 * c_r_s));
  int g = ((1.164 * y_s) - (0.813 * c_r_s) - (0.391 * c_b_s));
  int b = ((1.164 * y_s) + (2.018 * c_b_s));
  // TODO Determine if there is a way to clamp here without as much branching
  r = r > 0 ? r : 0;
  g = g > 0 ? g : 0;
  b = b > 0 ? b : 0;
  RGBPixel p = {r,g,b};
  return p;
}
