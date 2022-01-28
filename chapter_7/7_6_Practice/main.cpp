//Copyright (c) 2022 user1687569
#include <iostream>

int  Fill_array(double array[], int length);
void Show_array(const double array[], int length);
void Reverse_array(double array[], int length);

int main()
{
    int num;
    std::cout << "Please enter the number of array elements: ";

    while(!(std::cin >> num))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Bad input; Please enter a number: ";
    }

    double array[num];
    num = Fill_array(array, num);
    Show_array(array, num);

    Reverse_array(array, num);
    Show_array(array, num);

    return 0;
}


int Fill_array(double array[], int length)
{
    int i = 0;

    std::cout << "Please enter value(double) to fill array: " << std::endl;
    while(std::cin >> array[i] && i < length)
    {
        i++;
    }

    return i;
}


void Show_array(const double array[], int length)
{
    std::cout << "Double array list: ";
    for(int i = 0; i < length; i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}


void Reverse_array(double array[], int length)
{
    double temp;
    for(int i = 0; i < length / 2; i++)
    {
        temp = array[i];
        array[i] = array[length - i - 1];
        array[length - i - 1] = temp;
    }
}
