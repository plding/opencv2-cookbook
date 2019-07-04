#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

#include "edgedetector.h"

int main()
{
    cv::Mat image = cv::imread("../images/road.jpg", 0);
    cv::imshow("Original Image", image);

    EdgeDetector ed;
    ed.computeSobel(image);
    cv::imshow("Sobel (orientation)", ed.getSobelOrientationImage());
    cv::imshow("Sobel (low threshold)", ed.getBinaryMap(125));
    cv::imshow("Sobel (high threshold)", ed.getBinaryMap(350));

    cv::Mat contours, contoursInv;
    cv::Canny(image, contours, 125, 350);
    cv::threshold(contours, contoursInv, 128, 255, cv::THRESH_BINARY_INV);
    cv::imshow("Canny contours", contoursInv);

    cv::waitKey();
    return 0;
}
