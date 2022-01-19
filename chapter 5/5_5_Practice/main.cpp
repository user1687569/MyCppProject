//Copyright (c) 2022 user1687569
#include <iostream>

int main()
{
    const char* months[12] = 
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    int i;
    int sales[12];
    int sum = 0;
    for(i = 0; i < 12; i++)
    {
        std::cout << "Enter " << months[i] << " sale: ";
        std::cin >> sales[i];
        sum += sales[i];
    }

    std::cout << "Total sale is: " << sum << std::endl;
    return 0;
}




