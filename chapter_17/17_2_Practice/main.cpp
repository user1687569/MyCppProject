//Copyright (c) 2022 user1687569
#include <iostream>
#include <fstream>

int main(int argc, char * argv[])
{
    if(argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }

    std::ofstream fout;
    long count;
    long total = 0;
    char ch;

    fout.open(argv[1]);
    if(!fout.is_open())
    {
        std::cerr << "Could not open " << argv[1] << std::endl;
        fout.clear();
        return -1;
    }

    char str[50];
    std::cout << "Please enter command(End with '$'): ";
    std::cin.get(str, 50, '$');

    fout << str;
    fout.clear();
    fout.close();
    
    return 0;
}
