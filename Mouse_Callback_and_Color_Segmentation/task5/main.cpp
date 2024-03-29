#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <cmath>
#include <filesystem>

using namespace cv;

static void Mask_HSV_onMouse(int event, int col, int row, int flags, void* param) {
    Mat& img = *((Mat*)param); //cast and deref the param
    Mat img_HSV;
    Mat mask (img.rows, img.cols, CV_8UC1); // Different from before, now is better since the mask has only white or black pixel (grayscale sufficient)

    cvtColor(img, img_HSV, COLOR_BGR2HSV);
    namedWindow("Robot HSV");
    imshow("Robot HSV", img_HSV); // Values are read as BGR, though

    int kernel_size = 9;
    if (event == EVENT_LBUTTONDOWN) {
        int mean_H = 0;
        int mean_S = 0;
        int mean_V = 0;
        for(int i = -kernel_size/2; i <= kernel_size/2; i++) {
            for(int j = -kernel_size/2; j <= kernel_size/2; j++) {
                if((i+col) >= 0 && (j+row) >= 0 && (i+col) < img_HSV.cols && (j+row) < img_HSV.rows) { // in case the kernel exceeds the image size
                    Vec3b temp = img_HSV.at<Vec3b>(row+j, col+i);
                    mean_H += int(temp[0]);
                    mean_S += int(temp[1]);
                    mean_V += int(temp[2]);
                }
            }
        }

        mean_H /= (kernel_size * kernel_size);
        mean_S /= (kernel_size * kernel_size);
        mean_V /= (kernel_size * kernel_size);

        int T = 55; // Threshold
        for(int i = 0; i < img_HSV.rows; i++) {
            for(int j = 0; j < img_HSV.cols; j++) {
                if (abs((img_HSV.at<Vec3b>(i, j)[0] - mean_H)) <= T &&
                    abs((img_HSV.at<Vec3b>(i, j)[1] - mean_S)) <= T &&
                    abs((img_HSV.at<Vec3b>(i, j)[2] - mean_V)) <= T) {
                    mask.at<uchar>(i,j) = 255;
                }
                else mask.at<uchar>(i,j) = 0;
            }
        }

        namedWindow("Mask");
        imshow("Mask", mask);
        waitKey(0);
    }
}

int main(int argc, char** argv) {
    // Task 5
    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    Mat robocup = imread(pathImage);
    namedWindow("Robot cup");
    imshow("Robot cup", robocup);
    setMouseCallback("Robot cup", Mask_HSV_onMouse, &robocup);
    waitKey(0);

    return 0;
}


