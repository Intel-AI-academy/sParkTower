// GlobalVariables.h
#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#pragma once

#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <string>

extern std::string g_msg;
extern std::mutex mtx;
extern std::condition_variable conv;
extern std::queue<std::string> messageQueue;

extern bool finished;

#endif // GLOBAL_VARIABLES_H
