#include "colors.h"
// https://bright.uvic.ca/d2l/le/content/204143/viewContent/1720844/View

// While nolonger used this is kept for reference
#ifdef ARM
// Since we are using gcc asm inlining is required
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
// ARM efficient clamp to ensure values always fall between 255 and 0
inline int32_t clamp(int32_t x){
  // unsigned is used to ensure numbers bellow 0 and above 255 will set y to 1
  uint32_t y = x>>8;
  if (y)
    x = ~y >> 24;
  return x;
}

YCCPixel2 rgb_to_ycbcr2(const RGBPixel** pixels){
  uint8_t y_pixels[4];
  int32_t y, c_b = 0, c_r = 0;
  for (uint8_t i = 0; 4 > i ; i++) {
    // NOTE: y could never actaully be negative
    y = ((YCC_R_R_DOT * pixels[i]->red
          + YCC_R_G_DOT * pixels[i]->green
          + YCC_R_B_DOT * pixels[i]->blue)
         >> INT_SHIFT)
    + Y_SCALING;

    c_b += (((YCC_G_R_DOT * pixels[i]->red)
             - (YCC_G_G_DOT * pixels[i]->green)
             + (YCC_G_B_DOT * pixels[i]->blue))
            >> INT_SHIFT)
    + C_SCALING;

    c_r += (((YCC_B_R_DOT * pixels[i]->red)
             - (YCC_B_G_DOT * pixels[i]->green)
             - (YCC_B_B_DOT * pixels[i]->blue))
            >> INT_SHIFT)
    + C_SCALING;

    y_pixels[i] = y;
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
    clamp((y_lt + r_term)),
    clamp((y_lt - g_term_0 - g_term_1)), // Can't shorten due to order of opperations
    clamp((y_lt + b_term)),
  };
  pixels[1] = (RGBPixel){
    clamp((y_rt + r_term)),
    clamp((y_rt - g_term_0 - g_term_1)),
    clamp((y_rt + b_term))
  };
  pixels[2] = (RGBPixel){
    clamp((y_lb + r_term)),
    clamp((y_lb - g_term_0 - g_term_1)),
    clamp((y_lb + b_term))
  };
  pixels[3] = (RGBPixel){
    clamp((y_rb + r_term)),
    clamp((y_rb - g_term_0 - g_term_1)),
    clamp((y_rb + b_term))
  };

  return pixels;
}
