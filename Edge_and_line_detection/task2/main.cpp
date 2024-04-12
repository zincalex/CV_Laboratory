#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <filesystem>

using namespace cv;

int main(int argc, char** argv) { // Task 2
    const char* window_name = "White markings detection";

    Mat street, street_gray, Sobel_img, ClosedSobel_img;
    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    street = imread(pathImage);
    namedWindow(window_name, WINDOW_AUTOSIZE);

    cvtColor( street, street_gray, COLOR_BGR2GRAY );
    for (int i = 0; i < street_gray.rows; i++)
        for (int j = 0; j < street_gray.cols; j++)
            if(street_gray.at<unsigned char>(i,j) < 245)
                street_gray.at<unsigned char>(i,j) = 0;

    Mat kernel_morph = getStructuringElement(MORPH_RECT, Size(3,3)); // Default anchor point at the center
    Sobel(street_gray, Sobel_img, CV_8U, 1, 0, 3);
    morphologyEx(Sobel_img, ClosedSobel_img, MORPH_CLOSE, kernel_morph); // Closing is a dilatation followed by erosion

    imshow( window_name, ClosedSobel_img);
    waitKey(0);
    return 0;
}


