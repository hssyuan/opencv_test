#include <iostream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

Mat &ScanImageAndReduceC(Mat &I, const uchar *const table) {
  // accept only char type matrices
  CV_Assert(I.depth() == CV_8U);
  int channels = I.channels();
  int nRows = I.rows;
  int nCols = I.cols * channels;
  if (I.isContinuous()) {
    nCols *= nRows;
    nRows = 1;
  }
  int i, j;
  uchar *p;
  for (i = 0; i < nRows; ++i) {
    p = I.ptr<uchar>(i);
    for (j = 0; j < nCols; ++j) {
      p[j] = table[p[j]];
      p[j] = 255 - p[j];
    }
  }
  return I;
}

int main() {
  Mat I = imread("1.jpg");

  int divideWith = 10; //量化分辨率
  uchar table[256];
  for (int i = 0; i < 256; ++i) {
    table[i] = (uchar)(divideWith * (i / divideWith));
  }
  ScanImageAndReduceC(I, table);
  imshow("111", I);
  waitKey(0);
  return 0;
}
