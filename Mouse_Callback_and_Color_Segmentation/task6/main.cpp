#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <cmath>
#include <filesystem>

using namespace cv;

static void colorMask_onMouse(int event, int col, int row, int flags, void* param) {
    Mat& img = *((Mat*)param); //cast and deref the param
    Mat mask (img.rows, img.cols, CV_8UC1);
    Mat new_img(img.rows, img.cols, CV_8UC3);

    int kernel_size = 9;
    if (event == EVENT_LBUTTONDOWN) {
        int mean_B = 0;
        int mean_G = 0;
        int mean_R = 0;
        for (int i = -kernel_size / 2; i <= kernel_size / 2; i++) {
            for (int j = -kernel_size / 2; j <= kernel_size / 2; j++) {
                if ((i + col) >= 0 && (j + row) >= 0 && (i + col) < img.cols &&
                    (j + row) < img.rows) { // in case the kernel exceeds the image size
                    Vec3b temp = img.at<Vec3b>(row + j, col + i);
                    mean_B += int(temp[0]);
                    mean_G += int(temp[1]);
                    mean_R += int(temp[2]);
                }
            }
        }
        mean_B /= (kernel_size * kernel_size);
        mean_G /= (kernel_size * kernel_size);
        mean_R /= (kernel_size * kernel_size);

        int T = 55; // Threshold
        for (int i = 0; i < img.rows; i++) {
            for (int j = 0; j < img.cols; j++) {
                if (abs((img.at<Vec3b>(i, j)[0] - mean_B)) <= T &&
                    abs((img.at<Vec3b>(i, j)[1] - mean_G)) <= T &&
                    abs((img.at<Vec3b>(i, j)[2] - mean_R)) <= T) {
                    mask.at<uchar>(i, j) = 255;
                } else mask.at<uchar>(i, j) = 0;
            }
        }

        // Task 6
        Vec3b sub_color = Vec3b(92, 37, 201);
        for (int i = 0; i < new_img.rows; i++) {
            for (int j = 0; j < new_img.cols; j++) {
                if (mask.at<uchar>(i, j) == 0)
                    new_img.at<Vec3b>(i, j) = img.at<Vec3b>(i, j);
                else new_img.at<Vec3b>(i, j) = sub_color;
            }
        }
        namedWindow("Robot Cup Color changed based on mask");
        imshow("Robot Cup Color changed based on mask", new_img);
        //imwrite("/home/zincalex/Uni/Computer-Vision-Laboratory/Mouse_Callback_and_Color_Segmentation/NEW_robocup.jpg",new_img);
        waitKey(0);
    }
}

int main(int argc, char** argv) {
    // Task 6
    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    Mat robocup = imread(pathImage);
    namedWindow("Robot cup");
    imshow("Robot cup", robocup);
    setMouseCallback("Robot cup", colorMask_onMouse, &robocup);
    waitKey(0);

    return 0;
}


