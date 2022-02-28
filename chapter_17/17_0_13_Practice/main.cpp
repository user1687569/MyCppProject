//Copyright (c) 2022 user1687569
#include <iostream>
#include <fstream>
#include <string>


int main()
{
    std::string filename;
    
    std::cout << "Enter name for new file: ";
    std::cin >> filename;

    std::ofstream fout(filename.c_str());

    fout << "For your eyes only!\n";
    std::cout << "Enter your secret number: ";
    float secret;
    std::cin >> secret;
    fout << "Your secret number is " << secret << std::endl;
    fout.close();

    std::ifstream fin(filename.c_str());
    std::cout << "Here are the contents of " << filename << ":\n";
    char ch;
    while (fin.get(ch))
        std::cout << ch;
    
    std::cout << "Done\n";
    fin.close();
    
    return 0;
}


