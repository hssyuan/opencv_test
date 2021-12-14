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

  vector<Mat> rgb(3);
  split(I, rgb);

  Mat blank, r_merged, g_merged, b_merged, gb_merged;
  blank = Mat::zeros(Size(I.cols, I.rows), CV_8UC1);

  vector<Mat> rchannel;
  rchannel.push_back(blank);
  rchannel.push_back(blank);
  rchannel.push_back(rgb[2]);
  merge(rchannel, r_merged);
  imshow("R channel", r_merged);

  vector<Mat> gchannel;
  gchannel.push_back(blank);
  gchannel.push_back(rgb[1]);
  gchannel.push_back(blank);
  merge(gchannel, g_merged);
  imshow("G channel", g_merged);

  vector<Mat> bchannel;
  bchannel.push_back(rgb[0]);
  bchannel.push_back(blank);
  bchannel.push_back(blank);
  merge(bchannel, b_merged);
  imshow("B channel", b_merged);

  vector<Mat> gbchannel;
  gbchannel.push_back(rgb[0]);
  gbchannel.push_back(rgb[1]);
  gbchannel.push_back(blank);
  merge(gbchannel, gb_merged);
  imshow("G&B channel", gb_merged);

  waitKey(0);
  return 0;
}
