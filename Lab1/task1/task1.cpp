#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/core.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv) {

    Mat garden_img = imread("/home/zincalex/University/Computer Vision Laboratory/Lab1/Images/Garden.jpg");
    cvtColor(garden_img, garden_img, COLOR_BGR2GRAY);

    namedWindow("Garden image grayscale");
    imshow("Garden image grayscale", garden_img);
    waitKey(0);

    // writing the image to a defined location as JPEG
    bool check = imwrite("/home/zincalex/University/Computer Vision Laboratory/Lab1/task1/GardenModifiedGrayscale.jpg", garden_img);

    // if the image is not saved
    if (!check) {
        std::cout << "Mission - Saving the image, FAILED" << std::endl;
        // wait for any key to be pressed
        std::cin.get();
        return -1;
    }

    std::cout << "Successfully saved the image. " << std::endl;

    return 0;
}