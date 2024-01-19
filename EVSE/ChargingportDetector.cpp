#include "ChargingportDetector.h"

ChargingportDetector::ChargingportDetector() : cap(0) {
    if (!cap.isOpened()) {
        std::cerr << "Error: 카메라를 열 수 없습니다." << std::endl;
    }
}

ChargingportDetector::~ChargingportDetector() {
    cap.release();
}

void ChargingportDetector::run() {
    while (true) {
        cv::Mat frame;
        cap >> frame;

        if (frame.empty())
            break;

        detectChargingport(frame);

        cv::imshow("result", frame);

        if (cv::waitKey(33) == 27)
            break;
    }
}

void* ChargingportDetector::DetectPortThread(void* arg) {
    ChargingportDetector* detector = static_cast<ChargingportDetector*>(arg);
    detector->run();
    return nullptr;
}
/*
void ChargingportDetector::startThread() {
    pthread_create(&threadId, nullptr, &ChargingportDetector::threadFunction, this);
}

void ChargingportDetector::joinThread() {
    pthread_join(threadId, nullptr);
}
*/

void ChargingportDetector::detectChargingport(cv::Mat& frame) {


    // 그레이 스케일로 변환
    cv::Mat gray;
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    // 블러처리하여 노이즈 감소
    cv::GaussianBlur(gray, gray, cv::Size(9, 9), 2, 2);

    // HoughCircles를 사용하여 원 찾기
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 16, 100, 50, 0, 0);

    std::vector<cv::Point2f> circleCenters;
    
    for (size_t i = 0; i < circles.size(); i++)
    {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);

        // 원의 면적 계산
        double circleArea = CV_PI * radius * radius;

        // 면적이 50 이상인 경우에만 그리기
        if (circleArea > 50)
        {
            // 원 그리기
            cv::circle(frame, center, radius, cv::Scalar(0, 0, 255), 3, 8, 0);

            // 중심에 점 찍기
            cv::circle(frame, center, 3, cv::Scalar(0, 255, 0), -1, 8, 0);

            // 원의 중심을 저장
            circleCenters.push_back(center);
        }
    }

    // 무게 중심 계산
    if (circleCenters.size() >= 5)
    {
        cv::Point2f mc(0, 0);
        for (const auto& center : circleCenters)
        {
            mc += center;
        }
        mc /= static_cast<float>(circleCenters.size());

        // 무게 중심에 점 찍기
        cv::circle(frame, mc, 5, cv::Scalar(255, 255, 0), -1, 8, 0);

        // 카메라 중심 계산
        cv::Point2f cameraCenter(frame.cols / 2, frame.rows / 2);

        // X 및 Y 방향 거리 계산
        double distanceX = std::abs(mc.x - cameraCenter.x);
        double distanceY = std::abs(mc.y - cameraCenter.y);

        // 거리에 따른 상태 텍스트 설정
        std::string statusX, statusY;
	g_msg = "";

	// 수평 방향 스텝모터 제어
	if (distanceX > 100) {
            statusX = "far";
	    g_msg = "[YSK_QT]move@X\n";
	    if(distanceY > 100) {
		statusY = "far";
	    }
	    else if (distanceY > 20) {
		statusY = "close";
	    }
	    else
		statusY = "match";
        }
        else if (distanceX > 20) {
            statusX = "close";
	    g_msg = "[YSK_QT]move@X\n";
	    if(distanceY > 100) {
		statusY = "far";
	    }
	    else if (distanceY > 20) {
		statusY = "close";
	    }
	    else
		statusY = "match";
        }
        else {
            statusX = "match";
	    if(distanceY > 100) {
		statusY = "far";
		g_msg = "[YSK_QT]move@Y\n";
	    }
	    else if (distanceY > 20) {
		statusY = "close";
		g_msg = "[YSK_QT]move@Y\n";
	    }
	    else
		statusY = "match";
        }

	/*
	// 수직 방향 스텝모터 제어
        if (distanceY > 100) {
            statusY = "far";
        }
        else if (distanceY > 20) {
            statusY = "close";
        }
        else {
            statusY = "match";
        }
	*/

        // 텍스트를 화면에 추가
        cv::putText(frame, "status (X): " + statusX, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);
        cv::putText(frame, "status (Y): " + statusY, cv::Point(10, 70), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);

        // ROI의 크기 설정
        int roiSize = 40;
        cv::Rect roiRect(mc.x - roiSize / 2, mc.y - roiSize / 2, roiSize, roiSize);

        // ROI 그리기
        cv::rectangle(frame, roiRect, cv::Scalar(0, 255, 255), 2);
    }
    
    // 화면 중심에 점 찍기
    cv::Point centerOfFrame(frame.cols / 2, frame.rows / 2);
    cv::circle(frame, centerOfFrame, 5, cv::Scalar(0, 255, 255), -1, 8, 0);
}

