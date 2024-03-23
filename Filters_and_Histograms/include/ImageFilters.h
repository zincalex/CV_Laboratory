#ifndef IMAGEFILTERS_H
#define IMAGEFILTERS_H

#include <opencv4/opencv2/core.hpp>
#include <vector>
#include <algorithm>

/**
 * @brief 	Max filter is applied to the image
 * @param 	src  input image
 * @param 	kernel_size length of the side of a square kernel
 * @return  filtered image
 * @throw 	error if size is even or the number of channels of src differs from 1
 */
cv::Mat maxFilter (const cv::Mat& src, const int& kernel_size);


/**
 * @brief 	Min filter is applied to the image
 * @param 	src  input image
 * @param 	kernel_size length of the side of a square kernel
 * @return  filtered image
 * @throw 	error if size is even or the number of channels of src differs from 1
 */
cv::Mat minFilter (const cv::Mat& src, const int& kernel_size);


/**
 * @brief 	Median filter is applied to the image
 * @param 	src  input image
 * @param 	kernel_size length of the side of a square kernel
 * @return  filtered image
 * @throw 	error if size is even or the number of channels of src differs from 1
 */
cv::Mat medianFilter(const cv::Mat& src, const int& kernel_size);

#endif
