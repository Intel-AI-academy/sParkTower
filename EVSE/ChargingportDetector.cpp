#include "ChargingportDetector.h"

bool ChargingportDetector::find_flag = false; // 충전포트를 찾았는지 확인하는 플래그
bool ChargingportDetector::exti_flag = false; 
bool ChargingportDetector::updown_flag = false;
int ChargingportDetector::count = 1000; // find 시 최대 펄스 1000

double ChargingportDetector::distanceY = 0.0;

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
void* ChargingportDetector::SendMsgThread(void* arg) {
    ChargingportDetector* detector = static_cast<ChargingportDetector*>(arg);
    detector->SendMsg();
    return nullptr;
}

void ChargingportDetector::detectChargingport(cv::Mat& frame) {
    // 그레이 스케일로 변환
    cv::Mat gray;
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    // 블러처리하여 노이즈 감소
    cv::GaussianBlur(gray, gray, cv::Size(9, 9), 2, 2);

    // HoughCircles를 사용하여 원 찾기
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 128, 50, 25, 0, 25);

    std::vector<cv::Point2f> circleCenters;
    
    for (size_t i = 0; i < circles.size(); i++)
    {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);

        // 원 그리기
        cv::circle(frame, center, radius, cv::Scalar(0, 0, 255), 3, 8, 0);

        // 중심에 점 찍기
        cv::circle(frame, center, 3, cv::Scalar(0, 255, 0), -1, 8, 0);

        // 원의 중심을 저장
        circleCenters.push_back(center);

    }
    if(circleCenters.size() == 5)
	find_flag = true;
    /*
    else
	find_flag = false;
	*/
    
    if(find_flag)
    {
        // 무게 중심 계산
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
        //double distanceX = std::abs(mc.x - cameraCenter.x);
        distanceY = std::abs(mc.y - cameraCenter.y);

        // 거리에 따른 상태 텍스트 설정
        //std::string statusX, statusY;
        std::string statusY;

        if(distanceY > 100){
            statusY = "far";
	}
	else if(distanceY > 20){
            statusY = "close";
	}
	else {
	    statusY = "match";
	}

         #ifdef DEBUG
        // 텍스트를 화면에 추가
        //cv::putText(frame, "status (X): " + statusX, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);
        cv::putText(frame, "status (Y): " + statusY, cv::Point(10, 70), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);
        #endif

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

void ChargingportDetector::SendMsg() {
    while(true){
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	// Produce a message
        std::string message = "";
        if(!find_flag){
            if(!updown_flag){
                message = this->receiver + "find@up\n";
                count -= 50;
		//message = message + "@" + std::to_string(count);
                if(count<=0)
                    updown_flag=true;
            }
            else{
                message = this->receiver + "find@down\n";
                count += 50;
		//message = message + "@" + std::to_string(count);
                if(count>=1000)
                    updown_flag=false;
            }
        }
        else{    
	    if(!exti_flag){
	        //message = this->receiver + "stop\n";
	        // 수직 방향 스텝모터 제어
                if (this->distanceY > 100) {
	   	    message = this->receiver + "move@up\n";
                }
                else if (this->distanceY > 20) {
                    message = this->receiver + "move@up\n";
                }
                else {
                    message = this->receiver + "stop\n";
		    exti_flag = true;
                }
	    }
        }
	// Lock the mutex before modifying the shared data
        std::unique_lock<std::mutex> lock(mtx);

        // Add the message to the queue
        messageQueue.push(message);

        // Notify the consumer that there is a new message
        conv.notify_one();
    }
}
