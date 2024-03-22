#include "../include/ImageFilters.h"

cv::Mat maxFilter(const cv::Mat& src, const int& kernel_size) {
    // Controls
    if(kernel_size % 2 == 0) throw std::invalid_argument("Error: kernel_size must be odd");
    if(src.channels() != 1) throw std::invalid_argument("Error: the image provided must have only one channel");

    cv::Mat out(src.rows, src.cols, CV_8U);
    for(int i = 0; i < src.rows; i++) {
        for(int j = 0; j < src.cols; j++) {
            int max = 0;
            int temp;
            for(int x = -kernel_size/2; x <= kernel_size/2; x++) {
                for(int y = -kernel_size/2; y <= kernel_size/2; y++) {
                    if((i+x) >= 0 && (j+y) >= 0 && (i+x) < src.rows && (j+y) < src.cols) { // in case the kernel exceeds the image size
                        temp = src.at<unsigned char> (i+x, j+y);
                        if(temp > max)
                            max = temp;
                    }
                }
            }

            for(int x = -kernel_size/2; x <= kernel_size/2; x++)
                for(int y = -kernel_size/2; y <= kernel_size/2; y++)
                    if((i+x) >= 0 && (j+y) >= 0 && (i+x) < src.rows && (j+y) < src.cols)
                        out.at<unsigned char> (i+x, j+y) = max;

        }
    }
    return out;
}

cv::Mat minFilter(const cv::Mat& src, const int& kernel_size) {
    // Controls
    if(kernel_size % 2 == 0) throw std::invalid_argument("Error: kernel_size must be odd");
    if(src.channels() != 1) throw std::invalid_argument("Error: the image provided must have only one channel");

    cv::Mat out(src.rows, src.cols, CV_8U);
    for(int i = 0; i < src.rows; i++) {
        for(int j = 0; j < src.cols; j++) {
            int min = 255;
            int temp;
            for(int x = -kernel_size/2; x <= kernel_size/2; x++) {
                for(int y = -kernel_size/2; y <= kernel_size/2; y++) {
                    if((i+x) >= 0 && (j+y) >= 0 && (i+x) < src.rows && (j+y) < src.cols) { // in case the kernel exceeds the image size
                        temp = src.at<unsigned char> (i+x, j+y);
                        if(temp < min)
                            min = temp;
                    }
                }
            }

            for(int x = -kernel_size/2; x <= kernel_size/2; x++)
                for(int y = -kernel_size/2; y <= kernel_size/2; y++)
                    if((i+x) >= 0 && (j+y) >= 0 && (i+x) < src.rows && (j+y) < src.cols)
                        out.at<unsigned char> (i+x, j+y) = min;
        }
    }
    return out;
}

cv::Mat medianFilter(const cv::Mat& src, const int& kernel_size) {
    // Controls
    if(kernel_size % 2 == 0) throw std::invalid_argument("Error: kernel_size must be odd");
    if(src.channels() != 1) throw std::invalid_argument("Error: the image provided must have only one channel");

    cv::Mat out(src.rows, src.cols, CV_8U);
    for(int i = 0; i < src.rows; i++)  {
        for(int j = 0; j < src.cols; j++) {
            std::vector<int> kernel_elements;
            for(int x = -kernel_size/2; x <= kernel_size/2; x++) {
                for(int y = -kernel_size/2; y <= kernel_size/2; y++) {
                    if((i+x) >= 0 && (j+y) >= 0 && (i+x) < src.rows && (j+y) < src.cols) // in case the kernel exceeds the image size
                        kernel_elements.insert(kernel_elements.end(), src.at<unsigned char> (i+x, j+y));
                }
            }

            // Sorting and Median
            std::sort(kernel_elements.begin(), kernel_elements.end());
            unsigned char median = kernel_elements[int(kernel_elements.size()/ 2)];
            if( kernel_elements.size() % 2 == 0) { // At the borders it might happen that I have gathered even pixels values
                 unsigned char temp = kernel_elements[int(kernel_elements.size()/ 2) - 1];
                 median = int((temp + median) / 2);
            }

            for(int x = -kernel_size/2; x <= kernel_size/2; x++)
                for(int y = -kernel_size/2; y <= kernel_size/2; y++)
                    if((i+x) >= 0 && (j+y) >= 0 && (i+x) < src.rows && (j+y) < src.cols)
                        out.at<unsigned char> (i+x, j+y) = median;

        }
    }
    return out;
}

