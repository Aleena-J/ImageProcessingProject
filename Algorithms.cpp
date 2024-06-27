#include "Algorithms.h"
using namespace std;

vector<Image::Pixel> Multiply(vector<Image::Pixel>& P1, vector<Image::Pixel>& P2) {
    vector<Image::Pixel> multiplied_pixels;
    for (unsigned int i = 0; i < P1.size(); i++) {
        float nBlue = (((float(P1.at(i).blue) / 255) * (float(P2.at(i).blue) / 255)) *255) + 0.5f;
        unsigned char mBlue = nBlue;
        float nGreen = (((float(P1.at(i).green) / 255) * (float(P2.at(i).green) / 255)) *255) + 0.5f;
        unsigned char mGreen = nGreen;
        float nRed = (((float(P1.at(i).red) / 255) * (float(P2.at(i).red) / 255)) *255) + 0.5f;
        unsigned char mRed = nRed;
        Image::Pixel multipliedPixel = Image::Pixel(mBlue, mGreen, mRed);
        multiplied_pixels.push_back(multipliedPixel);
    }
    return multiplied_pixels;
}

vector<Image::Pixel> Subtract(vector<Image::Pixel>& P1, vector<Image::Pixel>& P2){
    vector<Image::Pixel> subtracted_pixels;
    unsigned char sBlue;
    unsigned char sGreen;
    unsigned char sRed;
    for(unsigned int i = 0; i < P1.size(); i++) {
        int iBlue = P1.at(i).blue - P2.at(i).blue;
        if(iBlue < 0){
            sBlue = 0;
        }else{
            sBlue = iBlue;
        }
        int iGreen = P1.at(i).green - P2.at(i).green;
        if(iGreen < 0){
            sGreen = 0;
        }else{
            sGreen = iGreen;
        }
        int iRed = P1.at(i).red - P2.at(i).red;
        if(iRed < 0){
            sRed = 0;
        }else{
            sRed = iRed;
        }
        Image::Pixel subtractedPixel = Image::Pixel(sBlue, sGreen, sRed);
        subtracted_pixels.push_back(subtractedPixel);
    }
    return subtracted_pixels;
}

vector<Image::Pixel> Screen(vector<Image::Pixel>& P1, vector<Image::Pixel>& P2){
    vector<Image::Pixel> screen_pixels;
    for(unsigned int i = 0; i < P1.size(); i++){
        float iBlue = (1 - ((1-(float(P1.at(i).blue) / 255)) * (1-(float(P2.at(i).blue) / 255)))) * 255 + 0.5f;
        unsigned char scrBlue = iBlue;
        float iGreen = (1 - ((1-(float(P1.at(i).green) / 255)) * (1-(float(P2.at(i).green) / 255)))) * 255 + 0.5f;
        unsigned char scrGreen = iGreen;
        float iRed = (1 - ((1-(float(P1.at(i).red) / 255)) * (1-(float(P2.at(i).red) / 255)))) * 255 + 0.5f;
        unsigned char scrRed = iRed;
        Image::Pixel screenPixel = Image::Pixel(scrBlue, scrGreen, scrRed);
        screen_pixels.push_back(screenPixel);
    }
    return screen_pixels;
}

vector<Image::Pixel> Overlay(vector<Image::Pixel>& P1, vector<Image::Pixel>& P2){
    vector<Image::Pixel> overlayed_pixels;
    unsigned char oBlue;
    unsigned char oGreen;
    unsigned char oRed;
    for(unsigned int i = 0; i < P1.size(); i++){
        if((float(P2.at(i).blue) / 255) <= 0.5f){
            float nBlue = (((float(P1.at(i).blue) / 255) * (float(P2.at(i).blue) / 255))* 2 *255) + 0.5f;
            oBlue = nBlue;
        }else{
            float nBlue = (1-(2*((1-(float(P1.at(i).blue) / 255)) * (1-(float(P2.at(i).blue) / 255))))) * 255 + 0.5f;
            oBlue = nBlue;
        }
        if((float(P2.at(i).green) / 255) <= 0.5f){
            float nGreen = (((float(P1.at(i).green) / 255) * (float(P2.at(i).green) / 255)) *2 *255) + 0.5f;
            oGreen = nGreen;
        }else{
            float nGreen = (1-(2*((1-(float(P1.at(i).green) / 255)) * (1-(float(P2.at(i).green) / 255))))) * 255 + 0.5f;
            oGreen = nGreen;
        }
        if((float(P2.at(i).red) / 255) <= 0.5f){
            float nRed = (((float(P1.at(i).red) / 255) * (float(P2.at(i).red) / 255)) *2 *255) + 0.5f;
            oRed = nRed;
        }else{
            float nRed = (1-(2*((1-(float(P1.at(i).red) / 255)) * (1-(float(P2.at(i).red) / 255))))) * 255 + 0.5f;
            oRed = nRed;
        }
        Image::Pixel overlayPixel = Image::Pixel(oBlue, oGreen, oRed);
        overlayed_pixels.push_back(overlayPixel);
    }
    return overlayed_pixels;
}

vector<Image::Pixel> AddGreen(vector<Image::Pixel>& P1, int num){
    vector<Image::Pixel> added_pixels;
    unsigned char colorvalue;
    for (unsigned int i = 0; i < P1.size(); i++) {
        if ((P1.at(i).green + num) >= 255) {
            colorvalue = 255;
        }else if ((P1.at(i).green + num) <= 0){
            colorvalue = 0;
        }
        else {
            colorvalue = P1.at(i).green + num;
        }
        Image::Pixel addedgreenPixel = Image::Pixel(P1.at(i).blue, colorvalue, P1.at(i).red);
        added_pixels.push_back(addedgreenPixel);
    }
    return added_pixels;
}

