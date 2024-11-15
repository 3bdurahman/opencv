#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "CV.hpp"
using namespace cv;
using namespace std;

int main()
{
  Mat img, gray, pixel;
  do
  {
    try { img = check_Path(); }
    catch (exception& msg) { cerr << msg.what(); }

  } while (img.empty());
  int sel;
  do
  {
    cmd();
    cin >> sel;
    try { choose(sel, img, gray, pixel); }
    catch (exception& msg) { cerr << "Invalid!, " << msg.what(); }

  } while (sel > 0 && sel < 6);
  return 0;
}