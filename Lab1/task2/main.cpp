#include "ImageFilters.h"
#include "string"

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main(int argc, char** argv) {
    Mat Lena_corr_img = imread("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/Images/Lena_corrupted.png");
    Mat Astronaut_corr_img = imread("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/Images/Astronaut_salt_pepper.png");
    Mat Garden_grayscale_img = imread("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task1/GardenModifiedGrayscale.jpg");

    cvtColor(Lena_corr_img, Lena_corr_img, COLOR_BGR2GRAY);
    cvtColor(Astronaut_corr_img, Astronaut_corr_img, COLOR_BGR2GRAY);
    cvtColor(Garden_grayscale_img, Garden_grayscale_img, COLOR_BGR2GRAY);

    int KS = 3; // Kernel size

    Mat Lena_modified;
    Mat Astronaut_modified;
    Mat Garden_modified;

    // Max or Min filter
    if (max_filter(Lena_corr_img, Lena_modified, KS) != 0) return -1;
    if (max_filter(Astronaut_corr_img, Astronaut_modified, KS) != 0) return -1;
    if(max_filter(Garden_grayscale_img, Garden_modified, KS) != 0) return -1;

    namedWindow("Lena with max/min filter");
    imshow("Lena with max/min filter", Lena_modified);
    waitKey(0);
    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/Lena_maxmin.jpg", Lena_modified);

    namedWindow("Astronaut with max/min filter");
    imshow("Astronaut with max/min filter", Astronaut_modified);
    waitKey(0);
    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/Astronaut_maxmin.jpg", Astronaut_modified);

    namedWindow("Garden no eletric cables max/min filter");
    imshow("Garden no eletric cables max/min filter", Garden_modified);
    waitKey(0);
    imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Lab1/task2/GardenNoCables_maxmin.jpg", Garden_modified);

    // Median filter
    if (median_filter(Lena_corr_img, Lena_modified, KS) != 0) return -1;
    if (median_filter(Astronaut_corr_img, Astronaut_modified, KS) != 0) return -1;
    if(median_filter(Garden_grayscale_img, Garden_modified, KS) != 0) return -1;

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
    GaussianBlur(Lena_corr_img, Lena_modified, Size(KS, KS), 0);
    GaussianBlur(Astronaut_corr_img, Astronaut_modified, Size(KS, KS), 0);
    GaussianBlur(Garden_grayscale_img, Garden_modified, Size(KS, KS), 0);

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


    MatND hist;
    int histSize = 256;
    float range[] = { 0, 256 };
    const float* histRange[] = { range };
    calcHist(&Garden_grayscale_img, 1, 0, Mat(), hist, 2, &histSize, histRange, true, false);

    return 0;
}
