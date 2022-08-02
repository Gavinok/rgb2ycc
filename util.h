#ifndef COLOR_UTILS
#define COLOR_UTILS
#include <stdint.h>
typedef struct {
     uint8_t red,green,blue;
} PPMPixel;

typedef struct {
     uint8_t y,c_b,c_r;
} YCCPixel;

typedef struct {
     uint8_t lt,rt,lb,rb,c_b,c_r;
} YCCPixel2;


typedef struct {
     int32_t x, y;
     PPMPixel *data;
} PPMImage;

typedef PPMPixel RGBPixel;
#endif
