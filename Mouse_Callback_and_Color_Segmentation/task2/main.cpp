#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>


using namespace cv;

static void BGR_onMouse(int event, int col, int row, int flags, void* param) {
    Mat &img = *((Mat*)param); //cast and deref the param

    if (event == EVENT_LBUTTONDOWN) {
        Vec3b val = img.at<Vec3b>(row,col);
        std::cout << "row= " << row << " col= " << col << std::endl;
        std::cout << "B= " << int(val[0]) << std::endl;
        std::cout << "G= " << int(val[1]) << std::endl;
        std::cout << "R= " << int(val[2]) << std::endl;
    }
}

int main(int argc, char** argv) {
    // Task 2
    Mat robocup = imread("/home/zincalex/Uni/Computer-Vision-Laboratory/Mouse_Callback_and_Color_Segmentation/robocup.jpg");
    namedWindow("Robot cup");
    imshow("Robot cup", robocup);
    setMouseCallback("Robot cup", BGR_onMouse, &robocup);
    waitKey(0);

    return 0;
}


