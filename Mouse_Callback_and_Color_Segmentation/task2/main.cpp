#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <filesystem>

using namespace cv;

static void BGR_onMouse(int event, int col, int row, int flags, void* param) {
    Mat &img = *((Mat*)param); //cast and deref the param

    if (event == EVENT_LBUTTONDOWN) {
        Vec3b val = img.at<Vec3b>(row,col);
        std::cout << "row= " << row << " col= " << col << std::endl;
        std::cout << "B= " << int(val[0]) << std::endl;
        std::cout << "G= " << int(val[1]) << std::endl;
        std::cout << "R= " << int(val[2]) << std::endl;
        std::cout << "---------------" << std::endl;
    }
}

int main(int argc, char** argv) {
    // Task 2
    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    Mat robocup = imread(pathImage);
    namedWindow("Robot cup");
    imshow("Robot cup", robocup);
    setMouseCallback("Robot cup", BGR_onMouse, &robocup);
    waitKey(0);

    return 0;
}


