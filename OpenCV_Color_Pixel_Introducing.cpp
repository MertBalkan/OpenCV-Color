#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;


void CameraFunc() {
	VideoCapture cam(0);

	int height = cam.get(CV_CAP_PROP_FRAME_HEIGHT);
	int width = cam.get(CAP_PROP_FRAME_WIDTH);

	Size size(width, height);

	VideoWriter vidWrite("D:/OpenCvReferances/videos/myFirstOpenCvVid.avi", CV_FOURCC('M', 'P', '4', '2'), 20, size, true);


	while (true) {
		Mat frame;
		Mat outputFrame1;
		Mat outputFrame2;
		Mat outputFrame3;

		int x1, x2;

		string winName = "Cam";

		if (!(vidWrite.isOpened())) {
			cout << "There is no camera..." << endl;
			break;
		}
		if (waitKey(30) == 27) {
			vidWrite.release();
		}
		cam.read(frame);
		imshow(winName, frame);

		inRange(frame, Scalar(100, 10, 10), Scalar(200, 100, 100), outputFrame1); // for blue pixels
		inRange(frame, Scalar(10, 10, 100), Scalar(100, 100, 200), outputFrame2); // for red pixels
		inRange(frame, Scalar(0, 0, 0), Scalar(1, 1, 1), outputFrame3); // for black pixels

		imshow(winName,frame);
		imshow("Frame1",outputFrame1); //blue pixels showing
		imshow("Frame2",outputFrame2); // red pixels showing
		imshow("Frame3", outputFrame3); //dark pixels showing

		x1 = countNonZero(outputFrame1);
		x2 = countNonZero(outputFrame2);
		
		//Checking blue and red pixel counts
		if (x1 > x2) {
			cout << "It's a blueee" << endl;
		}
		else
		{
			cout << "It's a reddd" << endl;
		}
		
		//vidWrite.write(frame); //VideoWrite 
	}
}

int main(){
	CameraFunc();
	system("PAUSE");
	return 0;
}
