#ifndef IMAGEFILTERS_H
#define IMAGEFILTERS_H

#include <opencv4/opencv2/core.hpp>
#include <vector>
#include <algorithm>

cv::Mat max_filter (const cv::Mat& src, const int& kernel_size);

cv::Mat min_filter (const cv::Mat& src, const int& kernel_size);

cv::Mat median_filter(const cv::Mat& src, const int& kernel_size);

#endif
