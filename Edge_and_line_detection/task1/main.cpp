#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <filesystem>

using namespace cv;

Mat street, street_gray;
Mat dst, detected_edges;

int lowThreshold = 0;
int ratio = 3;
int kernel_size = 3;

const int max_lowThreshold = 100;
const int max_ratioThreshold = 100;
const int max_kernelThreshold = 7;
const char* window_name = "Canny Edge Detector Image";

static void CannyThreshold(int, void*) {
    if(kernel_size % 2 == 0)
        kernel_size -= 1;

    GaussianBlur(street_gray, detected_edges, Size(kernel_size,kernel_size), 0);
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    dst = Scalar::all(0);
    street.copyTo( dst, detected_edges);
    imshow( window_name, dst );
}

int main(int argc, char** argv) {
    // Task 1
    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    street = imread(pathImage);
    namedWindow(window_name, WINDOW_AUTOSIZE);
    dst.create( street.size(), street.type() );

    cvtColor( street, street_gray, COLOR_BGR2GRAY );
    createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);
    createTrackbar( "Kernel size:", window_name, &kernel_size, max_kernelThreshold, CannyThreshold);
    createTrackbar( "Ratio:", window_name, &ratio, max_ratioThreshold, CannyThreshold);
    //setTrackbarPos( "Min Threshold:", window_name, lowThreshold);
    CannyThreshold(0, 0);
    waitKey(0);

    return 0;
}


