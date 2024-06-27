//
// Created by aleen on 3/13/2023.
//

#ifndef PROJECT2_ALGORITHMS_H
#define PROJECT2_ALGORITHMS_H

#endif //PROJECT2_ALGORITHMS_H
#include <vector>
#include "Image.h"
using namespace std;

vector<Image::Pixel> Multiply(vector<Image::Pixel>& P1, vector<Image::Pixel>& P2);

vector<Image::Pixel> Screen(vector<Image::Pixel>& P1, vector<Image::Pixel>& P2);

vector<Image::Pixel> Subtract(vector<Image::Pixel>& P1, vector<Image::Pixel>& P2);

vector<Image::Pixel> Overlay(vector<Image::Pixel>& P1, vector<Image::Pixel>& P2);

vector<Image::Pixel> AddGreen(vector<Image::Pixel>& P1, int num);

vector<Image::Pixel> AddRed(vector<Image::Pixel>& P1, int num);

vector<Image::Pixel> AddBlue(vector<Image::Pixel>& P1, int num);

vector<Image::Pixel> ScaleBlue(vector<Image::Pixel>& P1, int num);

vector<Image::Pixel> ScaleGreen(vector<Image::Pixel>& P1, int num);

vector<Image::Pixel> ScaleRed(vector<Image::Pixel>& P1, int num);

vector<Image::Pixel> SeperateBlue(vector<Image::Pixel>& P1);

vector<Image::Pixel> SeperateGreen(vector<Image::Pixel>& P1);

vector<Image::Pixel> SeperateRed(vector<Image::Pixel>& P1);

vector<Image::Pixel> CombineBGR(vector<Image::Pixel>& B, vector<Image::Pixel>& G, vector<Image::Pixel>& R);

vector<Image::Pixel> Reverse(vector<Image::Pixel>& P1);