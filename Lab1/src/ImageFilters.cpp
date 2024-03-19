#include "ImageFilters.h"

cv::Mat max_filter(const cv::Mat& src, const int& kernel_size)
{
    // Controls
    if(kernel_size % 2 == 0) throw std::invalid_argument("Error: kernel_size must be odd");
    if(src.channels() != 1) throw std::invalid_argument("Error: the image provided must have only one channel");

    cv::Mat out(src.rows, src.cols, CV_8U);
    for(int i = 0; i < src.rows; i += kernel_size) // filter
    {
        for(int j = 0; j < src.cols; j += kernel_size)
        {
            int max = 0;
            int temp;
            for(int x = 0; x < kernel_size; x++)
            {
                for(int y = 0; y < kernel_size; y++)
                {
                    if((i+x) < src.rows && (j+y) < src.cols) // in case the kernel exceeds the image size
                    {
                        temp = src.at<unsigned char> (i+x, j+y);
                        if(temp > max)
                            max = temp;
                    }
                }
            }

            for(int x = 0; x < kernel_size; x++)
                for(int y = 0; y < kernel_size; y++)
                    if((i+x) < src.rows && (j+y) < src.cols)
                        out.at<unsigned char> (i+x, j+y) = max;

        }
    }
    return out;
}

cv::Mat min_filter(const cv::Mat& src, const int& kernel_size)
{
    // Controls
    if(kernel_size % 2 == 0) throw std::invalid_argument("Error: kernel_size must be odd");
    if(src.channels() != 1) throw std::invalid_argument("Error: the image provided must have only one channel");

    cv::Mat out(src.rows, src.cols, CV_8U);
    for(int i = 0; i < src.rows; i += kernel_size) // filter
    {
        for(int j = 0; j < src.cols; j += kernel_size)
        {
            int min = 255;
            int temp;
            for(int x = 0; x < kernel_size; x++)
            {
                for(int y = 0; y < kernel_size; y++)
                {
                    if((i+x) < src.rows && (j+y) < src.cols)
                    {
                        temp = src.at<unsigned char> (i+x, j+y);
                        if(temp < min)
                            min = temp;
                    }
                }
            }

            for(int x = 0; x < kernel_size; x++)
                for(int y = 0; y < kernel_size; y++)
                    if((i+x) < src.rows && (j+y) < src.cols)
                        out.at<unsigned char> (i+x, j+y) = min;
        }
    }
    return out;
}

cv::Mat median_filter(const cv::Mat& src, const int& kernel_size)
{
    // Controls
    if(kernel_size % 2 == 0) throw std::invalid_argument("Error: kernel_size must be odd");
    if(src.channels() != 1) throw std::invalid_argument("Error: the image provided must have only one channel");

    cv::Mat out(src.rows, src.cols, CV_8U);
    for(int i = 0; i < src.rows; i += kernel_size) // filter
    {
        for(int j = 0; j < src.cols; j += kernel_size)
        {
            std::vector<int> kernel_elements;
            for(int x = 0; x < kernel_size; x++)
            {
                for(int y = 0; y < kernel_size; y++)
                {
                    if((i+x) < src.rows && (j+y) < src.cols)  // In case the kernel exceeds the image size
                        kernel_elements.insert(kernel_elements.end(), src.at<unsigned char> (i+x, j+y));
                }
            }

            // Sorting and Median
            std::sort(kernel_elements.begin(), kernel_elements.end());
            unsigned long numElem_kernel = kernel_elements.size();
            unsigned char median = kernel_elements[(numElem_kernel/ 2) + 1]; // always odd elements inside the vector

            for(int x = 0; x < kernel_size; x++)
                for(int y = 0; y < kernel_size; y++)
                    if((i+x) < src.rows && (j+y) < src.cols)
                        out.at<unsigned char> (i+x, j+y) = median;

        }
    }
    return out;
}

