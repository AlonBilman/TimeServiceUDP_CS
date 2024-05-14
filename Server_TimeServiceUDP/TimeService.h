#pragma once
#include <time.h>
#include "RequestType.h"
#include <string>
#include <iostream>


class TimeService
{
private: 
	const char* request;
    char* answer;
    // Methods to handle different types of requests
    void GetTime();
    void GetTimeWithoutDate();
    void GetTimeSinceEpoch();
    void GetClientToServerDelayEstimation();
    void MeasureRTT();
    void GetTimeWithoutDateOrSeconds();
    void GetYear();
    void GetMonthAndDay();
    void GetSecondsSinceBeginingOfMonth();
    void GetWeekOfYear();
    void GetDaylightSavings();
    void GetTimeWithoutDateInCity();
    void MeasureTimeLap();

public: 
	TimeService(const char* req, char* ans) : request(req),answer(ans) {} 
    void updateAnswer();
};




