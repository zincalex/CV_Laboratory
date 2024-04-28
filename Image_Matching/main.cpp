#include "filesystem"
#include "opencv4/opencv2/imgcodecs.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "iostream"
#include "include/FeatureMatchers.h"

int main(int argc, char** argv) {
    if (argc < 4) {
        std::cerr << "Error: provide all needed parameters" << std::endl;
        exit(1);
    }

    std::filesystem::path folderPath = std::filesystem::current_path();
    std::filesystem::path relativePath= folderPath/"Images";
    std::filesystem::path img1Path = relativePath/argv[1];
    std::filesystem::path img2Path = relativePath/argv[2];
    char analysis_type =  *argv[3];
    cv::Mat img1 = cv::imread(img1Path);
    cv::Mat img2 = cv::imread(img2Path);
    int k = 2;
    float ratio = 0.75;

    if(img1.empty() || img2.empty()) {
        std::cerr << "Error: couldn't find or open one of the images" << std::endl;
        exit(1);
    }

    infoFeatureMatch featureMatchDetect_output;
    switch (analysis_type) {
        case '0' :
            featureMatchDetect_output = FLANN_SIFT(img1, img2, k, ratio);
            std::cout << "FLANN feature matching with SIFT feature detection" << std::endl;
            break;
        case '1' :
            featureMatchDetect_output = FLANN_SURF(img1, img2, k, ratio);
            std::cout << "FLANN feature matching with SURF feature detection" << std::endl;
            break;
        case '2' :
            featureMatchDetect_output = BruteForce_KAZE(img1, img2, k, ratio);
            std::cout << "BruteForce feature matching with KAZE feature detection" << std::endl;
            break;
        case '3' :
            featureMatchDetect_output = BruteForce_ORB(img1, img2, k, ratio);
            std::cout << "BruteForce feature matching with ORB feature detection" << std::endl;
            break;
        default:
            featureMatchDetect_output = BruteForce_SIFT(img1, img2, k, ratio);
            std::cout << "BruteForce feature matching with SIFT feature detection" << std::endl;
    }

    // infoFeatureMatch = <keypoints img1, descriptor img1, keypoints img2, descriptor img2, img3 where feature are matched, # of good matches>
    cv::Mat img3 = std::get<4>(featureMatchDetect_output);
    unsigned long num_good_matches = std::get<5>(featureMatchDetect_output);

    std::cout << "Number of good matches detected : " << num_good_matches << std::endl;
    if (num_good_matches > 150)
        std::cout << "Same image" << std::endl;
    else if (40 < num_good_matches)
        std::cout << "Same image but with strong transformation" << std::endl;
    else
        std::cout << "Different content" << std::endl;

    namedWindow("test", cv::WINDOW_AUTOSIZE);
    imshow("test", img3);
    imwrite("wrongBFKAZE.jpg", img3);
    cv::waitKey(0);
    return 0;
}


