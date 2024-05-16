#pragma once
#include <time.h>
#include "RequestType.h"
#include <string>
#include <iostream>


class TimeService
{
private:

    time_t timer; 
    int countForTimeLaps = 0;
    //for MeasureTimeLap
    time_t startMeasure = 0;
    time_t endMeasure = 0;

	const char* request;
    char* answer;

    // Methods to handle different types of requests
    void GetTime();
    void GetTimeWithoutDate();
    void GetTimeSinceEpoch();
    void GetClientToServerDelayEstimation();
    void GetTimeWithoutDateOrSeconds();
    void GetYear();
    void GetMonthAndDay();
    void GetSecondsSinceBeginingOfMonth();
    void GetWeekOfYear();
    void GetDaylightSavings();
    void GetTimeWithoutDateInCity(int whatCity);
    void MeasureTimeLap();

    std::string months[12] = { "January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December" };

    std::string days[8] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };


public: 
	TimeService(const char* req, char* ans) : request(req),answer(ans) {} 
    void updateAnswer();
};




