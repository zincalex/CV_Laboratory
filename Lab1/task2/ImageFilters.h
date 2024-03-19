#ifndef IMAGEFILTERS_H
#define IMAGEFILTERS_H

#include <opencv4/opencv2/core.hpp>
#include<vector>
#include<algorithm>

int max_filter (const cv::Mat& src, cv::Mat& out, const int& kernel_size);

int min_filter (const cv::Mat& src, cv::Mat& out, const int& kernel_size);

int median_filter(const cv::Mat& src, cv::Mat& out, const int& kernel_size);

#endif
