#include "ImageFilters.h"
#include <iostream>

int max_filter (const cv::Mat& src, cv::Mat& out, const int& kernel_size) {
    // Controls
    if(kernel_size % 2 == 0) {
        std::cout << "The kernel must be odd sized" << std::endl;
        return -1;
    }
    if(src.channels() != 1 && out.channels() != 1) {
        std::cout << "This function works only for images with 1 channel" << std::endl;
        return -1;
    }

    // Filter
    for(int i = 0; i < src.rows; i += kernel_size) {
        for(int j = 0; j < src.cols; j += kernel_size) {

            int max_value_block = 0;
            int temp;
            for(int x = 0; x < kernel_size; x++) {
                for(int y = 0; y < kernel_size; y++) {

                    if((i+x) < src.rows && (j+y) < src.cols) { // In case the kernel exceeds the image size
                        temp = src.at<unsigned char> (i+x, j+y);
                        if(temp > max_value_block)
                            max_value_block = temp;
                    }

                }
            }

            for(int x = 0; x < kernel_size; x++)
                for(int y = 0; y < kernel_size; y++)
                    if((i+x) < src.rows && (j+y) < src.cols)
                        out.at<unsigned char> (i+x, j+y) = max_value_block;

        }
    }
    return 0;
}


int min_filter (const cv::Mat& src, cv::Mat& out, const int& kernel_size) {
    // Controls
    if(kernel_size % 2 == 0) {
        std::cout << "The kernel must be odd sized" << std::endl;
        return -1;
    }
    if(src.channels() != 1 && out.channels() != 1) {
        std::cout << "This function works only for images with 1 channel" << std::endl;
        return -1;
    }

    // Filter
    for(int i = 0; i < src.rows; i += kernel_size) {
        for(int j = 0; j < src.cols; j += kernel_size) {

            int min_value_block = 255;
            int temp;
            for(int x = 0; x < kernel_size; x++) {
                for(int y = 0; y < kernel_size; y++) {
                    if((i+x) < src.rows && (j+y) < src.cols) {
                        temp = src.at<unsigned char> (i+x, j+y);
                        if(temp < min_value_block)
                            min_value_block = temp;
                    }

                }
            }

            for(int x = 0; x < kernel_size; x++)
                for(int y = 0; y < kernel_size; y++)
                    if((i+x) < src.rows && (j+y) < src.cols)
                        out.at<unsigned char> (i+x, j+y) = min_value_block;
        }
    }
    return 0;
}
