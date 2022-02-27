//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>


int main()
{
    std::string one("Lottery Winner!");
    std::cout << one << std::endl;

    std::string two(20, '$');
    std::cout << two << std::endl;

    std::string three(one);
    std::cout << three << std::endl;

    one += " Oops!";
    std::cout << one << std::endl;

    two = "Sorry! That was ";
    three[0] = 'P';
    
    std::string four;
    four = two + three;
    std::cout << four << std::endl;

    char alls[] = "All's well that ends well";
    std::string five(alls, 20);
    std::cout << five << std::endl;

    std::string six(alls + 6, alls + 10);
    std::cout << six << std::endl;

    std::string seven(&five[6], &five[10]);
    std::cout << seven << "..." << std::endl;

    std::string eight(four, 7, 16);
    std::cout << eight << " in motion!" << std::endl;

    return 0;
}

// Run Result: 
// Lottery Winner!
// $$$$$$$$$$$$$$$$$$$$
// Lottery Winner!
// Lottery Winner! Oops!
// Sorry! That was Pottery Winner!
// All's well that ends
// well
// well...
// That was Pottery in motion!




