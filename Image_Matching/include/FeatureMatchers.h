#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

#ifndef FEATUREMATCHERS_H
#define FEATUREMATCHERS_H

/**
 * @brief   The method applies the Brute-Force matcher to evaluate feature in the two given images. To detect and describe the features
 *          the SIFT algorithm has been used. The method applies the ratio test to find the good matches.
 *
 * @param img1  first image
 * @param img2  second image
 * @param k     Count of best matches found per each query descriptor or less if a query descriptor has less than k possible matches in total
 * @param ratio maximum ratio between the distance of two keypoint descriptors in order be considered a good match
 *
 * @return a tuple with and image showing the matched good features and the number of good matches found
 */
std::tuple<cv::Mat, unsigned long> BruteForce_SIFT(const cv::Mat& img1, const cv::Mat& img2, const int& k, const float& ratio);

/**
 * @brief   The method applies the FLANN matcher to evaluate feature in the two given images. To detect and describe the features
 *          the SIFT algorithm has been used. The method applies the ratio test to find the good matches.
 *
 * @param img1  first image
 * @param img2  second image
 * @param k     Count of best matches found per each query descriptor or less if a query descriptor has less than k possible matches in total
 * @param ratio maximum ratio between the distance of two keypoint descriptors in order be considered a good match
 *
 * @return a tuple with and image showing the matched good features and the number of good matches found
 */
std::tuple<cv::Mat, unsigned long> FLANN_SIFT(const cv::Mat& img1, const cv::Mat& img2, const int& k, const float& ratio);

/**
 * @brief   The method applies the FLANN matcher to evaluate feature in the two given images. To detect and describe the features
 *          the SURF algorithm has been used. The method applies the ratio test to find the good matches.
 *
 * @param img1  first image
 * @param img2  second image
 * @param k     Count of best matches found per each query descriptor or less if a query descriptor has less than k possible matches in total
 * @param ratio maximum ratio between the distance of two keypoint descriptors in order be considered a good match
 *
 * @return a tuple with and image showing the matched good features and the number of good matches found
 */
std::tuple<cv::Mat, unsigned long> FLANN_SURF(const cv::Mat& img1, const cv::Mat& img2, const int& k, const float& ratio);


#endif

