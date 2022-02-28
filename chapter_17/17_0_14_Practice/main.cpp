//Copyright (c) 2022 user1687569
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char * argv[])
{
    if(argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }

    std::ifstream fin;
    long count;
    long total = 0;
    char ch;

    for(int file = 1; file < argc; file++)
    {
        fin.open(argv[file]);
        if(!fin.is_open())
        {
            std::cerr << "Could not open " << argv[file] << std::endl;
            fin.clear();
            continue;
        }
        count = 0;
        while (fin.get(ch))
        {
            count++;
        }
        
        std::cout << count << " characters in " << argv[file] << std::endl;
        total += count;
        fin.clear();
        fin.close();
    }

    std::cout << total << " characters in all files\n";
    
    return 0;
}


