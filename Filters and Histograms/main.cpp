#include "include/ImageFilters.h"
#include "string"
#include "iostream"

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace cv;

int main(int argc, char** argv)
{
    if (argc < 2) return -1;
    std::string PATH = argv[1]; // path to Images folder

    // Task 1
    //
    Mat Garden_grayscale = imread(PATH + "/Garden_Grayscale.jpg");
    cvtColor(Garden_grayscale, Garden_grayscale, COLOR_BGR2GRAY);
    namedWindow("Garden grayscale");
    imshow("Garden grayscale", Garden_grayscale);
    waitKey(0);

    // Task 2
    // Max or Min filter
    int KS_maxORmin = 3;
    int KS_median = 7;
    int KS_gauss = 3;

    Mat Lena_corr_img = imread(PATH + "/Lena_corrupted.png");
    Mat Astronaut_corr_img = imread(PATH + "/Astronaut_salt_pepper.png");
    cvtColor(Lena_corr_img, Lena_corr_img, COLOR_BGR2GRAY);
    cvtColor(Astronaut_corr_img, Astronaut_corr_img, COLOR_BGR2GRAY);

    Mat Lena_modified = maxFilter(Lena_corr_img, KS_maxORmin);
    Mat Astronaut_modified = maxFilter(Astronaut_corr_img, KS_maxORmin);
    Mat Garden_modified = maxFilter(Garden_grayscale, KS_maxORmin);

    imwrite(PATH + "/Lena_max_" + std::to_string(KS_maxORmin) + ".png", Lena_modified);
    imwrite(PATH + "/Astronaut_max_" + std::to_string(KS_maxORmin) + ".png", Astronaut_modified);
    imwrite(PATH + "/Garden_max_" + std::to_string(KS_maxORmin) + ".jpg", Garden_modified);


    // Task 3
    // Median filter
    Lena_modified = medianFilter(Lena_corr_img, KS_median);
    Astronaut_modified = medianFilter(Astronaut_corr_img, KS_median);
    Garden_modified = medianFilter(Garden_grayscale, KS_median);

    imwrite(PATH + "/Lena_median_" + std::to_string(KS_median) + ".png", Lena_modified);
    imwrite(PATH + "/Astronaut_median_" + std::to_string(KS_median) + ".png", Astronaut_modified);
    imwrite(PATH + "/Garden_median_" + std::to_string(KS_median) + ".jpg", Garden_modified);


    // Task 4
    // Gaussian smoothing
    GaussianBlur(Lena_corr_img, Lena_modified, Size(KS_gauss, KS_gauss), 0);
    GaussianBlur(Astronaut_corr_img, Astronaut_modified, Size(KS_gauss, KS_gauss), 0);
    GaussianBlur(Garden_grayscale, Garden_modified, Size(KS_gauss, KS_gauss), 0);

    imwrite(PATH + "/Lena_gauss_" + std::to_string(KS_gauss) + ".png", Lena_modified);
    imwrite(PATH + "/Astronaut_gauss_" + std::to_string(KS_gauss) + ".png", Astronaut_modified);
    imwrite(PATH + "/Garden_gauss_" + std::to_string(KS_gauss) + ".jpg", Garden_modified);


    // Task 5
    // Histogram
    Mat hist;
    int histSize = 256;
    float range[] = {0, 256};
    const float* histRange[] = {range};
    calcHist(&Garden_grayscale, 1, 0, Mat(), hist, 1, &histSize, histRange, true, false);
    int hist_width = 1024;
    int hist_height = 800;
    int bin_w = cvRound((double) hist_width / histSize);
    Mat hist_img(hist_height, hist_width, CV_8UC3, Scalar(0,0,0));
    normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX, -1, Mat());
    for(int i = 1; i < histSize; i++)
        line(hist_img, Point(bin_w * (i - 1), hist_height - cvRound(hist.at<float>(i - 1))), Point(bin_w * (i), hist_height - cvRound(hist.at<float>(i))), Scalar(255, 255, 255), 1, LINE_AA, 0);

    namedWindow("histogram garden");
    imshow("histogram garden", hist_img);
    waitKey(0);
    imwrite(PATH + "/histogram.jpg", hist_img);


    // Task 6
    // Histogram equalization
    Mat	GardenImg_equalized;
    equalizeHist(Garden_grayscale, GardenImg_equalized);
    namedWindow("Garden image equalized");
    imshow("Garden image equalized", GardenImg_equalized);
    waitKey(0);
    imwrite(PATH + "/GardenImg_equalized.jpg", GardenImg_equalized);

    Mat hist_equalized;
    Mat histImage_equalized(hist_height, hist_width, CV_8UC3, cv::Scalar(0, 0, 0));
    calcHist(&GardenImg_equalized, 1, 0, cv::Mat(), hist_equalized, 1, &histSize, histRange, true, false);
    normalize(hist_equalized, hist_equalized, 0, histImage_equalized.rows, NORM_MINMAX, -1, Mat());
    for (int i = 1; i < histSize; i++)
        line(histImage_equalized, Point(bin_w * (i - 1), hist_height - cvRound(hist_equalized.at<float>(i - 1))), Point(bin_w * (i), hist_height - cvRound(hist_equalized.at<float>(i))), Scalar(255, 255, 255), 1, LINE_AA, 0);

    namedWindow("histogram equalized");
    imshow("histogram equalized", histImage_equalized);
    waitKey(0);
    imwrite(PATH + "/histogram_equalized.jpg", histImage_equalized);

    return 0;
}
