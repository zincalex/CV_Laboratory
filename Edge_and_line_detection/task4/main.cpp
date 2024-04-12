#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <filesystem>

using namespace cv;

int main(int argc, char** argv) { // Task 3
    Mat street, street_gray;
    int kernel_size_Gauss = 9;
    const char* window_name = "Hough Circle Detector";

    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    street = imread(pathImage);
    namedWindow(window_name, WINDOW_AUTOSIZE);

    cvtColor( street, street_gray, COLOR_BGR2GRAY );
    GaussianBlur(street_gray, street_gray, Size(kernel_size_Gauss,kernel_size_Gauss), 0);

    std::vector<Vec3f> circles;
    HoughCircles(street_gray, circles, HOUGH_GRADIENT_ALT, 1.5, 5,200, 0.9);
    for(int i = 0; i < circles.size(); i++ ) {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);

        // draw the circle
        circle( street, center, radius, Scalar(0,255,0), FILLED, 8, 0 );
    }

    imshow( window_name, street);
    waitKey(0);
    return 0;
}


