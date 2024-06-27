#include "Image.h"

Image::Header::Header(char idlength, char colormaptype, char datatypecode, short colormaporigin, short colormaplength,
                      char colormapdepth, short xorigin, short yorigin, short width, short height, char bitsperpixel,
                      char imagedescriptor) {
    this->idLength = idlength;
    this->colorMapType = colormaptype;
    this->dataTypeCode = datatypecode;
    this->colorMapOrigin = colormaporigin;
    this->colorMapLength = colormaplength;
    this->colorMapDepth = colormapdepth;
    this->xOrigin = xorigin;
    this->yOrigin = yorigin;
    this->width = width;
    this->height = height;
    this->bitsPerPixel = bitsperpixel;
    this->imageDescriptor = imagedescriptor;
}

void Image::add_header(char idlength, char colormaptype, char datatypecode, short colormaporigin, short colormaplength,
                       char colormapdepth, short xorigin, short yorigin, short width, short height, char bitsperpixel,
                       char imagedescriptor) {
    Header newheader = Header(idlength, colormaptype, datatypecode, colormaporigin, colormaplength, colormapdepth, xorigin, yorigin, width, height, bitsperpixel, imagedescriptor);
    this->header = newheader;
}

void Image::add_pixels(unsigned char b, unsigned char g, unsigned char r) {
    Image::Pixel newPixel = Pixel(b, g, r);
    pixels.push_back(newPixel);
}

Image::Header &Image::get_header() {
    return header;
}

Image::Pixel::Pixel(unsigned char blue, unsigned char green, unsigned char red) {
    this->blue = blue;
    this->green = green;
    this->red = red;
}

vector<Image::Pixel> &Image::get_pixels() {
    return pixels;
}

void Image::get_data(fstream& filename) {
    char IDlength;
    filename.read((char *) (&IDlength), 1);
    char colorMapType;
    filename.read((char *) (&colorMapType), 1);
    char dataTypeCode;
    filename.read((char *) (&dataTypeCode), 1);
    short colorMapOrigin;
    filename.read((char *) (&colorMapOrigin), 2);
    short colorMapLength;
    filename.read((char *) (&colorMapLength), 2);
    char colorMapDepth;
    filename.read((char *) (&colorMapDepth), 1);
    short xOrigin;
    filename.read((char *) (&xOrigin), 2);
    short yOrigin;
    filename.read((char *) (&yOrigin), 2);
    short width;
    filename.read((char *) (&width), 2);
    short height;
    filename.read((char *) (&height), 2);
    char bitsPerPixel;
    filename.read((char *) (&bitsPerPixel), 1);
    char imageDescriptor;
    filename.read((char *) (&imageDescriptor), 1);
    this->add_header(IDlength, colorMapType, dataTypeCode, colorMapOrigin, colorMapLength, colorMapDepth,
                   xOrigin, yOrigin, width, height, bitsPerPixel, imageDescriptor);
    for(unsigned int i = 0; i < (height * width); i++){
        unsigned char blue;
        unsigned char green;
        unsigned char red;
        filename.read((char *) (&blue), 1);
        filename.read((char *) (&green), 1);
        filename.read((char *) (&red), 1);
        this->add_pixels(blue, green, red);
    }
}

void Image::create_image_file(Image& headerimage,vector<Pixel>& multipliedpixels, fstream &filename) {
    this->header = headerimage.get_header();
    filename.write((char*)(&header.idLength), 1);
    filename.write((char*)(&header.colorMapType), 1);
    filename.write((char*)(&header.dataTypeCode), 1);
    filename.write((char*)(&header.colorMapOrigin), 2);
    filename.write((char*)(&header.colorMapLength), 2);
    filename.write((char*)(&header.colorMapLength), 1);
    filename.write((char*)(&header.xOrigin), 2);
    filename.write((char*)(&header.yOrigin), 2);
    filename.write((char*)(&header.width), 2);
    filename.write((char*)(&header.height), 2);
    filename.write((char*)(&header.bitsPerPixel), 1);
    filename.write((char*)(&header.imageDescriptor), 1);
    this->pixels = multipliedpixels;
    for(unsigned int i = 0; i < pixels.size(); i++){
        filename.write((char*)(&pixels.at(i).blue), 1);
        filename.write((char*)(&pixels.at(i).green), 1);
        filename.write((char*)(&pixels.at(i).red), 1);
    }
}
