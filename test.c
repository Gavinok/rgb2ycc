/* This file will be loaded instead of the main to test our color
   conversion. To try it run `make test` */
#include "colors.h"
#include <assert.h>
#include <stdlib.h>

#define THREASHOLD 50
void color_convert_benchmark2(const RGBPixel** rgb, YCCPixel expected_ycc){
  YCCPixel2 ycc = rgb_to_ycbcr2(rgb);
  RGBPixel* p = malloc(sizeof(RGBPixel[4]));
  RGBPixel* rgb_final = ycbcr_to_rgb2(&ycc, p);
  printf("Initial values \n");
  printf("input red   = %u AND output red  = %u Difference = %d\n", rgb[0]->red, rgb_final[0].red,
         rgb[0]->red - rgb_final[0].red);
  printf("input green = %u AND ouput green = %u Difference = %d\n", rgb[0]->green, rgb_final[0].green,
         rgb[0]->green - rgb_final[0].green);
  printf("input blue  = %u AND ouput blue  = %u Difference = %d\n", rgb[0]->blue, rgb_final[0].blue,
         rgb[0]->blue - rgb_final[0].blue);
  printf("Transitional values where \n");
  printf("y   = %u expected %u difference = %d\n", ycc.lt, expected_ycc.y,    ycc.lt - expected_ycc.y);
  printf("c_b = %u expected %u difference = %d\n", ycc.c_b, expected_ycc.c_b, ycc.c_b - expected_ycc.c_b);
  printf("c_r = %u expected %u difference = %d\n", ycc.c_r, expected_ycc.c_r, ycc.c_r - expected_ycc.c_r);

  // Assert not too much info was lost
  assert(abs(rgb[0]->red - rgb_final[0].red) <= THREASHOLD);
  assert(abs(rgb[0]->green - rgb_final[0].green) <= THREASHOLD);
  assert(abs(rgb[0]->blue - rgb_final[0].blue) <= THREASHOLD);
  free(p);
  printf("\n\n");
}

int main()
{
  // Used to check the accuracy of the conversion
  struct {
    RGBPixel rgb;
    YCCPixel ycc;
  } exp[] =
    {{{235, 235, 235}, {235, 128, 128}},
     {{213, 213, 213}, {213, 128, 128}},
     {{196, 196, 196}, {196, 128, 128}},
     {{176, 176, 176}, {176, 128, 128}},
     {{152, 152, 152}, {152, 128, 128}},
     {{16, 16, 16},    {16, 128, 128}},
     {{115, 86, 73},   {91, 118, 143}},
     {{182, 145, 128}, {152, 115, 148}},
     {{97, 121, 150},  {118, 146, 114}},
     {{93, 108, 73},   {102, 112, 122}},
     {{128, 126, 167}, {129, 149, 127}},
     {{101, 178, 161}, {160, 128, 89}},
     {{202, 119, 51},  {132, 83, 174}},
     {{80, 95, 156},   {96, 161, 117}},
     {{182, 88, 99},   {109, 123, 176}},
     {{95, 69, 108},   {77, 145, 139}},
     {{152, 176, 71},  {163, 77, 121}},
     {{213, 154, 55},  {159, 70, 163}},
     {{60, 69, 145},   {73, 168, 120}},
     {{77, 143, 77},   {124, 102, 97}},
     {{167, 58, 66},   {82, 119, 183}},
     {{220, 187, 44},  {184, 51, 152}},
     {{176, 88, 141},  {111, 145, 171}},
     {{16, 130, 156},  {108, 155, 68}},
     {{235, 16, 16},   {63, 102, 240}},
     {{16, 235, 16},   {173, 42, 26}},
     {{16, 16, 235},   {32, 240, 118}},
     {{16, 235, 235},  {188, 154, 16}},
     {{235, 16, 235},  {78, 214, 230}},
     {{235, 235, 16},  {219, 16, 138}}};

  for (int i = 0; i < 32; i++){
    printf("iteration %d\n", i);
    color_convert_benchmark2((const RGBPixel*[4]){&exp[i].rgb, &exp[i].rgb, &exp[i].rgb, &exp[i].rgb},
                             exp[i].ycc);
  }
}
