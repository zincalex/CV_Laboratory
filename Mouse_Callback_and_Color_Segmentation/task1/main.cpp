#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char** argv) {

    // Task 1
    Mat robocup = imread("/home/zincalex/Uni/Computer-Vision-Laboratory/Mouse_Callback_and_Color_Segmentation/robocup.jpg");
    namedWindow("Robot cup");
    imshow("Robot cup", robocup);
    waitKey(0);

    return 0;
}

