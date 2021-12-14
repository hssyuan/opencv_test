#include <iostream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
  Mat I = imread("1.jpg");
  if (I.empty()) {
    cout << "NO IMAGE" << endl;
    return -1;
  }

  line(I, Point(283, 173), Point(334, 206), Scalar(0, 0, 255), 5, 8, 0);
  line(I, Point(334, 206), Point(330, 276), Scalar(54, 114, 235), 5, 8, 0);
  line(I, Point(330, 276), Point(265, 319), Scalar(114, 51, 4), 5, 8, 0);
  line(I, Point(265, 319), Point(230, 291), Scalar(23, 34, 66), 5, 8, 0);
  line(I, Point(230, 291), Point(221, 242), Scalar(77, 23, 23), 5, 8, 0);
  line(I, Point(221, 242), Point(283, 173), Scalar(77, 23, 23), 5, 8, 0);

  line(I, Point(269, 317), Point(301, 673), Scalar(0, 47, 167), 5, 8, 0);
  line(I, Point(269, 317), Point(167, 493), Scalar(167, 0, 47), 5, 8, 0);
  line(I, Point(167, 493), Point(172, 632), Scalar(77, 23, 23), 5, 8, 0);
  line(I, Point(269, 317), Point(423, 437), Scalar(47, 167, 20), 5, 8, 0);
  line(I, Point(423, 437), Point(305, 429), Scalar(47, 0, 167), 5, 8, 0);
  imshow("111", I);
  waitKey(0);
  return 0;
}
