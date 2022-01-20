//Copyright (c) 2022 user1687569
#include <iostream>

int main()
{
    const char* years[3] = 
    {
        "First year",
        "Second year",
        "Third year"
    };

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

    int i, j;
    int sales[3][12] = {0};
    int sum[3] = {0};
    for(i = 0; i < 3; i++)
    {   
        for(j = 0; j < 12; j++)
        {
            std::cout << "Enter " << years[i] << " " << months[j] << " sale: ";
            std::cin >> sales[i][j];
            sum[i] += sales[i][j];
        }
    }

    std::cout << std::endl <<"======Sale summary shows below======" << std::endl;
    for(i = 0; i < 3; i++)
        std::cout << years[i] << ": " << sum[i] << std::endl;
    return 0;
}




