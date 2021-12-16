#include <iostream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>

using namespace cv;
Mat src, src_gray;
  Mat dst, detected_edges;

  int edgeThresh = 1;
  int lowThreshold;
  int const max_lowThreshold = 100;
  int ratio = 3;    //高:低阈值比为 3:1
  int kernel_size = 3;



  int main(){
  src = imread("1.jpg" );
  dst.create(src.size(),src.type());
 cvtColor( src, src_gray, CV_BGR2GRAY ); 
  blur(src_gray,detected_edges,Size(3,3));
  Canny(detected_edges,detected_edges,30,30*ratio,kernel_size);
  dst = Scalar::all(0);
  src.copyTo(dst,detected_edges);
  imshow( "edge", dst );
 waitKey(0);
 return 0;
  }
