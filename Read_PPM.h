#ifndef READ_PPM
#define READ_PPM
#include<stdio.h>
#include<stdlib.h>

typedef struct {
     unsigned char red,green,blue;
} PPMPixel;

typedef struct {
     int x, y;
     PPMPixel *data;
} PPMImage;

#define RGB_COMPONENT_COLOR 255
#define CREATOR "bmazerolle"

PPMImage *readPPM(const char *filename);

void writePPM(const char *filename, PPMImage *img);

void changeColorPPM(PPMImage *img);
#endif
