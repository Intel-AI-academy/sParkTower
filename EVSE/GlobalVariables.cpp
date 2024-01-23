// GlobalVariables.cpp
#include "GlobalVariables.h"

std::string g_msg;
std::mutex mtx;
std::condition_variable conv;
std::queue<std::string> messageQueue;

bool finished = false;

