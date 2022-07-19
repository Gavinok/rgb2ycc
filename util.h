#ifndef COLOR_UTILS
#define COLOR_UTILS

typedef struct {
     unsigned char red,green,blue;
} PPMPixel;

typedef struct {
     unsigned char y,c_b,c_r;
} YCCPixel;

typedef struct {
     unsigned char lt,rt,lb,rb,c_b,c_r;
} YCCPixel2;


typedef struct {
     int x, y;
     PPMPixel *data;
} PPMImage;

typedef PPMPixel RGBPixel;
#endif
