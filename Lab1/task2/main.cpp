#include "ImageFilters.h"
#include "string"
#include "iostream"

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main(int argc, char** argv) {
    int KS_maxORmin = 3; // Kernel size
    int KS_median = 9;
    int KS_gauss = 13;
    std::string PATH = "/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/";

    Mat Lena_corr_img = imread(PATH + "Images/Lena_corrupted.png");
    Mat Astronaut_corr_img = imread(PATH + "Images/Astronaut_salt_pepper.png");
    Mat Garden_grayscale_img = imread(PATH + "Images/GardenModifiedGrayscale.jpg");

    cvtColor(Lena_corr_img, Lena_corr_img, COLOR_BGR2GRAY);
    cvtColor(Astronaut_corr_img, Astronaut_corr_img, COLOR_BGR2GRAY);
    cvtColor(Garden_grayscale_img, Garden_grayscale_img, COLOR_BGR2GRAY);

    Mat Lena_modified(Lena_corr_img.rows, Lena_corr_img.cols, CV_8U) ;
    Mat Astronaut_modified(Astronaut_corr_img.rows, Astronaut_corr_img.cols, CV_8U);
    Mat Garden_modified(Garden_grayscale_img.rows, Garden_grayscale_img.cols, CV_8U);

    // Max or Min filter
    if (min_filter(Lena_corr_img, Lena_modified, KS_maxORmin) != 0) return -1;
    if (max_filter(Astronaut_corr_img, Astronaut_modified, KS_maxORmin) != 0) return -1;
    if(max_filter(Garden_grayscale_img, Garden_modified, KS_maxORmin) != 0) return -1;

    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/Lena_min.jpg", Lena_modified);
    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/Astronaut_max.jpg", Astronaut_modified);
    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/GardenNoCables_max.jpg", Garden_modified);


    // Median filter
    if (median_filter(Lena_corr_img, Lena_modified, KS_median) != 0) return -1;
    if (median_filter(Astronaut_corr_img, Astronaut_modified, KS_median) != 0) return -1;
    if(median_filter(Garden_grayscale_img, Garden_modified, KS_median) != 0) return -1;

    namedWindow("Lena with median filter");
    imshow("Lena with median filter", Lena_modified);
    waitKey(0);
    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/Lena_median.jpg", Lena_modified);

    namedWindow("Astronaut with median filter");
    imshow("Astronaut with median filter", Astronaut_modified);
    waitKey(0);
    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/Astronaut_median.jpg", Astronaut_modified);

    namedWindow("Garden no eletric cables median filter");
    imshow("Garden no eletric cables median filter", Garden_modified);
    waitKey(0);
    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/GardenNoCables_median.jpg", Garden_modified);


    // Gaussian smoothing
    GaussianBlur(Lena_corr_img, Lena_modified, Size(KS_gauss, KS_gauss), 0);
    GaussianBlur(Astronaut_corr_img, Astronaut_modified, Size(KS_gauss, KS_gauss), 0);
    GaussianBlur(Garden_grayscale_img, Garden_modified, Size(KS_gauss, KS_gauss), 0);

    namedWindow("Lena with gauss filter");
    imshow("Lena with gauss filter", Lena_modified);
    waitKey(0);
    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/Lena_gauss.jpg", Lena_modified);

    namedWindow("Astronaut with gauss filter");
    imshow("Astronaut with gauss filter", Astronaut_modified);
    waitKey(0);
    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/Astronaut_gauss.jpg", Astronaut_modified);

    namedWindow("Garden no eletric cables gauss filter");
    imshow("Garden no eletric cables gauss filter", Garden_modified);
    waitKey(0);
    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/GardenNoCables_gauss.jpg", Garden_modified);

    /*
    MatND hist;
    int histSize = 256;
    float range[] = { 0, 256 };
    const float* histRange[] = { range };
    calcHist(&Garden_grayscale_img, 1, 0, Mat(), hist, 2, &histSize, histRange, true, false);
     */

    return 0;
}
