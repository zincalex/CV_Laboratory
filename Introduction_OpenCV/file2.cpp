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
    char wk = waitKey(0);
    int number_of_channels = img.channels();
    std::cout << "The number of channels for the image is " << number_of_channels << std::endl;
    std::cout << "Button pressed to stop resume the flow of the program "<< wk << std::endl;

    return 0;
}