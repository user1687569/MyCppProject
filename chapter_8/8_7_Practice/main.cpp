//Copyright (c) 2022 user1687569
#include <iostream>


template <typename T>
void ShowArray(T arr[], int n);

template<typename T>
void ShowArray(T * arr[], int n);

template <typename T>
double SumArray(T arr[], int n);

template <typename T>
double SumArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3]
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    
    double * pd[3];

    for(int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;

    std::cout << "Listing Mr.E's counts of things: " << std::endl;
    ShowArray(things, 6);
    SumArray(things, 6);

    std::cout << "Listing Mr.E's debts: " << std::endl;
    ShowArray(pd, 3);
    SumArray(pd, 3);

    return 0;
}


template <typename T>
void ShowArray(T arr[], int n)
{
    std::cout << "template A" << std::endl;
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}


template <typename T>
void ShowArray(T * arr[], int n)
{
    std::cout << "template B" << std::endl;
    for(int i = 0; i < n; i++)
        std::cout << *arr[i] << ' ';
    std::cout << std::endl;
}


template <typename T>
double SumArray(T arr[], int n)
{
    double sum = 0.0;
    std::cout << "template C" << std::endl;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    std::cout << "Array sum is: " << sum << std::endl;
}


template <typename T>
double SumArray(T * arr[], int n)
{
    double sum = 0.0;
    std::cout << "template D" << std::endl;
    for(int i = 0; i < n; i++)
        sum += *arr[i];
    std::cout << "Array sum is: " << sum << std::endl;
}

