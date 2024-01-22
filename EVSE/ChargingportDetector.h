#ifndef CHARGINGPORT_DETECTOR_H
#define CHARGINGPORT_DETECTOR_H

#include <opencv2/opencv.hpp>
#include <string>
#include "GlobalVariables.h"

#define DEBUG

class ChargingportDetector {
public:
    ChargingportDetector();
    ~ChargingportDetector();

    void run();
    //void startThread();
    //void joinThread();
    static void* DetectPortThread(void* arg);
    static bool find_flag;
    static bool exti_flag;

    static int count;
    static bool updown_flag;
    static double prevDistanceY;

private:
    cv::VideoCapture cap;
    //pthread_t threadId;
    std::string receiver = "[YSK_STM]";

    void detectChargingport(cv::Mat& frame);
};

#endif // CHARGINGPORT_DETECTOR_H
