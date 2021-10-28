#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat imgHSV, mask, imgColor;
int hMin = 0, sMin = 0, vMin = 0;
int hMax = 179, sMax = 255, vMax = 255;

VideoCapture cap(0);
Mat img;

int main()
{
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hMin, 179);
	createTrackbar("Hue Max", "Trackbars", &hMax, 179);
	createTrackbar("Sat Min", "Trackbars", &sMin, 255);
	createTrackbar("Sat Max", "Trackbars", &sMax, 255);
	createTrackbar("Val Min", "Trackbars", &vMin, 255);
	createTrackbar("Val Max", "Trackbars", &vMax, 255);

	while (1)
	{
		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);

		Scalar lower(hMin, sMin, vMin);
		Scalar upper(hMax, sMax, vMax);
		inRange(imgHSV, lower, upper, mask);

		cout << hMin << "," << sMin << "," << vMin << "," << hMax << "," << sMax << "," << vMax << endl;

		imshow("Image", img);
		imshow("Mask", mask);
		waitKey(1);
	}

	return 0;
}