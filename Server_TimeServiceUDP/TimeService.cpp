#define _CRT_SECURE_NO_WARNINGS
#include "TimeService.h"
using namespace std; 


void TimeService::updateAnswer()
{
    int type = stoi(request); //the protocol ive used is using ints for communications.
    if (type > (int)RequestType::ThreeDigits) 
        type /= 10;
    switch (type) {
    case (int)RequestType::GetTime:
        return GetTime();
    case (int)RequestType::GetTimeWithoutDate:
        return GetTimeWithoutDate();
    case (int)RequestType::GetTimeSinceEpoch:
        return GetTimeSinceEpoch();
    case (int)RequestType::GetClientToServerDelayEstimation: 
        return GetClientToServerDelayEstimation();
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
        return GetTimeWithoutDateInCity(stoi(request) % 10);
    case (int)RequestType::MeasureTimeLap:
        return MeasureTimeLap();

    default:
        cout << "something went wrong, the user didnt use the protocol as intended.\n";
        strcpy(answer, "You Did not use the protocol as intended!,ugh..");
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
    sprintf(answer, "\n The Month is : %s | The Day is : %s", months[info->tm_mon].c_str(), days[info->tm_wday].c_str());
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
void TimeService::GetTimeWithoutDateInCity(int whatCity)
{
    time(&timer);
    tm* info = gmtime(&timer); // for UTC time

    switch (whatCity)
    {
    case (int)RequestType::Doha: // gmt +3
    {
        sprintf(answer, "The time in Doha is %d:%d:%d", info->tm_hour +3, info->tm_min, info->tm_sec);
        break;
    }
    case (int)RequestType::Prague: // gmt +2
    {
        sprintf(answer, "The time in Prague is %d:%d:%d", info->tm_hour+2, info->tm_min, info->tm_sec);
        break;
    }
    case (int)RequestType::New_York: // gmt -4
    {
        sprintf(answer, "The time in New York is %d:%d:%d", info->tm_hour-4, info->tm_min, info->tm_sec);
        break;
    }

    case (int)RequestType::Berlin: // gmt +2
    {
        sprintf(answer, "The time in Berlin is %d:%d:%d", info->tm_hour+2, info->tm_min, info->tm_sec);
        break;
    }

    default:
        sprintf(answer, "The UTC time is %d:%d:%d", info->tm_hour, info->tm_min, info->tm_sec);
        break;
    }
  
}

void TimeService::MeasureTimeLap()
{
    int diff;

    if (++countForTimeLaps == 2)
    {
        time(&endMeasure);
        diff = difftime(endMeasure, startMeasure);
        //if 3 min have passed - its a new 
        if (diff > (int)RequestType::ThreeMinMark)
        {
            --countForTimeLaps; //its like the client just started a measure
            startMeasure = endMeasure;
            endMeasure = 0;
            sprintf(answer, "A measure have been started!..");
        }
        else
        {
            sprintf(answer, "The measure stoped! The timelap was %d seconds:", diff);
            countForTimeLaps = 0;
        }
    }
    else
    {
        time(&startMeasure); // starting the measure.
        sprintf(answer, "A measure has been started!..");
    }

}
