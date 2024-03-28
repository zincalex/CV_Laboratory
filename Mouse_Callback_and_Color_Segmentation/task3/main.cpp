#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <filesystem>

using namespace cv;

static void BGR_mean9x9_onMouse(int event, int col, int row, int flags, void* param) {
    Mat& img = *((Mat*)param); //cast and deref the param
    int kernel_size = 9;

    if (event == EVENT_LBUTTONDOWN) {
        int sum_B = 0;
        int sum_G = 0;
        int sum_R = 0;
        for(int i = -kernel_size/2; i <= kernel_size/2; i++) {
            for(int j = -kernel_size/2; j <= kernel_size/2; j++) {
                if((i+col) >= 0 && (j+row) >= 0 && (i+col) < img.cols && (j+row) < img.rows) { // in case the kernel exceeds the image size
                    Vec3b temp = img.at<Vec3b>(row+j, col+i);
                    sum_B += int(temp[0]);
                    sum_G += int(temp[1]);
                    sum_R += int(temp[2]);
                }
            }
        }

        std::cout << "row= " << row << " col= " << col << std::endl;
        std::cout << "mean B= " <<  (sum_B / (9*9)) << std::endl;
        std::cout << "mean G= " << (sum_G / (9*9)) << std::endl;
        std::cout << "mean R= " << (sum_R / (9*9)) << std::endl;
        std::cout << "------------------" << std::endl;
    }
}

int main(int argc, char** argv) {
    // Task 3
    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    Mat robocup = imread(pathImage);
    namedWindow("Robot cup");
    imshow("Robot cup", robocup);
    setMouseCallback("Robot cup", BGR_mean9x9_onMouse, &robocup);
    waitKey(0);

    return 0;
}


