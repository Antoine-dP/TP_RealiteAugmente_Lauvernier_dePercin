// TP_RA.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <opencv2/core/core.hpp>
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/calib3d.hpp"

#include <iostream>
#include <fstream>
#include <string>

#include "aruco/aruco.h"
#include "aruco/marker.h"
#include "aruco/markerdetector.h"
#include "aruco/markerdetector_impl.h"


#define ESC_KEY 27
#define SPACE_KEY 32



using namespace cv;
using namespace std;
using namespace aruco;

void PromptImageAndDisplayMarkers();
void PlayWebcamVideo();
Mat DisplayDetectedMarkers(Mat image);

VideoCapture cap;
char key;
Mat image;
Mat image_with_markers;

string imagePath;
Mat img;


int main(int argc, char* argv[])
{
	// Q3
	//PromptImageAndDisplayMarkers()
	
	// Cette fonction affiche la vidéo webcam et détecte les markers
	PlayWebcamVideo();
	//Dictionary dictionary = aruco::getPredefinedDictionary(aruco::DICT_6X6_250);




    return 1;
}

void PromptImageAndDisplayMarkers() {
	cout << "Image path : ";
	cin >> imagePath;

	img = imread(imagePath);

	if (!img.data) {
		cout << "Open Image Failed" << endl;
		return;
	}
	else {
		cout << "Open Image Successful" << endl;
	}

	MarkerDetector myDetector;

	for (auto m : myDetector.detect(img)) {
		cout << m << endl;
		m.draw(img);
	}

	string windowName = "Image";
	namedWindow(windowName, WINDOW_AUTOSIZE);

	while (true)
	{
		imshow(windowName, img);
		key = waitKey(10);
	}
}

void PlayWebcamVideo() {
	bool play = true;
	bool showMarkers = true;
	int camNum = 0;


	// Opening the video
	//cap.open("E:/Documents/TP/VSION/TP_Autoroute/TP_Autoroute/video.avi");


	cap.open(camNum);

	cout << "IsOpen No 2 : " << cap.isOpened() << endl;

	// Creating a window to display the images
	string windowName = "OpenCV Calibration";
	namedWindow(windowName, WINDOW_AUTOSIZE);

	while (play) {

		// Getting the new image from the camera
		cap >> image;

		if (showMarkers) {
			image_with_markers = DisplayDetectedMarkers(image);
			imshow(windowName, image_with_markers);
		}
		else {
			imshow(windowName, image);
		}

		// Showing the image in the window
		//imshow(windowName, image);

		key = waitKey(10);

		switch (key)
		{
		case 'Q':
		case 'q':
		case ESC_KEY:
			play = false;
			break;
		case 'M':
		case 'm':
			showMarkers = !showMarkers;
			break;
		default:
			break;
		}
	}


	// Destroying the windows
	destroyWindow(windowName);
	// Releasing the video capture
	cap.release();
}

Mat DisplayDetectedMarkers(Mat image) {

	MarkerDetector myDetector;

	for (auto m : myDetector.detect(image)) {
		cout << m << endl;
		m.draw(image);
	}
	return image;
}