#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <filesystem>
#include "iostream"

using namespace cv;

int main(int argc, char** argv) { // Task 3

    // From task 1 the following values are the best for what is the purpose of task 3
    int lowThreshold = 75;
    int ratio = 109;
    int kernel_size = 5;
    const char* window_name = "Canny Edge Detector Image";

    Mat street, street_gray, canny_img;

    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    street = imread(pathImage);
    namedWindow(window_name, WINDOW_AUTOSIZE);

    cvtColor( street, street_gray, COLOR_BGR2GRAY );
    GaussianBlur(street_gray, canny_img, Size(kernel_size,kernel_size), 0);
    Canny( canny_img, canny_img, lowThreshold, lowThreshold*ratio, kernel_size );

    std::vector<Vec2f> llane;
    std::vector<Vec2f> rlane;
    HoughLines(canny_img, llane, 1, CV_PI/180, 128, 0, 0, 0, CV_PI / 3); // 128 to select stronger lines
    HoughLines(canny_img, rlane, 1, CV_PI/180, 128, 0, 0, -CV_PI / 3, 0);
    Vec2f lline = llane[0];
    Vec2f rline = rlane[0];
    float lrho = lline[0], ltheta = lline[1], rrho = rline[0], rtheta = rline[1];

    for(int y = 0; y < street.rows; y++) {
        for(int x = 0; x < street.cols; x++) { // Given the parameters in polar coordinate, the next formula allows me to work with cartesian coordinate
            if(y > lrho / sin(ltheta) - x / tan(ltheta) && y > rrho / sin(rtheta) - x / tan(rtheta))
                street.at<Vec3b>(y,x) = Vec3b(0,0,255);
        }
    }

    imshow( window_name, canny_img);
    waitKey(0);
    return 0;
}


