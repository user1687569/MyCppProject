//Copyright (c) 2022 user1687569
#include <iostream>
#include <valarray>
#include <cstdlib>

const int SIZE = 12;
typedef std::valarray<int> vint;
void show(const vint & v, int cols);


int main()
{
    vint valint(SIZE);

    int i;
    for(i = 0; i < SIZE; i++)
        valint[i] = std::rand() % 10;
    std::cout << "Original array: " << std::endl;
    show(valint, 3);

    vint vcol(valint[std::slice(1, 4, 3)]);
    std::cout << "Second column: " << std::endl;
    show(vcol, 1);

    vint vrow(valint[std::slice(3, 3, 1)]);
    std::cout << "Second row: " << std::endl;
    show(vrow, 3);

    valint[std::slice(2, 4, 3)] = 10;
    std::cout << "Set last column to 10: " << std::endl;
    show(valint, 3);

    std::cout << "Set first column to sum of next two: " << std::endl;
    valint[std::slice(0, 4, 3)] = vint(valint[std::slice(1, 4, 3)])
                           + vint(valint[std::slice(2, 4, 3)]);
    show(valint, 3);
    return 0;
}


void show(const vint & v, int cols)
{
    int lim = v.size();
    for(int i = 0; i < lim; i++)
    {
        std::cout.width(3);
        std::cout << v[i];
        if(i % cols == cols - 1)
            std::cout << std::endl;
        else
            std::cout << ' ';
    }
    if(lim % cols != 0)
        std::cout << std::endl;
}




