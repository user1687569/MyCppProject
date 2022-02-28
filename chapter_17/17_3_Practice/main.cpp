//Copyright (c) 2022 user1687569
#include <iostream>
#include <fstream>


int main(int argc, char * argv[])
{
    if(argc < 3)
    {
        std::cerr << "Usage: " << argv[0]
                  << " source-file target-file" << std::endl;
    }

    std::ifstream fin(argv[1], std::ios_base::in);
    if(!fin.is_open())
    {
        std::cerr << "Can't open " << argv[1] << "for input" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ofstream fout(argv[2], std::ios_base::out);
    if(!fout.is_open())
    {
        std::cerr << "Can't open " << argv[1] << "for output" << std::endl;
        exit(EXIT_FAILURE);
    }

    char ch;
    while (fin.get(ch))
    {
        fout.put(ch);
    }

    std::cout << "Content of " << argv[1] << " copied to " << argv[2] << std::endl;
    fin.close();
    fout.close();
    
    
    return 0;
}

