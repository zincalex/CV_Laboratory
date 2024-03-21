#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace cv;

bool check_3_channels(int& num_chan) {
    return  num_chan == 3;
}

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "A image filename shall be provided\n";
        return 1;
    }
        
    Mat img = imread(argv[1], IMREAD_COLOR);
    int number_of_channels = img.channels();
    if(img.empty()) {
        std::cout << "Could not read the image";
        return 1;
    }

    int rows = img.rows;
    int cols = img.cols;
    Mat img1(rows, cols, CV_8U); 
    Mat img2(rows, cols, CV_8U);
    Mat img3(rows, cols, CV_8U);

    if(check_3_channels(number_of_channels)) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                img1.at<unsigned char> (i, j) = img.at<Vec3b> (i, j)[0];
                img2.at<unsigned char> (i, j) = img.at<Vec3b> (i, j)[1];
                img3.at<unsigned char> (i, j) = img.at<Vec3b> (i, j)[2];
            }
        }
    }   

    namedWindow("Original Image");
    imshow("Original Image", img);
    namedWindow("Image1");
    imshow("Image1", img1);
    namedWindow("Image2");
    imshow("Image2", img2);
    namedWindow("Image3");
    imshow("Image3", img3);
    char wk = waitKey(0);
    
    std::cout << "The number of channels for the image is " << number_of_channels << std::endl;
    std::cout << "Button pressed to stop resume the flow of the program "<< wk << std::endl;

    return 0;
}