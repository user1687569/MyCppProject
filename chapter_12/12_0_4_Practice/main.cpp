//Copyright (c) 2022 user1687569
#include <iostream>
#include "placenew.h"


int main()
{   
    char *buffer = new char[BUF];

    PlaceNew *p1, *p2;
    p1 = new (buffer) PlaceNew;
    p2 = new PlaceNew("Heap1", 20);
    std::cout << "Memory block addresses: " << std::endl
              << "buffer: " << (void *)buffer
              << "     heap: " << p2 << std::endl;
    std::cout << "Memory contents: " << std::endl;
    std::cout << p1 << ": ";
    p1->Show();
    std::cout << p2 << ": ";
    p2->Show();


    PlaceNew *p3, *p4;
    p3 = new (buffer + sizeof(PlaceNew)) PlaceNew("Better Idea", 6);
    p4 = new PlaceNew("Heap2", 10);
    std::cout << "Memory contents: " << std::endl;
    std::cout << p3 << ": ";
    p3->Show();
    std::cout << p4 << ": ";
    p4->Show();

    delete p2;
    delete p4;

    p3->~PlaceNew();
    p4->~PlaceNew();
    delete [] buffer;
    std::cout << "Done!" << std::endl;
    return 0;
}



