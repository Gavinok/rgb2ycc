/* This file will be loaded instead of the main to test our color
   conversion. To try it run `make test` */
#include "colors.h"
#include <assert.h>

void color_convert_benchmark(RGBPixel rgb){
  YCCPixel ycc = rgb_to_ycbcr(rgb);
  RGBPixel rgb_final = ycbcr_to_rgb(ycc);
  printf("Initial values \n");
  printf("input red   = %u AND output red  = %u Difference = %d\n", rgb.red, rgb_final.red,
         rgb.red - rgb_final.red);
  printf("input green = %u AND ouput green = %u Difference = %d\n", rgb.green, rgb_final.green,
         rgb.green - rgb_final.green);
  printf("input blue  = %u AND ouput blue  = %u Difference = %d\n", rgb.blue, rgb_final.blue,
         rgb.blue - rgb_final.blue);
  printf("Transitional values where \n");
  printf("y = %u\n", ycc.y);
  printf("c_b = %u\n", ycc.c_b);
  printf("c_r = %u\n", ycc.c_r);

  // Assert not too much info was lost
  assert(rgb.red - rgb_final.red < 4);
  assert(rgb.green - rgb_final.green < 4);
  assert(rgb.blue - rgb_final.blue < 4);

  printf("\n\n");
}

void color_convert_benchmark2(RGBPixel* rgb){
  YCCPixel2 ycc = rgb_to_ycbcr2(rgb);
  RGBPixel* rgb_final = ycbcr_to_rgb2(ycc);
  printf("Initial values \n");
  printf("input red   = %u AND output red  = %u Difference = %d\n", rgb[0].red, rgb_final[0].red,
         rgb[0].red - rgb_final[0].red);
  printf("input green = %u AND ouput green = %u Difference = %d\n", rgb[0].green, rgb_final[0].green,
         rgb[0].green - rgb_final[0].green);
  printf("input blue  = %u AND ouput blue  = %u Difference = %d\n", rgb[0].blue, rgb_final[0].blue,
         rgb[0].blue - rgb_final[0].blue);
  printf("Transitional values where \n");
  printf("y = %u\n", ycc.lt);
  printf("c_b = %u\n", ycc.c_b);
  printf("c_r = %u\n", ycc.c_r);

  // Assert not too much info was lost
  assert(rgb[0].red - rgb_final[0].red < 4);
  assert(rgb[0].green - rgb_final[0].green < 4);
  assert(rgb[0].blue - rgb_final[0].blue < 4);

  printf("\n\n");
}

int main()
{
  // Used to check the accuracy of the conversion
  RGBPixel rgb[]  = {{235, 235, 235},
                     {213, 213, 213},
                     {196, 196, 196},
                     {176, 176, 176},
                     {152, 152, 152},
                     {16, 16, 16},
                     {115, 86, 73},
                     {182, 145, 128},
                     {97, 121, 150},
                     {93, 108, 73},
                     {128, 126, 167},
                     {101, 178, 161},
                     {202, 119, 51},
                     {80, 95, 156},
                     {182, 88, 99},
                     {95, 69, 108},
                     {152, 176, 71},
                     {213, 154, 55},
                     {60, 69, 145},
                     {77, 143, 77},
                     {167, 58, 66},
                     {220, 187, 44},
                     {176, 88, 141},
                     {16, 130, 156},
                     {235, 16, 16},
                     {16, 235, 16},
                     {16, 16, 235},
                     {16, 235, 235},
                     {235, 16, 235},
                     {235, 235, 16},
                     {235, 16, 235},
                     {235, 235, 16},
                     {0, 0, 0}};

  for (int i = 0; i < 32; i+=4){
    RGBPixel group[4] = {rgb[i], rgb[i+1], rgb[i+2], rgb[i+3]};
    color_convert_benchmark2(group);
  }
}
