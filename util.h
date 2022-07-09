#ifndef COLOR_UTILS
#define COLOR_UTILS

typedef struct {
     unsigned char red,green,blue;
} PPMPixel;

typedef struct {
     unsigned char y,c_b,c_r;
} YCCPixel;


typedef struct {
     int x, y;
     PPMPixel *data;
} PPMImage;

typedef PPMPixel RGBPixel;
#endif
