#include "ImageFilters.h"
#include <iostream>

using namespace cv;

void max_filter (cv::Mat& src, cv::Mat& out, int& kernel_size) {
    if(kernel_size % 2 == 0) {
        std::cout << "The kernel must be odd sized" << std::endl;
        return -1;
    }

    if(src.channels() != 1 && out.channels() != 1) {
        std::cout << "This function works only for images with 1 channel" << std::endl;
        return -1;
    }


    for(int i = 0; i < src.rows; i += kernel_size) {
        for(int j = 0; j < src.cols; j += kern) {

            int max_pix = 0;
            int temp = 0;
            for(int x = i; x < kernel_size; x++) {
                for(int y = j; y < kernel_size; y++) {
                     temp = src.at<unsigned char> (x, y);
                     if(temp > max_pix)
                         max_pix = temp;
                }
            }

            for(int x = i; x < kernel_size; x++)
                for(int y = j; y < kernel_size; y++)
                    out.at<unsigned char> (x, y) = max_pix;


        }
    }
}

cv::Mat min_filter (cv::Mat& src, int kernel_size);
