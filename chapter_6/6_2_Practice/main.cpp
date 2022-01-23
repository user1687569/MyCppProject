//Copyright (c) 2022 user1687569
#include <iostream>
#include <array>

const int ARRAYSIZE = 10;

int main()
{
    int i;
    int count;
    int numOverAverage = 0;
    double donation;
    double sum = 0.0;
    double average;
    std::array<double, ARRAYSIZE> donationArray;

    std::cout << "Please enter 10 donation value: " << std::endl;
    for(i = 0; i < 10 && std::cin >> donation; i++)
    {
        donationArray[i] = donation;
        sum += donation;
    }

    count = i;
    average = sum / count;
    for(i = 0; i < count; i++)
    {
        if(donationArray[i] > average)
            numOverAverage += 1;
    }

    std::cout << "You entered " << count << " donation value." << std::endl;
    std::cout << "Average value is: " << average << std::endl;
    std::cout << numOverAverage << " donation value above average." << std::endl;

    return 0;
}




