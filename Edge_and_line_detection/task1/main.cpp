#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <filesystem>

using namespace cv;

const int max_lowThreshold = 100;
const int max_ratioThreshold = 100;
const int max_kernelThreshold = 7;
const char* window_name = "Canny Edge Detector Image";
struct ParamsCanny {
    Mat street, street_gray;
    Mat streetCanny_overlapping, canny_img;

    int lowThreshold = 0;
    int ratio = 3;
    int kernel_size = 3;
    int kernel_size_Gauss = 9;
};


static void CannyThreshold(int, void* userdata) {
    ParamsCanny &par  = *((ParamsCanny*) userdata);

    if(par.kernel_size % 2 == 0)
        par.kernel_size -= 1;

    GaussianBlur(par.street_gray, par.canny_img, Size(par.kernel_size_Gauss, par.kernel_size_Gauss), 0);
    Canny(par.canny_img, par.canny_img, par.lowThreshold, par.lowThreshold * par.ratio, par.kernel_size );
    imshow(window_name, par.canny_img);

    // Optional For seeing the effect of Canny on the street_scene.png image
    //par.streetCanny_overlapping = Scalar::all(0);
    //par.street.copyTo(streetCanny_overlapping, par.canny_img);
}


int main(int argc, char** argv) {  // Task 1
    ParamsCanny params;     // Stuct used in order to not have global variables, which were not constant
    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    params.street = imread(pathImage);
    namedWindow(window_name, WINDOW_AUTOSIZE);
    //params.streetCanny_overlapping.create( params.street.size(), params.street.type() );

    cvtColor( params.street, params.street_gray, COLOR_BGR2GRAY );
    createTrackbar( "Min Threshold:", window_name, &params.lowThreshold, max_lowThreshold, CannyThreshold, &params);
    createTrackbar( "Kernel size Canny:", window_name, &params.kernel_size, max_kernelThreshold, CannyThreshold, &params);
    createTrackbar( "Ratio:", window_name, &params.ratio, max_ratioThreshold, CannyThreshold, &params);
    waitKey(0);

    return 0;
}


