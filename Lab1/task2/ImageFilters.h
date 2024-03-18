#ifndef IMAGEFILTERS_H
#define IMAGEFILTERS_H

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/core.hpp>

void max_filter (cv::Mat& src, cv::Mat& out, int& kernel_size);

cv::Mat min_filter (cv::Mat& src, int kernel_size);

#endif
