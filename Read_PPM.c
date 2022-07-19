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
        for(j=0; j+2<height; j+=2){
            int start = j * width; 
            for(i=start; i+2<(start+width); i+=2){
                RGBPixel pixelLT = {
                    img->data[i].red,
                    img->data[i].green,
                    img->data[i].blue,
                };
                RGBPixel pixelRT = {
                    img->data[i+1].red,
                    img->data[i+1].green,
                    img->data[i+1].blue,
                };
                RGBPixel pixelLB = {
                    img->data[i+width].red,
                    img->data[i+width].green,
                    img->data[i+width].blue,
                };
                RGBPixel pixelRB = {
                    img->data[i+width+1].red,
                    img->data[i+width+1].green,
                    img->data[i+width+1].blue,
                };
                RGBPixel pixels[4] = {pixelLT, pixelRT, pixelLB, pixelRB};
                YCCPixel2 yccPixels = rgb_to_ycbcr2(pixels);
                RGBPixel result[4];
                ycbcr_to_rgb2(yccPixels, result);
                img->data[i].red=result[0].red;
                img->data[i].green=result[0].green;
                img->data[i].blue=result[0].blue;
                img->data[i+1].red=result[1].red;
                img->data[i+1].green=result[1].green;
                img->data[i+1].blue=result[1].blue;
                img->data[i+width].red=result[2].red;
                img->data[i+width].green=result[2].green;
                img->data[i+width].blue=result[2].blue;
                img->data[i+width+1].red=result[3].red;
                img->data[i+width+1].green=result[3].green;
                img->data[i+width+1].blue=result[3].blue;
            }
            if (i+1<(start+width)) {
                RGBPixel pixelLT = {
                    img->data[i].red,
                    img->data[i].green,
                    img->data[i].blue,
                };
                RGBPixel pixelRT = {
                    img->data[i].red,
                    img->data[i].green,
                    img->data[i].blue,
                };
                RGBPixel pixelLB = {
                    img->data[i+width].red,
                    img->data[i+width].green,
                    img->data[i+width].blue,
                };
                RGBPixel pixelRB = {
                    img->data[i+width].red,
                    img->data[i+width].green,
                    img->data[i+width].blue,
                };
                RGBPixel pixels[4] = {pixelLT, pixelRT, pixelLB, pixelRB};
                YCCPixel2 yccPixels = rgb_to_ycbcr2(pixels);
                RGBPixel result[4];
                ycbcr_to_rgb2(yccPixels, result);
                img->data[i].red=result[0].red;
                img->data[i].green=result[0].green;
                img->data[i].blue=result[0].blue;
                img->data[i+width].red=result[2].red;
                img->data[i+width].green=result[2].green;
                img->data[i+width].blue=result[2].blue;
            }
        }
        if (j < height) {
            int start = j * width; 
            for(int i=start; i+2<(start+width); i+=2){
                RGBPixel pixelLT = {
                    img->data[i].red,
                    img->data[i].green,
                    img->data[i].blue,
                };
                RGBPixel pixelRT = {
                    img->data[i+1].red,
                    img->data[i+1].green,
                    img->data[i+1].blue,
                };
                RGBPixel pixelLB = {
                    img->data[i].red,
                    img->data[i].green,
                    img->data[i].blue,
                };
                RGBPixel pixelRB = {
                    img->data[i+1].red,
                    img->data[i+1].green,
                    img->data[i+1].blue,
                };
                RGBPixel pixels[4] = {pixelLT, pixelRT, pixelLB, pixelRB};
                YCCPixel2 yccPixels = rgb_to_ycbcr2(pixels);
                RGBPixel result[4];
                ycbcr_to_rgb2(yccPixels, result);
                img->data[i].red=result[0].red;
                img->data[i].green=result[0].green;
                img->data[i].blue=result[0].blue;
                img->data[i+1].red=result[1].red;
                img->data[i+1].green=result[1].green;
                img->data[i+1].blue=result[1].blue;
            }
            if (i+1<(start+width)) {
                RGBPixel pixelLT = {
                    img->data[i].red,
                    img->data[i].green,
                    img->data[i].blue,
                };
                RGBPixel pixelRT = {
                    img->data[i].red,
                    img->data[i].green,
                    img->data[i].blue,
                };
                RGBPixel pixelLB = {
                    img->data[i].red,
                    img->data[i].green,
                    img->data[i].blue,
                };
                RGBPixel pixelRB = {
                    img->data[i].red,
                    img->data[i].green,
                    img->data[i].blue,
                };
                RGBPixel pixels[4] = {pixelLT, pixelRT, pixelLB, pixelRB};
                YCCPixel2 yccPixels = rgb_to_ycbcr2(pixels);
                RGBPixel result[4];
                ycbcr_to_rgb2(yccPixels, result);
                img->data[i].red=result[0].red;
                img->data[i].green=result[0].green;
                img->data[i].blue=result[0].blue;
            }
        }
    }
}
