#include "../include/FeatureMatchers.h"

std::tuple<cv::Mat, unsigned long> BruteForce_SIFT(const cv::Mat& img1, const cv::Mat& img2, const int& k, const float& ratio) {
    cv::Mat img1_gray, img2_gray;
    cv::Mat des1, des2; // Descriptors
    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();
    std::vector<cv::KeyPoint> kp1, kp2; // Keypoints

    cv::cvtColor(img1, img1_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(img2, img2_gray, cv::COLOR_BGR2GRAY);

    // Feature Detection and Description
    sift->detectAndCompute(img1_gray, cv::noArray(), kp1, des1);
    sift->detectAndCompute(img2_gray, cv::noArray(), kp2, des2);
    // std::cout << des1.size << std::endl;     We have 2674 features described by 128 values

    // Feature Matching
    cv::BFMatcher bf = cv::BFMatcher();
    std::vector<std::vector<cv::DMatch>> matches;
    bf.knnMatch(des1,des2, matches, k);

    std::vector<cv::DMatch> good_matches;
    for(const std::vector<cv::DMatch> &match: matches) {
        if (match[0].distance <  ratio * match[1].distance)
            good_matches.insert(good_matches.end(), match[0]);
    }
    unsigned long num_good_matches = good_matches.size();

    cv::Mat img3;
    cv::drawMatches(img1, kp1, img2, kp2, good_matches, img3, cv::Scalar::all(-1), cv::Scalar::all(-1), std::vector<char>(), cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

    return std::make_tuple(img3, num_good_matches);
}



std::tuple<cv::Mat, unsigned long> FLANN_SURF(const cv::Mat& img1, const cv::Mat& img2, const int& k, const float& ratio) {
    cv::Mat img1_gray, img2_gray;
    cv::Mat des1, des2; // Descriptors
    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();
    std::vector<cv::KeyPoint> kp1, kp2; // Keypoints

    cv::cvtColor(img1, img1_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(img2, img2_gray, cv::COLOR_BGR2GRAY);

    // SURF
    int minHessian = 400;
    cv::Ptr<cv::xfeatures2d::SURF> detector = cv::xfeatures2d::SURF::create(minHessian);
    detector->detectAndCompute(img1_gray, cv::noArray(), kp1, des1);
    detector->detectAndCompute(img2_gray, cv::noArray(), kp2, des2);

    //FLANN parameter
    cv::FlannBasedMatcher flann;
    std::vector<std::vector<cv::DMatch>> matches;
    flann.knnMatch(des1, des2, matches, k);

    std::vector<cv::DMatch> good_matches;
    for(const std::vector<cv::DMatch> &match: matches) {
        if (match[0].distance <  ratio * match[1].distance)
            good_matches.insert(good_matches.end(), match[0]);
    }
    unsigned long num_good_matches = good_matches.size();

    cv::Mat img3;
    cv::drawMatches(img1, kp1, img2, kp2, good_matches, img3, cv::Scalar::all(-1), cv::Scalar::all(-1), std::vector<char>(), cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

    return std::make_tuple(img3, num_good_matches);
}



std::tuple<cv::Mat, unsigned long> FLANN_SIFT(const cv::Mat& img1, const cv::Mat& img2, const int& k, const float& ratio) {
    cv::Mat img1_gray, img2_gray;
    cv::Mat des1, des2; // Descriptors
    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();
    std::vector<cv::KeyPoint> kp1, kp2; // Keypoints

    cv::cvtColor(img1, img1_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(img2, img2_gray, cv::COLOR_BGR2GRAY);

    // Feature Detection and Description
    sift->detectAndCompute(img1_gray, cv::noArray(), kp1, des1);
    sift->detectAndCompute(img2_gray, cv::noArray(), kp2, des2);

    //FLANN parameter
    cv::FlannBasedMatcher flann;
    std::vector<std::vector<cv::DMatch>> matches;
    flann.knnMatch(des1, des2, matches, k);


    std::vector<cv::DMatch> good_matches;
    for(const std::vector<cv::DMatch> &match: matches) {
        if (match[0].distance <  ratio * match[1].distance)
            good_matches.insert(good_matches.end(), match[0]);
    }
    unsigned long num_good_matches = good_matches.size();

    cv::Mat img3;
    cv::drawMatches(img1, kp1, img2, kp2, good_matches, img3, cv::Scalar::all(-1), cv::Scalar::all(-1), std::vector<char>(), cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

    return std::make_tuple(img3, num_good_matches);
}



