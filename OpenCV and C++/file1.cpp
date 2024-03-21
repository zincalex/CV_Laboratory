#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "A image filename shall be provided\n";
        return 1;
    }
        
    Mat img = imread(argv[1], IMREAD_COLOR);

    if(img.empty()) {
        std::cout << "Could not read the image";
        return 1;
    }

    namedWindow("Picture 1");
    imshow("Picture 1", img);
    waitKey(0);

    return 0;
}