// Credit: Inspired by https://stackoverflow.com/questions/2693631/read-ppm-file-and-store-it-in-an-array-coded-with-c

#include "Read_PPM.h"
#include "colors.h"

PPMImage *readPPM(const char *filename)
{
    char buff[16];
    PPMImage *img;
    FILE *fp;
    int32_t rgb_comp_color;
    char c;
    // open PPM file for reading
    fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    // read image format
    if (!fgets(buff, sizeof(buff), fp)) {
        perror(filename);
        exit(1);
    }

    // check the image format
    if ('P' != buff[0] || '6' != buff[1]) {
        fprintf(stderr, "Invalid image format (must be 'P6')\n");
        exit(1);
    }

    // Alloc memory form image
    // This cast is mostly just to clarify that this is a
    // pointer. While not manditory with most C compilers this is
    // required if compiled with a C++ compiler like g++
    img = (PPMImage *)malloc(sizeof(PPMImage));
    if (!img) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    // check for comments
    c = getc(fp);
    while ('#' == c) {
        while (getc(fp) != '\n')
            ;
        c = getc(fp);
    }

    ungetc(c, fp);
    // read image size information
    if (2 != fscanf(fp, "%d %d", &img->x, &img->y)) {
        fprintf(stderr, "Invalid image size (error loading '%s')\n", filename);
        exit(1);
    }

    // read rgb component
    if (1 != fscanf(fp, "%d", &rgb_comp_color)) {
        fprintf(stderr, "Invalid rgb component (error loading '%s')\n", filename);
        exit(1);
    }

    // check rgb component depth
    if (RGB_COMPONENT_COLOR != rgb_comp_color) {
        fprintf(stderr, "'%s' does not have 8-bits components\n", filename);
        exit(1);
    }

    while ('\n' != fgetc(fp))
        ;

    // Memory allocation for pixel data.

    // This cast is mostly just to clarify that this is a
    // pointer. While not manditory with most C compilers this is
    // required if compiled with a C++ compiler like g++
    img->data = (PPMPixel *)malloc(img->x * img->y * sizeof(PPMPixel));

    if (!img) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    // Read pixel data from file.

    // This casting is necessary to properly
    // function on newer versions of clang
    if (fread(img->data, 3 * img->x, img->y, fp) != (size_t)img->y) {
        fprintf(stderr, "Error loading image '%s'\n", filename);
        exit(1);
    }

    fclose(fp);
    return img;
}

void writePPM(const char *filename, PPMImage *img)
{
    FILE *fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp) {
         fprintf(stderr, "Unable to open file '%s'\n", filename);
         exit(1);
    }

    //write the header file
    //image format
    fprintf(fp, "P6\n");

    //comments
    fprintf(fp, "# Created by %s\n",CREATOR);

    //image size
    fprintf(fp, "%d %d\n",img->x,img->y);

    // rgb component depth
    fprintf(fp, "%d\n",RGB_COMPONENT_COLOR);

    // pixel data
    fwrite(img->data, 3 * img->x, img->y, fp);

    // Free the image data
    free(img->data);
    free(img);
    fclose(fp);
}

/*
 Apply different modifications to the given image modifier is given as
 a function pointer so new filtering approaches can be applied easily.
 This may not be the best way to apply the final version since I am
 unsure how well gcc applies optimizations to function pointers.
*/
void applyModifierPPM(PPMImage *img)
{
    int32_t i,j;
    if(img){
      int32_t width = img->x;
      int32_t height = img->y;
      RGBPixel result[4];
      for(j=0; j+2<height; j+=2){
        int32_t start = j * width;
        for(i=start; i+2<(start+width); i+=2){
          // Cast to keep more concise at 0 cost as seen in the
          // resulting assembally
          YCCPixel2 yccPixels = rgb_to_ycbcr2((const RGBPixel*[4]){
              &img->data[i],
              &img->data[i+1],
              &img->data[i+width],
              &img->data[i+width+1],
            });
          ycbcr_to_rgb2(&yccPixels, result);
          img->data[i] = result[0];
          img->data[i+1] = result[1];
          img->data[i+width] = result[2];
          img->data[i+width+1] = result[3];
        }
        if (i+1<(start+width)) {
          YCCPixel2 yccPixels = rgb_to_ycbcr2((const RGBPixel*[4]){
              &img->data[i],
              &img->data[i],
              &img->data[i+width],
              &img->data[i+width],
            });
          ycbcr_to_rgb2(&yccPixels, result);
          img->data[i] = result[0];
          img->data[i+width] = result[2];
        }
      }
      if (height > j) {
        int32_t start = j * width;
        for(int32_t i=start; i+2<(start+width); i+=2){
          // Cast to keep more concise at 0 cost as seen in the
          // resulting assembally
          YCCPixel2 yccPixels = rgb_to_ycbcr2((const RGBPixel*[4]){
              &img->data[i],
              &img->data[i+1],
              &img->data[i],
              &img->data[i+1],
            });
          ycbcr_to_rgb2(&yccPixels, result);
          img->data[i] = result[0];
          img->data[i+1] = result[1];
        }
        if (i+1<(start+width)) {
          // Cast to keep more concise at 0 cost as seen in the
          // resulting assembally
          YCCPixel2 yccPixels = rgb_to_ycbcr2((const RGBPixel*[4]){
              &img->data[i],
              &img->data[i],
              &img->data[i],
              &img->data[i]
            });
          ycbcr_to_rgb2(&yccPixels, result);
          img->data[i] = result[0];
        }
      }
    }
}
