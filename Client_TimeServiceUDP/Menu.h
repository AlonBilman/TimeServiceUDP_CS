#pragma once
#include <iostream>
#include <cstdlib> 

class Menu
{
public:
    static int printMenu()
    {
        std::system("cls");
        int choice;
        std::cout << "\n\n";
        std::cout << "================================================================================\n";
        std::cout << "|                        Welcome to the Time Server Client                     |\n";
        std::cout << "================================================================================\n";
        std::cout << "|                         Please choose an option:                             |\n";
        std::cout << "+------------------------------------------------------------------------------+\n";
        std::cout << "| 1.  GetTime                      - Get the current date and time             |\n";
        std::cout << "| 2.  GetTimeWithoutDate           - Get the current time without date         |\n";
        std::cout << "| 3.  GetTimeSinceEpoch            - Get time since UNIX epoch                 |\n";
        std::cout << "| 4.  GetClientToServerDelayEstimation - Estimate client-server delay          |\n";
        std::cout << "| 5.  MeasureRTT                   - Measure Round-Trip Time                   |\n";
        std::cout << "| 6.  GetTimeWithoutDateOrSeconds  - Get the current time without seconds      |\n";
        std::cout << "| 7.  GetYear                      - Get the current year                      |\n";
        std::cout << "| 8.  GetMonthAndDay               - Get the current month and day             |\n";
        std::cout << "| 9.  GetSecondsSinceBeginningOfMonth - Get seconds since start of month       |\n";
        std::cout << "| 10. GetWeekOfYear                - Get the week number of the year           |\n";
        std::cout << "| 11. GetDaylightSavings           - Get daylight saving status                |\n";
        std::cout << "| 12. GetTimeWithoutDateInCity     - Get time without date for a city          |\n";
        std::cout << "| 13. MeasureTimeLap               - Measure time lapse between requests       |\n";
        std::cout << "| 0.  Exit                         - Exit the program                          |\n";
        std::cout << "+------------------------------------------------------------------------------+\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::system("cls");

        if (choice == 12)
        {
            int secondChoice = 0;
            std::cout << "\n\n";
            std::cout << "===============================================================================\n";
            std::cout << "|                    Welcome! Please choose a city:                           |\n";
            std::cout << "===============================================================================\n";
            std::cout << "|                     What city would you like?                               |\n";
            std::cout << "+-----------------------------------------------------------------------------+\n";
            std::cout << "| 1. Doha                                                                     |\n";
            std::cout << "| 2. Prague                                                                   |\n";
            std::cout << "| 3. New York                                                                 |\n";
            std::cout << "| 4. Berlin                                                                   |\n";
            std::cout << "+-----------------------------------------------------------------------------+\n";
            std::cin >> secondChoice;
            choice = choice * 10 + secondChoice; //to make it 3 digits, for example 123 => 12 with the NewYork option
        }

        std::system("cls");

        return choice;

    }
};

