#ifndef CHARGINGPORT_DETECTOR_H
#define CHARGINGPORT_DETECTOR_H

#include <opencv2/opencv.hpp>
#include <string>

class ChargingportDetector {
public:
    ChargingportDetector();
    ~ChargingportDetector();

    void run();

private:
    cv::VideoCapture cap;

    void processFrame(cv::Mat& frame);
};

#endif // CHARGINGPORT_DETECTOR_H
