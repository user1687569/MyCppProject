//Copyright (c) 2022 user1687569
#include <iostream>
#include <climits>
#include <cmath>

const int inchFeetFactor = 12;
const double inchMeterFactor = 0.0254;
const double kiloPoundFactor = 2.2;

int main()
{
    int feet, inch, pound;
    double index;
    std::cout << "=====Body Mass Index=====" << std::endl;
    std::cout << "Please input your height: " << std::endl;
    std::cout << "Feet: ";
    std::cin >> feet;
    std::cout << "Inches:";
    std::cin >> inch;
    std::cout << "Please input your weight (unit: pound): ";
    std::cout << "Pound: ";
    std::cin >> pound;
    index = pound * kiloPoundFactor / pow((((feet * inchFeetFactor) + inch) * inchMeterFactor), 2);
    std::cout << "After calculation, your body mass index is " << index << std::endl;
    return 0;
}

