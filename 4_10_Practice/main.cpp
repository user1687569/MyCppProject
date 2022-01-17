//Copyright (c) 2022 user1687569
#include <iostream>
#include <array>

int main()
{
    std::array<double, 3> score;
    double averageScore;

    std::cout << "Enter first score: ";
    std::cin >> score[0];
    averageScore = score[0];
    std::cout << "Time: 1, average score: " << averageScore << std::endl;

    std::cout << "Enter second score: ";
    std::cin >> score[1];
    averageScore = (score[0] + score[1]) / 2;
    std::cout << "Time: 2, average score: " << averageScore << std::endl;
    
    std::cout << "Enter third score: ";
    std::cin >> score[2];
    averageScore = (score[0] + score[1] + score[2]) / 3;
    std::cout << "Time: 3, average score: " << averageScore << std::endl;

    return 0;
}




