#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <filesystem>

int main(int argc, char** argv) {
    if (argc < 3) return -1;

    std::filesystem::path folderPath = std::filesystem::current_path();
    std::filesystem::path relativePath= folderPath/"Images";
    std::filesystem::path img1Path = relativePath/argv[1];
    std::filesystem::path img2Path = relativePath/argv[2];

    cv::Mat img1 = cv::imread(img1Path);
    cv::Mat img2 = cv::imread(img2Path);
    cv::Mat img1_gray, img2_gray;
    cv::cvtColor(img1, img1_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(img2, img2_gray, cv::COLOR_BGR2GRAY);

    //if(img1 == NULL || img2 == NULL)
    //  throw std::mis

    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();
    std::vector<cv::KeyPoint> kp1, kp2;
    cv::Mat des1, des2;
    sift->detectAndCompute(img1_gray, cv::noArray(), kp1, des1);
    sift->detectAndCompute(img2_gray, cv::noArray(), kp2, des2);

    cv::BFMatcher bf = cv::BFMatcher();

    std::vector<std::vector<cv::DMatch>> matches;
    int k = 2;
    bf.knnMatch(des1,des2, matches, k);

    namedWindow("test", cv::WINDOW_AUTOSIZE);
    imshow("test", img1);
    cv::waitKey(0);
    return 0;
}


