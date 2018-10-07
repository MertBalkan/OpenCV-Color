//This program created by Mert Balkan
//06.10.2018
//Support me on github!
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;


void Trigonometry() {
	Mat im(720, 720, CV_8UC3, Scalar(150, 150, 150));
	Mat imCopy = im.clone();
	string winName = "Win";

	int imRows = im.rows;
	int imCols = im.cols;

	for (int i = 0; i <= 1801; i++) {
		cout << "Cosinus:" << -cos(i*M_PI / 180) << endl;
		cout << "Sinus:" << sin(i*M_PI / 180) << endl;
		cout << "Tanjant:" << sin(i*M_PI / 180) / cos(i*M_PI / 180) << endl;
		cout << "Cotanjant:" << -cos(i*M_PI / 180) / sin(i*M_PI / 180) << endl;
		
		circle(imCopy, Point(imCols / 2, imRows / 2), 150, Scalar(0, 255, 255), 2);
		line(imCopy, Point(imCols / 2, imRows / 2), Point(imCols / 2 - 150 * cos(i*M_PI / 180), imRows / 2 - 150 * sin(i*M_PI/180)), Scalar(255, 0, 0), 4);
		
		line(imCopy, Point(imCols / 2, imRows / 2), Point(imCols / 2 - 150 * cos(i*M_PI / 180), imRows / 2 ), Scalar(0, 0, 255), 4); // cosinus 
		line(imCopy, Point(imCols / 2, imRows / 2), Point(imCols / 2, imRows / 2 - 150 * sin(i*M_PI / 180)), Scalar(0, 255, 0), 4); //sinus 
		line(imCopy, Point(imCols / 2 - 150, imRows / 2 + 500), Point(210, 0), Scalar(0, 0, 0), 4); //tanjant
		line(imCopy, Point(imCols / 2 + 500, imRows / 2 - 150), Point(0, 210), Scalar(50, 50, 50), 4); //cotanjant
		
		cout << "-------------------------------------------------------" << endl;
		imshow(winName, imCopy);
		waitKey(30);
		im.copyTo(imCopy);
	}
}

int main(){
	Trigonometry();
	waitKey(0);
	destroyAllWindows(); 
	return 0;
}
