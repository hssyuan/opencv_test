#include <iostream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
int main( )
{
	Mat src = imread("1.jpg");
	imshow("source",src);
	Rect ccomp;
	floodFill(src, Point(50,300), Scalar(155, 255,55), &ccomp, Scalar(20, 20, 20),Scalar(20, 20, 20));
	imshow("processed",src);
	waitKey(0);
	return 0;
}
