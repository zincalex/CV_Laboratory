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
    int kernel_size_Gauss = 5;
    const char* window_name = "Canny Edge Detector Image";

    Mat street, street_gray, canny_img;

    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    street = imread(pathImage);
    namedWindow(window_name, WINDOW_AUTOSIZE);

    GaussianBlur(street, street, Size(kernel_size_Gauss, kernel_size_Gauss), 0);
    cvtColor( street, street_gray, COLOR_BGR2GRAY );

    Mat grad_xy;
    Sobel(street_gray, grad_xy, CV_16S, 1, 1, 3);
    convertScaleAbs(grad_xy, grad_xy);
    for (int i = 0; i < grad_xy.rows; i++) {
        for (int j = 0; j < grad_xy.rows; j++) {
            if(grad_xy.at<unsigned char>(i,j) < 210) {
                grad_xy.at<unsigned char>(i,j) = 0;
            }
        }
    }
    imshow( window_name, grad_xy);
    waitKey(0);
    Sobel(street_gray, grad_xy, CV_16S, 0, 1, 3);
    convertScaleAbs(grad_xy, grad_xy);
    for (int i = 0; i < grad_xy.rows; i++) {
        for (int j = 0; j < grad_xy.rows; j++) {
            if(grad_xy.at<unsigned char>(i,j) < 210) {
                grad_xy.at<unsigned char>(i,j) = 0;
            }
        }
    }
    imshow( window_name, grad_xy);
    waitKey(0);
    Sobel(street_gray, grad_xy, CV_16S, 1, 0, 3);
    convertScaleAbs(grad_xy, grad_xy);
    for (int i = 0; i < grad_xy.rows; i++) {
        for (int j = 0; j < grad_xy.rows; j++) {
            if(grad_xy.at<unsigned char>(i,j) < 210) {
                grad_xy.at<unsigned char>(i,j) = 0;
            }
        }
    }
    imshow( window_name, grad_xy);
    waitKey(0);




    imshow( window_name, grad_xy);
    waitKey(0);
    return 0;
}


