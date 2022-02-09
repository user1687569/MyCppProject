//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <cstring>
#include <limits>

template<typename T>
T maxn(T t[], int n);

template <> char * maxn<char*>(char *[], int n);


int main()
{
    int nList[] = {1, 3, 5, 7, 9, 11};
    double dList[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int nMax = INT16_MIN;
    double dMax = INT64_MIN;

    nMax = maxn(nList, 6);
    std::cout << "Max integer is: " << nMax << std::endl;

    dMax = maxn(dList, 4);
    std::cout << "Max double value is: " << dMax << std::endl;

    char *strList[] = 
                    {
                        (char *)"Let's",
                        (char *)"play",
                        (char *)"basketball",
                        (char *)"tommorrow",
                        (char *)"OK?"
                    };
    char *p = NULL;
    p = maxn(strList, 5);
    std::cout << "Max string length content is: " << p << std::endl; 

    return 0;
}


template<typename T>
T maxn(T t[], int n)
{
    T max = t[0];
    for(int i = 1; i < n; i++)
        max = max >= t[i] ? max : t[i];

    return max;
}

template <> char * maxn<char *>(char * strList[], int n)
{
    char *p = strList[0];
    for(int i = 1; i < n; i++)
        p =  strlen(p) >= strlen(strList[i]) ? p : strList[i];
    
    return p;
}

