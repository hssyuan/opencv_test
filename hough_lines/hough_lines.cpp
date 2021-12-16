#include <iostream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc/imgproc_c.h>

using namespace cv;
using namespace std;

int main(){
Mat dst, cdst,srco,src;
srco = imread("1.jpg");
blur( srco, src, Size(3,3) );
 Canny(src, dst, 50, 200, 3);
 cvtColor(dst, cdst, CV_GRAY2BGR);

 vector<Vec2f> lines;
HoughLines(dst, lines, 1, CV_PI/180, 200, 0, 0 );

for( size_t i = 0; i < lines.size(); i++ )
{
  float rho = lines[i][0], theta = lines[i][1];
  Point pt1, pt2;
  double a = cos(theta), b = sin(theta);
  double x0 = a*rho, y0 = b*rho;
  pt1.x = cvRound(x0 + 1000*(-b));
  pt1.y = cvRound(y0 + 1000*(a));
  pt2.x = cvRound(x0 - 1000*(-b));
  pt2.y = cvRound(y0 - 1000*(a));
  line( cdst, pt1, pt2, Scalar(0,0,255), 1, CV_AA);
}

imshow("source", src);
imshow("detected lines", cdst);

waitKey(0);

}
