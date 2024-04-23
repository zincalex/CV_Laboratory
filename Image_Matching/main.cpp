#include "filesystem"
#include "opencv4/opencv2/imgcodecs.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "iostream"
#include "include/FeatureMatchers.h"


int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Error: need to provide 2 image names" << std::endl;
        exit(1);
    }

    std::filesystem::path folderPath = std::filesystem::current_path();
    std::filesystem::path relativePath= folderPath/"Images";
    std::filesystem::path img1Path = relativePath/argv[1];
    std::filesystem::path img2Path = relativePath/argv[2];

    cv::Mat img1 = cv::imread(img1Path);
    cv::Mat img2 = cv::imread(img2Path);
    int k = 2;
    float ratio = 0.75;

    if(img1.empty() || img2.empty()) {
        std::cerr << "Error: couldn't find or open one of the images" << std::endl;
        exit(1);
    }

    std::tuple<cv::Mat, unsigned long> Brute_SIFT_output = FLANN_SURF(img1, img2, k, ratio);
    cv::Mat img3 = std::get<0>(Brute_SIFT_output);
    unsigned long num_good_matches = std::get<1>(Brute_SIFT_output);

    std::cout << num_good_matches << std::endl;
    if (num_good_matches > 150)
        std::cout << "Same image" << std::endl;
    else if (20 < num_good_matches)
        std::cout << "Same image but with strong transformation" << std::endl;
    else
        std::cout << "Different content" << std::endl;

    namedWindow("test", cv::WINDOW_AUTOSIZE);
    imshow("test", img3);
    cv::waitKey(0);
    return 0;
}


