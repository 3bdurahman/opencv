#include "CV.hpp"
#include <fstream>

static void Dev()
{
  string path = "Dev_Abdurahman.txt";
  ofstream dev(path);
  dev << "Github: 3bdurahman\n";
  dev << "Instagram: 3bdurahman.hashem\n";
  dev << "Futurs---------------------\n";
  dev << "1) Convert image to gray\n";
  dev << "2) dge detected Image\n";
  dev.close();
  path = "notepad.exe " + path;
  system(path.c_str());
}

static string read_Path()
{
  cout << "Enter image path: ";
  string path; getline(cin, path);
  return path;
}

Mat check_Path()
{
  string path = read_Path();
  if (imread(path).empty()) throw runtime_error("Invalid!, ");
  return imread(path);
}

void cmd() {
  cout << "[1] Convert image to gray\n";
  cout << "[2] Edge detection on gray image\n";
  cout << "[3] Show original image\n";
  cout << "[4] Show gray image\n";
  cout << "[5] Show edge-detected image\n";
  cout << "[6] Developer\n";
}

void choose(const int& sel, const Mat& original, Mat& gray, Mat& pixel) {
  switch (sel) {
  case 1:
    cvt(original, gray);
    system("CLS");
    clog << "Converted to gray.\n\n";
    break;
  case 2:
    threshold(gray, pixel);
    system("CLS");
    clog << "Edge detection completed.\n\n";
    break;
  case 3:
    showOriginal(original);
    system("CLS");
    break;
  case 4:
    showGray(gray);
    break;
  case 5:
    showPixel(pixel);
    break;
  case 6:
    Dev();
    break;
  default:
    throw runtime_error("Invalid selection! Try again.\n");
    break;
  }
}

static void cvt(const Mat& original, Mat& gray) 
{
  cvtColor(original, gray, COLOR_BGR2GRAY); 
  imwrite("gray.jpg", gray);
}

static void threshold(const Mat& gray, Mat& edgeDetected) 
{
  if (gray.empty()) throw runtime_error("First should convert original image to gray\n");
  Canny(gray, edgeDetected, 100, 200);
  imwrite("pixel.jpg", edgeDetected);
}

static void showOriginal(const Mat& img)
{
  imshow("Orginal image", img);
  waitKey(0);
}

static void showGray(const Mat& gray)
{
  if (gray.empty())
  {
    system("CLS");
    throw runtime_error("First should convert to gray\n\n");
    return;
  }
  imshow("Gray Image", gray);
  waitKey(0);
  system("CLS");
}

static void showPixel(const Mat& pixel) 
{
  if (pixel.empty())
  {
    system("CLS");
    throw runtime_error("First should pixel detection\n\n");
    return;
  }
  imshow("Edge-detected Image", pixel);
  waitKey(0);
  system("CLS");
}