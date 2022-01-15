//Copyright (c) 2022 user1687569
#include <iostream>
#include <climits>
#include <cmath>

const double hundredKm_Mile_Factor = 62.14;
const double gallon_Litre_Factor = 3.875;



int main()
{
    double europeStyle, americaStyle;
    std::cout << "Enter Europen style gas consumption (unit: Litre/hundredKm): ";
    std::cin >> europeStyle;
    americaStyle = (hundredKm_Mile_Factor * gallon_Litre_Factor) / europeStyle;
    std::cout << "Afer conversion, America style is " << americaStyle << " mile/gallon." << std::endl;

    std::cout << "Enter America style gas consumption (unit: mile/gallon): ";
    std::cin >> americaStyle;
    europeStyle =  (hundredKm_Mile_Factor * gallon_Litre_Factor) / americaStyle;
    std::cout << "After conversion, Europe style is " << europeStyle << " Litre/hundredKm.";

    return 0;
}




