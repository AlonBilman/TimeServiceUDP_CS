


enum class RequestType {

    GetTime = 1,
    GetTimeWithoutDate,
    GetTimeSinceEpoch,
    GetClientToServerDelayEstimation,
    MeasureRTT,
    GetTimeWithoutDateOrSeconds,
    GetYear,
    GetMonthAndDay,
    GetSecondsSinceBeginingOfMonth,
    GetWeekOfYear,
    GetDaylightSavings,
    GetTimeWithoutDateInCity,
    MeasureTimeLap,

    //citys 
    Doha = 1,
    Prague = 2,
    New_York = 3,
    Berlin = 4,


    ThreeDigits = 99,
    ThreeMinMark = 180 //in seconds!

};