vector<Image::Pixel> AddRed(vector<Image::Pixel>& P1, int num){
    vector<Image::Pixel> added_pixels;
    unsigned char colorvalue;
    for (unsigned int i = 0; i < P1.size(); i++) {
        if ((P1.at(i).red + num) >= 255) {
            colorvalue = 255;
        }else if ((P1.at(i).red + num) <= 0){
            colorvalue = 0;
        }
        else {
            colorvalue = P1.at(i).red + num;
        }
        Image::Pixel addedPixel = Image::Pixel(P1.at(i).blue, P1.at(i).green, colorvalue);
        added_pixels.push_back(addedPixel);
    }
    return added_pixels;
}

vector<Image::Pixel> AddBlue(vector<Image::Pixel>& P1, int num){
    vector<Image::Pixel> added_pixels;
    unsigned char colorvalue;
    for (unsigned int i = 0; i < P1.size(); i++) {
        if ((P1.at(i).blue + num) >= 255) {
            colorvalue = 255;
        } else if ((P1.at(i).blue + num) <= 0){
            colorvalue = 0;
        }
        else {
            colorvalue = P1.at(i).blue + num;
        }
        Image::Pixel addedPixel = Image::Pixel(colorvalue,P1.at(i).green, P1.at(i).red);
        added_pixels.push_back(addedPixel);
    }
    return added_pixels;
}

vector<Image::Pixel> SeperateBlue(vector<Image::Pixel>& P1) {
    vector<Image::Pixel> colorchannel;
    for(unsigned int i = 0; i < P1.size(); i++) {
        Image::Pixel addedColor = Image::Pixel(P1.at(i).blue, P1.at(i).blue, P1.at(i).blue);
        colorchannel.push_back(addedColor);
    }
    return colorchannel;
}

vector<Image::Pixel> SeperateGreen(vector<Image::Pixel>& P1){
    vector<Image::Pixel> colorchannel;
    for(unsigned int i = 0; i < P1.size(); i++) {
        Image::Pixel addedColor = Image::Pixel(P1.at(i).green, P1.at(i).green, P1.at(i).green);
        colorchannel.push_back(addedColor);
    }
    return colorchannel;
}

vector<Image::Pixel> SeperateRed(vector<Image::Pixel>& P1){
    vector<Image::Pixel> colorchannel;
    for(unsigned int i = 0; i < P1.size(); i++) {
        Image::Pixel addedColor = Image::Pixel(P1.at(i).red, P1.at(i).red, P1.at(i).red);
        colorchannel.push_back(addedColor);
    }
    return colorchannel;
}

vector<Image::Pixel> CombineBGR(vector<Image::Pixel>& B, vector<Image::Pixel>& G, vector<Image::Pixel>& R){
    vector<Image::Pixel> combined_pixels;
    for(unsigned int i = 0; i < B.size(); i++){
        Image::Pixel combinedPixel = Image::Pixel(B.at(i).blue, G.at(i).green, R.at(i).red);
        combined_pixels.push_back(combinedPixel);
    }
    return combined_pixels;
}

vector<Image::Pixel> Reverse(vector<Image::Pixel>& P1){
    vector<Image::Pixel> reversed_pixels;
    for(int i = P1.size()-1; i >= 0 ; i--){
        Image::Pixel reversedPixel = Image::Pixel(P1.at(i).blue, P1.at(i).green, P1.at(i).red);
        reversed_pixels.push_back(reversedPixel);
    }
    return reversed_pixels;
}

vector<Image::Pixel> ScaleRed(vector<Image::Pixel>& P1, int num) {
    unsigned char colorvalue;
    vector<Image::Pixel> added_pixels;
    for (unsigned int i = 0; i < P1.size(); i++) {
        if ((P1.at(i).red * num) >= 255) {
            colorvalue = 255;
        } else if ((P1.at(i).red * num) <= 0){
            colorvalue = 0;
        }
        else {
            colorvalue = P1.at(i).red * num;
        }
        Image::Pixel addedPixel = Image::Pixel(P1.at(i).blue, P1.at(i).green, colorvalue);
        added_pixels.push_back(addedPixel);
    }
    return added_pixels;
}

vector<Image::Pixel> ScaleGreen(vector<Image::Pixel>& P1, int num) {
    unsigned char colorvalue;
    vector<Image::Pixel> added_pixels;
    for (unsigned int i = 0; i < P1.size(); i++) {
        if ((P1.at(i).green * num) >= 255) {
            colorvalue = 255;
        }else if ((P1.at(i).green * num) <= 0){
            colorvalue = 0;
        }
        else {
            colorvalue = P1.at(i).green * num;
        }
        Image::Pixel addedPixel = Image::Pixel(P1.at(i).blue, colorvalue, P1.at(i).red);
        added_pixels.push_back(addedPixel);
    }
    return added_pixels;
}

vector<Image::Pixel> ScaleBlue(vector<Image::Pixel>& P1, int num) {
    unsigned char colorvalue;
    vector<Image::Pixel> added_pixels;
    for (unsigned int i = 0; i < P1.size(); i++) {
        if ((P1.at(i).blue * num) >= 255) {
            colorvalue = 255;
        } else if ((P1.at(i).blue * num) <= 0){
            colorvalue = 0;
        }
        else {
            colorvalue = P1.at(i).blue * num;
        }
        Image::Pixel addedPixel = Image::Pixel(colorvalue, P1.at(i).green, P1.at(i).red);
        added_pixels.push_back(addedPixel);
    }
    return added_pixels;
}