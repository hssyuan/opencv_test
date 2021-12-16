#include <iostream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
int main(){   
//上采样
	Mat srcImage = imread("1.jpg");  
	Mat dstImage;
  Mat downImage;
	Mat tmpImage = srcImage;					
	imshow("source", srcImage);
	//进行向上取样操作
	pyrUp(tmpImage, dstImage, Size(tmpImage.cols * 2, tmpImage.rows * 2));
	//显示效果图  
	imshow("up", dstImage);

pyrDown(srcImage,downImage,Size(srcImage.cols/2,srcImage.rows / 2));
imshow("down",downImage);
  waitKey(0);
  return 0;
  }

