#ifndef FEATUREMATCHERS_H
#define FEATUREMATCHERS_H

#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

typedef std::tuple<std::vector<cv::KeyPoint>, cv::Mat, std::vector<cv::KeyPoint>, cv::Mat, cv::Mat, unsigned long> infoFeatureMatch;

/**
* @brief   The method applies the Brute-Force matcher to evaluate feature in the two given images. To detect and describe the features
*          the SIFT algorithm has been used. The method applies the ratio test to find the good matches.
*
* @param img1  first image
* @param img2  second image
* @param k     Count of best matches found per each query descriptor or less if a query descriptor has less than k possible matches in total
* @param ratio maximum ratio between the distance of two keypoint descriptors in order be considered a good match
*
* @return a tuple with the keypoints and descriptors of each image given and image showing good features matched with the number of good matches found
*/
infoFeatureMatch BruteForce_SIFT(const cv::Mat& img1, const cv::Mat& img2, const int& k, const float& ratio);


/**
* @brief   The method applies the Brute-Force matcher to evaluate feature in the two given images. To detect and describe the features
*          the ORB algorithm has been used. The method applies the ratio test to find the good matches.
*
* @param img1  first image
* @param img2  second image
* @param k     Count of best matches found per each query descriptor or less if a query descriptor has less than k possible matches in total
* @param ratio maximum ratio between the distance of two keypoint descriptors in order be considered a good match
*
* @return a tuple with the keypoints and descriptors of each image given and image showing good features matched with the number of good matches found
*/
infoFeatureMatch BruteForce_ORB(const cv::Mat& img1, const cv::Mat& img2, const int& k, const float& ratio);


/**
* @brief   The method applies the Brute-Force matcher to evaluate feature in the two given images. To detect and describe the features
*          the KAZE algorithm has been used. The method applies the ratio test to find the good matches.
*
* @param img1  first image
* @param img2  second image
* @param k     Count of best matches found per each query descriptor or less if a query descriptor has less than k possible matches in total
* @param ratio maximum ratio between the distance of two keypoint descriptors in order be considered a good match
*
* @return a tuple with the keypoints and descriptors of each image given and image showing good features matched with the number of good matches found
*/
infoFeatureMatch BruteForce_KAZE(const cv::Mat& img1, const cv::Mat& img2, const int& k, const float& ratio);



/**
* @brief   The method applies the FLANN matcher to evaluate feature in the two given images. To detect and describe the features
*          the SIFT algorithm has been used. The method applies the ratio test to find the good matches.
*
* @param img1  first image
* @param img2  second image
* @param k     Count of best matches found per each query descriptor or less if a query descriptor has less than k possible matches in total
* @param ratio maximum ratio between the distance of two keypoint descriptors in order be considered a good match
*
* @return a tuple with the keypoints and descriptors of each image given and image showing good features matched with the number of good matches found
*/
infoFeatureMatch FLANN_SIFT(const cv::Mat& img1, const cv::Mat& img2, const int& k, const float& ratio);


/**
* @brief   The method applies the FLANN matcher to evaluate feature in the two given images. To detect and describe the features
*          the SURF algorithm has been used. The method applies the ratio test to find the good matches.
*
* @param img1  first image
* @param img2  second image
* @param k     Count of best matches found per each query descriptor or less if a query descriptor has less than k possible matches in total
* @param ratio maximum ratio between the distance of two keypoint descriptors in order be considered a good match
*
* @return a tuple with the keypoints and descriptors of each image given and image showing good features matched with the number of good matches found
*/
infoFeatureMatch FLANN_SURF(const cv::Mat& img1, const cv::Mat& img2, const int& k, const float& ratio);

#endif

