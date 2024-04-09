#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <filesystem>

using namespace cv;

Mat street, street_gray;
Mat dst, detected_edges, cdst, cdstP;

int lowThreshold = 75;
int ratio = 109;
int kernel_size = 5;
int T_H = 128;


const int max_lowThreshold = 100;
const int max_ratioThreshold = 110;
const int max_kernelThreshold = 7;
const char* window_name = "Canny Edge Detector Image";

static void HoughTransform_CannyThreshold(int, void*) {
    if(kernel_size % 2 == 0)
        kernel_size -= 1;

    GaussianBlur(street_gray, detected_edges, Size(kernel_size,kernel_size), 0);
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );


    cvtColor(detected_edges, cdst, COLOR_GRAY2BGR);

    // Standard Hough Line Transform
    std::vector<Vec2f> lines; // will hold the results of the detection
    HoughLines(detected_edges, lines, 1, CV_PI/180, T_H, 0, 0 ); // runs the actual detection
    // Draw the lines
    for( size_t i = 0; i < lines.size(); i++ )
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        line( street, pt1, pt2, Scalar(0,0,255), 1, LINE_AA);
    }

    for(int i = 0; i < cdst.rows; i++) {
        for(int j = 0; j < cdst.cols; j++) {
            if(cdst.at<Vec3b>(i, j)[2] == 255) {

            }
        }
    }


    dst = Scalar::all(0);
    street.copyTo( dst, detected_edges);
    imshow( window_name, street);
}

int main(int argc, char** argv) {
    // Task 1
    std::filesystem::path pathImage = std::filesystem::absolute(argv[1]);
    street = imread(pathImage);
    namedWindow(window_name, WINDOW_AUTOSIZE);
    dst.create( street.size(), street.type() );

    cvtColor( street, street_gray, COLOR_BGR2GRAY );
    createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, HoughTransform_CannyThreshold);
    createTrackbar( "Kernel size:", window_name, &kernel_size, max_kernelThreshold, HoughTransform_CannyThreshold);
    createTrackbar( "Ratio:", window_name, &ratio, max_ratioThreshold, HoughTransform_CannyThreshold);
    //setTrackbarPos( "Min Threshold:", window_name, lowThreshold);
    HoughTransform_CannyThreshold(0, 0);
    waitKey(0);

    return 0;
}


