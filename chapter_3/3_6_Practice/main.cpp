//Copyright (c) 2022 user1687569
#include <iostream>
#include <climits>
#include <cmath>

int main()
{
    double mile;
    double gallon;
    double gasConsumpton;
    std::cout << "Enter driving distance (unit: mile): ";
    std::cin >> mile;
    std::cout << "Enter used gas (unit: gallon): ";
    std::cin >> gallon;
    gasConsumpton = mile / gallon;
    std::cout << "America style Gas consumption is " << gasConsumpton << " mile/gallon.";

    double litre;
    double hundredKm;
    std::cout << "Enter used gas (unit: litre): ";
    std::cin >> litre;
    std::cout << "Enter driving distance (unit: hundredKm): ";
    std::cin >> hundredKm;
    gasConsumpton = litre / hundredKm;
    std::cout << "Europe style Gas consumption is " << gasConsumpton << " litre/hundredKm.";
    return 0;
}


