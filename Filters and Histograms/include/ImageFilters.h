#ifndef IMAGEFILTERS_H
#define IMAGEFILTERS_H

#include <opencv4/opencv2/core.hpp>
#include <vector>
#include <algorithm>

cv::Mat maxFilter (const cv::Mat& src, const int& kernel_size);

cv::Mat minFilter (const cv::Mat& src, const int& kernel_size);

cv::Mat medianFilter(const cv::Mat& src, const int& kernel_size);

#endif
