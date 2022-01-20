//Copyright (c) 2022 user1687569
#include <iostream>
#include <climits>
#include <cmath>

const int secondMinuteFactor = 60;
const int minuteHourFactor = 60;
const int hourDayFactor = 24;

int main()
{
    long secondInput;
    int day, hour, minute, second;
    std::cout << "Enter the number of seconds: ";
    std::cin >> secondInput;

    day = secondInput / (secondMinuteFactor * minuteHourFactor * hourDayFactor);
    hour = (secondInput - day * secondMinuteFactor * minuteHourFactor * hourDayFactor) / (secondMinuteFactor * minuteHourFactor);
    minute = (secondInput - day * secondMinuteFactor * minuteHourFactor * hourDayFactor - hour * secondMinuteFactor * minuteHourFactor) / secondMinuteFactor;
    second = secondInput % secondMinuteFactor;

    std::cout << secondInput << " seconds = ";
    std::cout << day << " days, ";
    std::cout << hour << " hours, ";
    std::cout << minute << " minutes, ";
    std::cout << second << " seconds." << std::endl;

    return 0;
}


