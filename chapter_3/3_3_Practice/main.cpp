//Copyright (c) 2022 user1687569
#include <iostream>
#include <climits>
#include <cmath>

// latitude of FuZhou: 26.08 => 26.4.48

const int minuteDegreeFactor = 60;
const int secondMinuteFactor = 60;

int main()
{
    double degree, minute, second;
    double latitude;
    std::cout << "Enter a latitude in degrees, minutes, and seconds: " << std::endl;
    std::cout << "First, enter the degrees: ";
    std::cin >> degree;
    std::cout << "Next, enter the minutes of arc: ";
    std::cin >> minute;
    std::cout << "Finally, enter the seconds of arc: ";
    std::cin >> second;
    latitude = ((second / secondMinuteFactor + minute) / minuteDegreeFactor) + degree;
    std::cout << degree << " degrees, " << minute << " minutes, " << second << " seconds = " << latitude << " degress." << std::endl;
    return 0;
}

