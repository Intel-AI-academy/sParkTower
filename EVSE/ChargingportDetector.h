#ifndef CHARGINGPORT_DETECTOR_H
#define CHARGINGPORT_DETECTOR_H

#pragma once

#include <opencv2/opencv.hpp>
#include "GlobalVariables.h"

#define DEBUG

class ChargingportDetector {
public:
    ChargingportDetector();
    ~ChargingportDetector();

    void run();
    static void* DetectPortThread(void* arg);
    static void* SendMsgThread(void* arg);
    static bool find_flag;
    static bool exti_flag;
    static bool updown_flag;

    static int count;

private:
    cv::VideoCapture cap;
    std::string receiver = "[YSK_STM]";
    static double distanceY;

    void detectChargingport(cv::Mat& frame);
    void SendMsg();
};

#endif // CHARGINGPORT_DETECTOR_H

