#include "ImageFilters.h"
#include "string"
#include "iostream"

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main(int argc, char** argv)
{
    if (argc < 2) return -1;
    std::string PATH = argv[1]; // path to Images folder

    // kernels size
    int KS_maxORmin = 5;
    int KS_median = 9;
    int KS_gauss = 13;

    Mat Lena_corr_img = imread(PATH + "/Lena_corrupted.png");
    Mat Astronaut_corr_img = imread(PATH + "/Astronaut_salt_pepper.png");
    Mat Garden_grayscale_img = imread(PATH + "/GardenModifiedGrayscale.jpg");

    cvtColor(Lena_corr_img, Lena_corr_img, COLOR_BGR2GRAY);
    cvtColor(Astronaut_corr_img, Astronaut_corr_img, COLOR_BGR2GRAY);
    cvtColor(Garden_grayscale_img, Garden_grayscale_img, COLOR_BGR2GRAY);

    // Task 2
    // Max or Min filter
    Mat Lena_modified = max_filter(Lena_corr_img, KS_maxORmin);
    Mat Astronaut_modified = max_filter(Astronaut_corr_img, KS_maxORmin);
    Mat Garden_modified = max_filter(Garden_grayscale_img, KS_maxORmin);
    // TODO adjust path to save images
    imwrite(PATH + "Lena_max_" + std::to_string(KS_maxORmin) + ".png", Lena_modified);
    imwrite(PATH + "Astronaut_max_" + std::to_string(KS_maxORmin) + ".png", Astronaut_modified);
    imwrite(PATH + "Garden_max_" + std::to_string(KS_maxORmin) + ".jpg", Garden_modified);


    // Task 3
    // Median filter
    Lena_modified = median_filter(Lena_corr_img, KS_median);
    Astronaut_modified = median_filter(Astronaut_corr_img, KS_median);
    Garden_modified = median_filter(Garden_grayscale_img, KS_median);

    imwrite(PATH + "Lena_median_" + std::to_string(KS_median) + ".png", Lena_modified);
    imwrite(PATH + "Astronaut_median_" + std::to_string(KS_median) + ".png", Astronaut_modified);
    imwrite(PATH + "Garden_median_" + std::to_string(KS_median) + ".jpg", Garden_modified);


    // Task 4
    // Gaussian smoothing
    GaussianBlur(Lena_corr_img, Lena_modified, Size(KS_gauss, KS_gauss), 0);
    GaussianBlur(Astronaut_corr_img, Astronaut_modified, Size(KS_gauss, KS_gauss), 0);
    GaussianBlur(Garden_grayscale_img, Garden_modified, Size(KS_gauss, KS_gauss), 0);

    imwrite(PATH + "Lena_gauss.png", Lena_modified);
    imwrite(PATH + "Astronaut_gauss.png", Astronaut_modified);
    imwrite(PATH + "Garden_gauss.jpg", Garden_modified);


    // Task 5
    /*
    MatND hist;
    int histSize = 256;
    float range[] = { 0, 256 };
    const float* histRange[] = { range };
    calcHist(&Garden_grayscale_img, 1, 0, Mat(), hist, 2, &histSize, histRange, true, false);
     */

    // Task 6

    return 0;
}
