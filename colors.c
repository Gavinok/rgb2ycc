#include "colors.h"
// https://bright.uvic.ca/d2l/le/content/204143/viewContent/1720844/View
// since we are using gcc asm inlining is required
// TODO add an ifdef to handle the possible wrap around
#ifdef ARM
int add( register int a, register int b){
  register int sum ;
  __asm__ __volatile__ (
                        "qadd\t %0, %1, %2\n"
                        : "=r" ( sum )
                        : "r" ( a ) , "r" ( b )
                        );
  return( sum );
}
#else
int add( register int a, register int b){
  register int sum = a + b;
  return sum ;
}
#endif
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
#define CLAMP(X) ((X > 0) ? X : 0)

#define nCLAMP(X, min, max) (X > max ? max : ((X > min) ? X : min))

YCCPixel2 rgb_to_ycbcr2(const RGBPixel** pixels){
  // TODO See if this well ever even need to be clamped
  // Convert to accept 4 RGB Pixels
  // Pass 1: pre-calculate the first C values and just use those in the other 4

  // Pass 2: Use averaging
  uint8_t y_pixels[4];
  int32_t y, c_b = 0, c_r = 0;
  for (uint8_t i = 0; i < 4; i++) {
    // NOTE: y could never actaully be negative
    y = ((YCC_R_R_DOT * pixels[i]->red
          + YCC_R_G_DOT * pixels[i]->green
          + YCC_R_B_DOT * pixels[i]->blue)
         >> INT_SHIFT)
      + Y_SCALING;

    c_b += CLAMP(
                  (((YCC_G_R_DOT * pixels[i]->red)
                    - (YCC_G_G_DOT * pixels[i]->green)
                    + (YCC_G_B_DOT * pixels[i]->blue))
                   >> INT_SHIFT)
                  + C_SCALING);

    c_r += CLAMP((((YCC_B_R_DOT * pixels[i]->red)
                    - (YCC_B_G_DOT * pixels[i]->green)
                    - (YCC_B_B_DOT * pixels[i]->blue))
                   >> INT_SHIFT)
                  + C_SCALING);

    y_pixels[i] = CLAMP(y);
  }

  YCCPixel2 p = {
    y_pixels[0],
    y_pixels[1],
    y_pixels[2],
    y_pixels[3],
    (c_b) >> 2,
    (c_r) >> 2
  };

  return p;
}

RGBPixel* ycbcr_to_rgb2(const YCCPixel2* color, RGBPixel* pixels){
  const int32_t y_lt = (RGB_Y_DOT * (color->lt - Y_SCALING))  >> INT_SHIFT;
  const int32_t y_rt = (RGB_Y_DOT * (color->rt - Y_SCALING))  >> INT_SHIFT;
  const int32_t y_lb = (RGB_Y_DOT * (color->lb - Y_SCALING))  >> INT_SHIFT;
  const int32_t y_rb = (RGB_Y_DOT * (color->rb - Y_SCALING))  >> INT_SHIFT;
  const int32_t c_b_s = color->c_b - C_SCALING;
  const int32_t c_r_s = color->c_r - C_SCALING;
  const int32_t r_term = (RGB_R_DOT * c_r_s)  >> INT_SHIFT;
  const int32_t g_term_0 = RGB_G_R_DOT*(c_r_s)  >> INT_SHIFT;
  const int32_t g_term_1 = RGB_G_B_DOT*(c_b_s)  >> INT_SHIFT;
  const int32_t b_term = (RGB_B_DOT * c_b_s)  >> INT_SHIFT;

  // Due to order of opperations we can't do this ahead of time
  /* int g_term = ((RGB_G_R_DOT * c_r_s) - (RGB_G_B_DOT * c_b_s)); */

  // Defering the bit shifting seems to preserve more accuracy
  pixels[0] = (RGBPixel){
    CLAMP((y_lt + r_term)),
    CLAMP((y_lt - g_term_0 - g_term_1)), // Can't shorten due to order of opperations
    CLAMP((y_lt + b_term)),
  };
  pixels[1] = (RGBPixel){
    CLAMP((y_rt + r_term)),
    CLAMP((y_rt - g_term_0 - g_term_1)),
    CLAMP((y_rt + b_term))
  };
  pixels[2] = (RGBPixel){
    CLAMP((y_lb + r_term)),
    CLAMP((y_lb - g_term_0 - g_term_1)),
    CLAMP((y_lb + b_term))
  };
  pixels[3] = (RGBPixel){
    CLAMP((y_rb + r_term)),
    CLAMP((y_rb - g_term_0 - g_term_1)),
    CLAMP((y_rb + b_term))
  };

  return pixels;
}
