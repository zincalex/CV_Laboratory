#include "ImageFilters.h"
#include "string"

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char** argv) {

    Mat Lena_corr_img = imread("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/Images/Lena_corrupted.png");
    Mat Astronaut_corr_img = imread("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/Images/Astronaut_salt_pepper.png");

    cvtColor(Lena_corr_img, Lena_corr_img, COLOR_BGR2GRAY);
    cvtColor(Astronaut_corr_img, Astronaut_corr_img, COLOR_BGR2GRAY);

    int kernel_size = 5;


    if (max_filter(Lena_corr_img, Lena_corr_img, kernel_size) != 0)
        return -1;

    if (max_filter(Astronaut_corr_img, Astronaut_corr_img, kernel_size) != 0)
        return -1;

    namedWindow("Lena corrupted image with kernel size " + std::to_string(kernel_size));
    imshow("Lena corrupted image with kernel size " + std::to_string(kernel_size), Lena_corr_img);
    waitKey(0);

   imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task1/Lena.jpg", Lena_corr_img);

    namedWindow("Astronaut revamped image with kernel size " + std::to_string(kernel_size));
    imshow("Astronaut revamped image with kernel size " + std::to_string(kernel_size), Astronaut_corr_img);
    waitKey(0);


    return 0;
}
