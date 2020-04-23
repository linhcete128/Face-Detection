#include<iostream>
#include<cstdlib> //use stdlib.h for C language
#include<cstdio>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main() {
	CascadeClassifier faceDetection;
	//Load XML file, use "\\" in path because using Windows instead of Linux
	if (!faceDetection.load("D:\\OpenCV\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml")) {
		cout << "\n File is not loaded properly";
		exit(0); //stdlib.h
	}
	
	//If file is loaded properly, ask user for the image
	char path[100]; 
	cout << "\n Enter the path to image for face detection : ";
	cin.getline(path, 100);
	
	//Create matrix object
	Mat img = imread(path, IMREAD_UNCHANGED);
	//Check if image is loaded properly
	if (img.empty()) {
		cout << "\n Image is not loaded properly";
	}
	else {
		cout << "\n Image is found";
		cout << "\n Processing...";

		vector<Rect> faces; //create a vector object of rectangle for detecting faces
		faceDetection.detectMultiScale(img, faces); //detecting faces here
		
		for (int i = 0; i < faces.size(); i++) {
			Point pt1(faces[i].x, faces[i].y);	//create 1st point
			Point pt2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width)); //create 2nd point
			rectangle(img, pt1, pt2, Scalar(0,255,0), 2, 8, 0); //pass the image and draw rectangle, Scalar(Blue,Green,Red) is for the color of rectangle on face, thickness, linetype, shift			
		}
		imwrite("E:\\Software Development\\Face Detection C++\\Output\\output.jpg", img); //path to save
		cout << ("\n Face detected ok");
	}

	return 0;
}