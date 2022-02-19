//Copyright (c) 2022 user1687569
#include <iostream>
#include "cd.h"

void Bravo(const Cd & disk);

int main()
{
    Cd c1((char *)"Beatles", (char *)"Capitol", 14, 35.5);
    Classic c2 = Classic((char *)"Piano Sonata in B flat, Fantasia in C",
                        (char *)"Alfred Brendel", (char *)"Philips", 2, 57.17);    
    Cd *pcd = &c1;

    std::cout << "Using object directly: " << std::endl;
    c1.Report();    // use Cd method
    c2.Report();    // use Classic method

    std::cout << "Using type cd * pointer to objects: " << std::endl;
    pcd->Report();  // use Cd method for cd object
    pcd = &c2;
    pcd->Report();  // use Classic method for classic object

    std::cout << "Calling a function with a Cd reference argument: " << std::endl;
    Bravo(c1);
    Bravo(c2);

    std::cout << "Testing assignment: " << std::endl;
    Classic copy;
    copy = c2;
    copy.Report(); 

    return 0;
}


void Bravo(const Cd & disk)
{
    disk.Report();
}


