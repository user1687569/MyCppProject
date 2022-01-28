//Copyright (c) 2022 user1687569
#include <iostream>

const int Max = 5;

double * fill_array(double *pBegin, int limit);
void show_array(const double *pBegin, const double *pEnd);
void revalue(double r, double *pBegin, double *pEnd);

int main()
{
    double *properties = new double[Max];
    double *pEnd;

    pEnd = fill_array(properties, Max);
    show_array(properties, pEnd);
    if(pEnd > properties)
    {
        std::cout << "Enter revaluation factor: ";
        double factor;
        while(!(std::cin >> factor))
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input; Please enter a number: ";
        }

        revalue(factor, properties, pEnd);
        show_array(properties, pEnd);
    }

    std::cout << "Done." << std::endl;
    std::cin.get();
    std::cin.get();

    delete [] properties;

    return 0;
}


double * fill_array(double *pBegin, int limit)
{
    double temp;
    int i;
    double *pEnd = pBegin;
    for(i = 0; i < limit; i++)
    {
        std::cout << "Enter value #" << (i + 1) << ": ";
        std::cin >> temp;
        if(!std::cin)
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input; input process terminated." << std::endl;
            break;
        }
        else if(temp < 0)
            break;
        *pEnd++ = temp;
    }
    return pEnd;
}


void show_array(const double *pBegin, const double *pEnd)
{
    int i = 0;
    const double *p;
    p = pBegin;
    while(p != pEnd)
    {
        std::cout << "Property #" << (i + 1) << ": $";
        std::cout << *p++ << std::endl;
        i++;
    }
}


void revalue(double r, double *pBegin, double *pEnd)
{
    double *p;
    p = pBegin;

    while (p != pEnd)
        *p++ *= r;
}



