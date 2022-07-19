#include "colors.h"

YCCPixel rgb_to_ycbcr(RGBPixel color){
  // TODO See if this well ever even need to be clamped
  // TODO convert to integer arithmetic (should be relitively simple)
  int r = color.red;
  int g = color.green;
  int b = color.blue;
  YCCPixel p = {
    ((257 * r / 1000) + (504 * g / 1000) + (98 * b / 1000)) + Y_SCALING,
    ((-148 * r / 1000) - (291 * g / 1000) + (439 * b / 1000)) + C_SCALING,
    ((+439 * r / 1000) - (368 * g / 1000) - (71 * b / 1000)) + C_SCALING
  };
  return p;
}

RGBPixel ycbcr_to_rgb(YCCPixel color){
  int y_s = color.y - Y_SCALING;
  int c_b_s = color.c_b - C_SCALING;
  int c_r_s = color.c_r - C_SCALING;
  int r = ((1164 * y_s / 1000) + (1596 * c_r_s / 1000));
  int g = ((1164 * y_s / 1000) - (813 * c_r_s / 1000) - (391 * c_b_s / 1000));
  int b = ((1164 * y_s / 1000) + (2018 * c_b_s / 1000));
  // TODO Determine if there is a way to clamp here without as much branching
  // Answer: Doesn't appear to be a good way in C, QADD in asm is best solution. 
  // Could try adding this as a normal conditional rather than an inline since I 
  // think that avoiding the re-assignment of r = r etc might be slowing it down by a couple cycles.
  r = r > 0 ? r : 0;
  g = g > 0 ? g : 0;
  b = b > 0 ? b : 0;
  RGBPixel p = {r,g,b};
  return p;
}

YCCPixel2 rgb_to_ycbcr2(RGBPixel* pixels){
  // TODO See if this well ever even need to be clamped
  // TODO convert to integer arithmetic (should be relitively simple)
  // Convert to accept 4 RGB Pixels
  // Pass 1: pre-calculate the first C values and just use those in the other 4
  
  // YCCPixel2 p = {
  //   ((257 * pixels[0].red / 1000) + (504 * pixels[0].green / 1000) + (98 * pixels[0].blue / 1000)) + Y_SCALING, 
  //   ((257 * pixels[1].red / 1000) + (504 * pixels[1].green / 1000) + (98 * pixels[1].blue / 1000)) + Y_SCALING,
  //   ((257 * pixels[2].red / 1000) + (504 * pixels[2].green / 1000) + (98 * pixels[2].blue / 1000)) + Y_SCALING, 
  //   ((257 * pixels[3].red / 1000) + (504 * pixels[3].green / 1000) + (98 * pixels[3].blue / 1000)) + Y_SCALING,
  //   ((-148 * pixels[0].red / 1000) - (291 * pixels[0].green / 1000) + (439 * pixels[0].blue / 1000)) + C_SCALING,
  //   ((439 * pixels[0].red / 1000) - (368 * pixels[0].green / 1000) - (71 * pixels[0].blue / 1000)) + C_SCALING
  // }

  // Pass 2: Use averaging
  YCCPixel y_pixels[4];
  int y, c_b, c_r;
  for (int i = 0; i < 4; i++) {
    y = ((257 * pixels[i].red / 1000) + (504 * pixels[i].green / 1000) + (98 * pixels[i].blue / 1000)) + Y_SCALING;
    c_b = ((-148 * pixels[1].red / 1000) - (291 * pixels[1].green / 1000) + (439 * pixels[1].blue / 1000)) + C_SCALING;
    c_r = ((439 * pixels[1].red / 1000) - (368 * pixels[1].green / 1000) - (71 * pixels[1].blue / 1000)) + C_SCALING;
    y = y > 0 ? y : 0;
    c_b = c_b > 0 ? c_b : 0;
    c_r = c_r > 0 ? c_r : 0;
    YCCPixel p = {
      y,
      c_b,
      c_r,
    };
    y_pixels[i] = p;
  }

  YCCPixel2 p = {
    y_pixels[0].y, 
    y_pixels[1].y,
    y_pixels[2].y, 
    y_pixels[3].y,
    ((y_pixels[0].c_b + y_pixels[1].c_b + y_pixels[2].c_b + y_pixels[3].c_b) / 4),
    ((y_pixels[0].c_r + y_pixels[1].c_r + y_pixels[2].c_r + y_pixels[3].c_r) / 4)
  };

  return p;
}

