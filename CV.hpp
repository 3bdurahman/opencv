#pragma once
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;


static string read_Path();
Mat check_Path();
void cmd();
void choose(const int&, const Mat&, Mat&, Mat&);
void cvt(const Mat&, Mat&);
void threshold(const Mat&, Mat&);
void showOriginal(const Mat&);
void showGray(const Mat&);
void showPixel(const Mat&);
void Dev();