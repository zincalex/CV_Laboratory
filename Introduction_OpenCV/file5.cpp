#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv) {
    Mat v_img(256, 256, CV_8U); 
    Mat h_img(256, 256, CV_8U);

    for(int i = 0; i < 256; i++) {
        for(int j = 0; j < 256; j++) {
            v_img.at<unsigned char> (i, j) = j;
            h_img.at<unsigned char> (i, j) = i;
        }
    }

    namedWindow("Vertical Gradient");
    imshow("Vertical Gradient", v_img);
    namedWindow("Horizontal Gradient");
    imshow("Horizontal Gradient", h_img);
    char wk = waitKey(0);
    
    std::cout << "Button pressed to stop resume the flow of the program "<< wk << std::endl;

    return 0;
}