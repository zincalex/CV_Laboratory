#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv) {
    Mat twentySquared_img(300, 300, CV_8U); 
    Mat fiftySquared_img(300, 300, CV_8U);

    bool rowCond50 = false;
    bool colCond50 = false;

    bool rowCond20 = false;
    bool colCond20 = false;
    // THE CODE IS RIGHT, HOWEVER FOR SQUARES OF SIZE 20 (ALSO 100), THE IMAGE IS BROKEN
    for(int i = 0; i < 300; i++) {

        if(i%50 == 0) 
            rowCond50 = !rowCond50;
        if(i%20 == 0) 
            rowCond20 = !rowCond20;

        for(int j = 0; j < 300; j++) {
            if(j%50 == 0)
                colCond50 = !colCond50;  
            if(j%20 == 0)
                colCond20 = !colCond20;

            // Whitening for 50
            if(rowCond50) {
                if(colCond50)
                    fiftySquared_img.at<unsigned char> (i, j) = 255;
            }
            else {
                if(!colCond50)
                    fiftySquared_img.at<unsigned char> (i, j) = 255;
            }

            // Whitening for 20
            if(rowCond20) {
                if(colCond20)
                    twentySquared_img.at<unsigned char> (i, j) = 255;
            }
            else {
                if(!colCond20)
                    twentySquared_img.at<unsigned char> (i, j) = 255;
            }
        }
    }

    namedWindow("Chessboard with squares of 20 pixels");
    imshow("Chessboard with squares of 20 pixels", twentySquared_img);
    namedWindow("Chessboard with squares of 50 pixels");
    imshow("Chessboard with squares of 50 pixels", fiftySquared_img);
    char wk = waitKey(0);
    
    std::cout << "Button pressed to stop resume the flow of the program "<< wk << std::endl;

    return 0;
}