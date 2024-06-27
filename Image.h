#ifndef IMAGEPROCESSINGPROJECT_IMAGE_H
#define IMAGEPROCESSINGPROJECT_IMAGE_H

#endif //IMAGEPROCESSINGPROJECT_IMAGE_H
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Image{
public:
    struct Header{
        char idLength;
        char colorMapType;
        char dataTypeCode;
        short colorMapOrigin;
        short colorMapLength;
        char colorMapDepth;
        short xOrigin;
        short yOrigin;
        short width;
        short height;
        char bitsPerPixel;
        char imageDescriptor;
        Header(){
            idLength = 0;
            colorMapType = 0;
            dataTypeCode = 0;
            colorMapOrigin = 0;
            colorMapLength = 0;
            colorMapDepth = 0;
            xOrigin = 0;
            yOrigin = 0;
            width = 0;
            height = 0;
            bitsPerPixel = 0;
            imageDescriptor = 0;
        };
        Header(char idlength, char colormaptype, char datatypecode, short colormaporigin, short colormaplength,
               char colormapdepth, short xorigin, short yorigin, short width, short height, char bitsperpixel,
               char imagedescriptor);
    };
    struct Pixel{
        unsigned char blue;
        unsigned char green;
        unsigned char red;
        Pixel(unsigned char blue, unsigned char green, unsigned char red);
    };
    void add_header(char idlength, char colormaptype, char datatypecode, short colormaporigin, short colormaplength,
                    char colormapdepth, short xorigin, short yorigin, short width, short height, char bitsperpixel,
                    char imagedescriptor);
    void add_pixels(unsigned char b, unsigned char g, unsigned char r);
    Header& get_header();
    vector<Pixel>& get_pixels();
    void get_data(fstream& filename);
    void create_image_file(Image& headerimage, vector<Pixel>& multipliedpixels, fstream& filename);
    Image(Image::Header& copyheader, vector<Pixel>& copypixels){
        this->header = copyheader;
        this->pixels = copypixels;
    }
    Image(){}
private:
    Header header;
    vector<Pixel> pixels;
};