#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <filesystem>

using namespace cv;

int main(int argc, char** argv) {
    // Task 1
    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    Mat robocup = imread(pathImage);
    namedWindow("Robot cup");
    imshow("Robot cup", robocup);
    waitKey(0);

    return 0;
}