RGBPixel* ycbcr_to_rgb2(YCCPixel2 color, RGBPixel* pixels){
  // Pass 1: Bad math
  // int y_lt = color.lt - Y_SCALING;
  // int y_rt = color.rt - Y_SCALING;
  // int y_lb = color.lb - Y_SCALING;
  // int y_rb = color.rb - Y_SCALING;
  // int c_b_s = color.c_b - C_SCALING;
  // int c_r_s = color.c_r - C_SCALING;
  // RGBPixel pixelLT = {
  //   ((1164 * y_lt / 1000) + (1596 * c_r_s / 1000)),
  //   ((1164 * y_lt / 1000) - (813 * c_r_s / 1000) - (391 * c_b_s / 1000)),
  //   ((1164 * y_lt / 1000) + (2018 * c_b_s / 1000))
  // };
  // RGBPixel pixelRT = {
  //   ((1164 * y_rt / 1000) + (1596 * c_r_s / 1000)),
  //   ((1164 * y_rt / 1000) - (813 * c_r_s / 1000) - (391 * c_b_s / 1000)),
  //   ((1164 * y_rt / 1000) + (2018 * c_b_s / 1000))
  // };
  // RGBPixel pixelLB = {
  //   ((1164 * y_lb / 1000) + (1596 * c_r_s / 1000)),
  //   ((1164 * y_lb / 1000) - (813 * c_r_s / 1000) - (391 * c_b_s / 1000)),
  //   ((1164 * y_lb / 1000) + (2018 * c_b_s / 1000))
  // };
  // RGBPixel pixelRB = {
  //   ((1164 * y_rb / 1000) + (1596 * c_r_s / 1000)),
  //   ((1164 * y_rb / 1000) - (813 * c_r_s / 1000) - (391 * c_b_s / 1000)),
  //   ((1164 * y_rb / 1000) + (2018 * c_b_s / 1000))
  // };

  // Pass 2: Better math:
  int y_lt = 1164 * (color.lt - Y_SCALING) / 1000;
  int y_rt = 1164 * (color.rt - Y_SCALING) / 1000;
  int y_lb = 1164 * (color.lb - Y_SCALING) / 1000;
  int y_rb = 1164 * (color.rb - Y_SCALING) / 1000;
  int c_b_s = color.c_b - C_SCALING;
  int c_r_s = color.c_r - C_SCALING;
  int r_term = 1596 * c_r_s / 1000;
  int g_term = (813 * c_r_s / 1000) - (391 * c_b_s / 1000);
  int b_term = 2018 * c_b_s / 1000;

  RGBPixel pixelLT = {
    (y_lt + r_term) > 0 ? (y_lt + r_term) : 0,
    (y_lt - g_term) > 0 ? (y_lt - g_term) : 0,
    (y_lt + b_term) > 0 ? (y_lt + b_term) : 0
  };
  RGBPixel pixelRT = {
    (y_rt + r_term) > 0 ? (y_rt + r_term) : 0,
    (y_rt - g_term) > 0 ? (y_rt - g_term) : 0,
    (y_rt + b_term) > 0 ? (y_rt + b_term) : 0
  };
  RGBPixel pixelLB = {
    (y_lb + r_term) > 0 ? (y_lb + r_term) : 0,
    (y_lb - g_term) > 0 ? (y_lb - g_term) : 0,
    (y_lb + b_term) > 0 ? (y_lb + b_term) : 0
  };
  RGBPixel pixelRB = {
    (y_rb + r_term) > 0 ? (y_rb + r_term) : 0,
    (y_rb - g_term) > 0 ? (y_rb - g_term) : 0,
    (y_rb + b_term) > 0 ? (y_rb + b_term) : 0
  };

  pixels[0] = pixelLT;
  pixels[1] = pixelRT;
  pixels[2] = pixelLB;
  pixels[3] = pixelRB;
  return pixels;
}