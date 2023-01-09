// TP_RA.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

#include "aruco/aruco.h"
#include "aruco/marker.h"
#include "aruco/markerdetector.h"
#include "aruco/markerdetector_impl.h"

using namespace cv;
using namespace std;
using namespace aruco;

string imagePath;
Mat img;
_ARUCO_MarkerDetector_H

int main(int argc, char* argv[])
{
    cout << "Image path : ";
    cin >> imagePath;

    img = imread(imagePath);

    if (!img.data) {
        cout << "Open Image Failed" << endl;
        return 0;
    }
    else {
        cout << "Open Image Successful" << endl;
    }
    
    MarkerDetector myDetector;

    for (auto m : myDetector.detect(img)) {
        cout << m << endl;
        m.draw(img);
    }

    








    return 1;
}
