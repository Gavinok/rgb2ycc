// Credit: Inspired by https://stackoverflow.com/questions/2693631/read-ppm-file-and-store-it-in-an-array-coded-with-c

#include "Read_PPM.h"
#include "colors.h"

PPMImage *readPPM(const char *filename)
{
    char buff[16];
    PPMImage *img;
    FILE *fp;
    int c, rgb_comp_color;
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
    if (buff[0] != 'P' || buff[1] != '6') {
        fprintf(stderr, "Invalid image format (must be 'P6')\n");
        exit(1);
    }

    // alloc memory form image
    img = (PPMImage *)malloc(sizeof(PPMImage));
    if (!img) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    // check for comments
    c = getc(fp);
    while (c == '#') {
        while (getc(fp) != '\n')
            ;
        c = getc(fp);
    }

    ungetc(c, fp);
    // read image size information
    if (fscanf(fp, "%d %d", &img->x, &img->y) != 2) {
        fprintf(stderr, "Invalid image size (error loading '%s')\n", filename);
        exit(1);
    }

    // read rgb component
    if (fscanf(fp, "%d", &rgb_comp_color) != 1) {
        fprintf(stderr, "Invalid rgb component (error loading '%s')\n", filename);
        exit(1);
    }

    // check rgb component depth
    if (rgb_comp_color != RGB_COMPONENT_COLOR) {
        fprintf(stderr, "'%s' does not have 8-bits components\n", filename);
        exit(1);
    }

    while (fgetc(fp) != '\n')
        ;
    // memory allocation for pixel data
    img->data = (PPMPixel *)malloc(img->x * img->y * sizeof(PPMPixel));

    if (!img) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    // read pixel data from file
    //  XXX Should we even be doing this cast? This assumes y will always be
    //  positive.
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
    int i,j;
    if(img){
      int width = img->x;
      int height = img->y;
      RGBPixel result[4];
      for(j=0; j+2<height; j+=2){
        int start = j * width;
        for(i=start; i+2<(start+width); i+=2){
          YCCPixel2 yccPixels = rgb_to_ycbcr2((RGBPixel[4]){
              img->data[i],
              img->data[i+1],
              img->data[i+width],
              img->data[i+width+1],
            });
          ycbcr_to_rgb2(yccPixels, result);
          img->data[i] = result[0];
          img->data[i+1] = result[1];
          img->data[i+width] = result[2];
          img->data[i+width+1] = result[3];
        }
        if (i+1<(start+width)) {
          YCCPixel2 yccPixels = rgb_to_ycbcr2((RGBPixel[4]){
              img->data[i],
              img->data[i],
              img->data[i+width],
              img->data[i+width],
            });
          ycbcr_to_rgb2(yccPixels, result);
          img->data[i] = result[0];
          img->data[i+width] = result[2];
        }
      }
      if (j < height) {
        int start = j * width;
        for(int i=start; i+2<(start+width); i+=2){
          YCCPixel2 yccPixels = rgb_to_ycbcr2((RGBPixel[4]){
              img->data[i],
              img->data[i+1],
              img->data[i],
              img->data[i+1],
            });
          ycbcr_to_rgb2(yccPixels, result);
          img->data[i] = result[0];
          img->data[i+1] = result[1];
        }
        if (i+1<(start+width)) {
          YCCPixel2 yccPixels = rgb_to_ycbcr2((RGBPixel[4]){
              img->data[i],
              img->data[i],
              img->data[i],
              img->data[i]
            });
          ycbcr_to_rgb2(yccPixels, result);
          img->data[i] = result[0];
        }
      }
    }
}
