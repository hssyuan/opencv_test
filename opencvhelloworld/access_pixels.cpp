#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>

using namespace cv;
int main() {
  Mat img = imread("1.jpg");

  Mat dst;                            // operate 3 channals img
  dst.create(img.size(), img.type()); // get width and height of the img
  int h = img.rows;
  int w = img.cols;
  int nc = img.channels(); // get img's channels

  int b = dst.at<Vec3b>(h, w)[0];
  dst.at<Vec3b>(h, w)[0] = 255 - b;

  int g = dst.at<Vec3b>(h, w)[1];
  dst.at<Vec3b>(h, w)[1] = 255 - g;

  int r = dst.at<Vec3b>(h, w)[2];
  dst.at<Vec3b>(h, w)[2] = 255 - r;

  imshow("111", img);
}
