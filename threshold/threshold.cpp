#include <iostream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
Mat dst;
Mat src = imread("1.jpg");
int max_BINARY_value = 255;
void Thresh( int, void* )
{
  /* 0: 二进制阈值
     1: 反二进制阈值
     2: 截断阈值
     3: 0阈值
     4: 反0阈值
   */

  threshold( src, dst,155, max_BINARY_value,3);

  imshow("threshold", dst );
}

int main(){
  imshow("111", src);
  Thresh(0,0);
  waitKey(0);
  return 0;
}
