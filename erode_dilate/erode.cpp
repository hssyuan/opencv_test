#include <iostream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
Mat erosion_dst;
Mat dilation_dst;
Mat src = imread("1.jpg");

void Erosion( int, void* )
{
  int erosion_type = 0;
  Mat element = getStructuringElement( erosion_type,
                       Size( 2*10 + 1, 2*10+1 ),
                       Point( 10, 10 ) );
  erode( src, erosion_dst,element);
  imshow( "Erosion Demo", erosion_dst);
}

void Dilation( int, void* )
{
  int dilation_type;
  Mat element = getStructuringElement( dilation_type,
                                       Size( 20 + 1, 20+1 ),
                                       Point( 10, 10 ) );
  /// 膨胀操作
  dilate( src, dilation_dst, element );
  imshow( "Dilation Demo", dilation_dst );
}

int main(){
  Erosion(0,0);
  Dilation(0,0);
  imshow("111", src);
  waitKey(0);
  return 0;
}
