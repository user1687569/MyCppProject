//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <exception>
#include <typeinfo>
#include "sales.h"


int main()
{
    double vals1[12] =
    {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };

    double vals2[12] = 
    {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };

    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("Blogstar", 2012, vals2, 12);

    std::cout << "First try block: " << std::endl;
    try{
        int i;
        std::cout << "Year = " << sales1.Year() << std::endl;
        for(i = 0; i < 12; i++)
        {
            std::cout << sales1[i] << ' ';
            if(i % 6 == 5)
                std::cout << std::endl;
        }

        std::cout << "Year = " << sales2.Year() << std::endl;
        std::cout << "Label = " << sales2.Label() << std::endl;
        for(i = 0; i <= 12; i++)    // bad index, max value of i should be 11
        {
            std::cout << sales2[i] << ' ';
            if(i % 6 == 5)
                std::cout << std::endl;
        }
        std::cout << "End of try block 1." << std::endl; 
    }
    catch(Sales::bad_index & bad)
    {
        std::cout << bad.what();
        if(typeid(LabeledSales::nbad_index) == typeid(bad))
        {
            std::cout << "Company: " << ((LabeledSales::nbad_index &) bad).label_val() << std::endl;
        }
        else
            std::cout << "Do not use typeid" << std::endl;
        std::cout << "bad index: " << bad.bi_val() << std::endl;
    }

    std::cout << std::endl << "Next try block: " << std::endl;
    try{
        sales2[2] = 37.5;
        sales1[20] = 23345;     // bad index, max value of (i - sales1[i]) should be 11
        std::cout << "End of try block 2." << std::endl;
    }
    catch(Sales::bad_index & bad)
    {
        std::cout << bad.what();
        if(typeid(LabeledSales::nbad_index) == typeid(bad))
        {
            std::cout << "Company: " << ((LabeledSales::nbad_index &) bad).label_val() << std::endl;
        }
        std::cout << "bad index: " << bad.bi_val() << std::endl;
    }

    std::cout << "Done" << std::endl;
    return 0;
}

