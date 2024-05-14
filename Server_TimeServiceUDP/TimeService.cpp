#define _CRT_SECURE_NO_WARNINGS
#include "TimeService.h"
using namespace std; 

time_t timer; 

void TimeService::updateAnswer()
{
   // int type = stoi(request); //the protocol ive used is using ints for communications. 
    int type = 11;
    switch (type) {
    case (int)RequestType::GetTime:
        return GetTime();
    case (int)RequestType::GetTimeWithoutDate:
        return GetTimeWithoutDate();
    case (int)RequestType::GetTimeSinceEpoch:
        return GetTimeSinceEpoch();
    case (int)RequestType::GetClientToServerDelayEstimation: 
        return GetClientToServerDelayEstimation();
    case (int)RequestType::MeasureRTT:
        return MeasureRTT();
    case (int)RequestType::GetTimeWithoutDateOrSeconds:
        return GetTimeWithoutDateOrSeconds();
    case (int)RequestType::GetYear:
        return GetYear();
    case (int)RequestType::GetMonthAndDay:
        return GetMonthAndDay();
    case (int)RequestType::GetSecondsSinceBeginingOfMonth:
        return GetSecondsSinceBeginingOfMonth();
    case (int)RequestType::GetWeekOfYear:
        return GetWeekOfYear();
    case (int)RequestType::GetDaylightSavings:
        return GetDaylightSavings();
    case (int)RequestType::GetTimeWithoutDateInCity:
        return GetTimeWithoutDateInCity();
    case (int)RequestType::MeasureTimeLap:
        return MeasureTimeLap();

    default:
        cout << "something went wrong, the user didnt use the protocol as intended.\n";
        return;
    }
}

void TimeService::GetTime()
{
   time(&timer);
   // Parse the current time to printable string.
   strcpy(answer, ctime(&timer));
   answer[strlen(answer) - 1] = '\0'; //to remove the new-line from the created string
}

void TimeService::GetTimeWithoutDate()
{
    time(&timer);
    tm* info = localtime(&timer);
    sprintf(answer, "The time is %d:%d:%d", info->tm_hour, info->tm_min, info->tm_sec);
}

void TimeService::GetTimeSinceEpoch() //seconds since 1.1.1970
{
    time(&timer);
    long long secondsSinceTheSeventies = static_cast<long long>(timer); //casting to longlong
    sprintf(answer, "The time since 1970 in seconds is: %lld", secondsSinceTheSeventies);
}
void TimeService::GetClientToServerDelayEstimation() 
{
    
}
void TimeService::MeasureRTT()
{

}
void TimeService::GetTimeWithoutDateOrSeconds()
{
    time(&timer);
    tm* info = localtime(&timer);
    sprintf(answer, "The time is %d:%d", info->tm_hour, info->tm_min);
}
void TimeService::GetYear()
{
    time(&timer);
    tm* info = localtime(&timer);
    sprintf(answer, "The year is %d", info->tm_year+1900); //tm_year gets the years since 1970

}
void TimeService::GetMonthAndDay()
{
    time(&timer);
    tm* info = localtime(&timer);
    sprintf(answer, "\n The Month is : %d \n The Day is : %d", info->tm_mon, info->tm_wday);
}
void TimeService::GetSecondsSinceBeginingOfMonth()
{
    int secondsInAday = 86400;
    int secondsInAnHour = 3600;
    time(&timer);
    tm* info = localtime(&timer);
    int seconds = (info->tm_mday - 1) * secondsInAday + info->tm_sec + info->tm_min * 60 + info->tm_hour * secondsInAnHour;
    sprintf(answer, "The seconds sice the start of the month are : %d", seconds);
}
void TimeService::GetWeekOfYear()
{
    int numberOfweeks;
    time(&timer);
    tm* info = localtime(&timer);
    numberOfweeks = (info->tm_yday / 7) + 1; //+1 for the current week 
    sprintf(answer, "The weeks sice the start of the year are : %d", numberOfweeks);
}
void TimeService::GetDaylightSavings()
{
    int Daylight;
    time(&timer);
    tm* info = localtime(&timer);
    Daylight = info->tm_isdst;
    sprintf(answer, "The Daylight Saving is : %d", Daylight);

}
void TimeService::GetTimeWithoutDateInCity()
{
    time(&timer);
    tm* info = localtime(&timer);
}
void TimeService::MeasureTimeLap()
{

}
