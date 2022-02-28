//Copyright (c) 2022 user1687569
#include <iostream>
#include <fstream>


int main(int argc, char * argv[])
{
    if(argc < 4)
    {
        std::cerr << "Usage: " << argv[0]
                  << " source-file target-file" << std::endl;
    }

    std::ifstream fin1(argv[1], std::ios_base::in);
    std::ifstream fin2(argv[1], std::ios_base::in);
    if(!fin1.is_open() || !fin2.is_open())
    {
        std::cerr << "Can't open " << argv[1] << "or " << argv[2] << "for input" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ofstream fout(argv[3], std::ios_base::out);
    if(!fout.is_open())
    {
        std::cerr << "Can't open " << argv[3] << "for output" << std::endl;
        exit(EXIT_FAILURE);
    }

    char ch;
    while (!fin1.eof() || !fin2.eof())
    {
        if(!fin1.eof())
        {
            while (fin1.get(ch) && ch != '\n')
            {
                fout << ch;
            }
            fout << ' ';
        }

        if(!fin2.eof())
        {
            while (fin2.get(ch) && ch != '\n')
            {
                fout << ch;
            }
            fout << ' ';
        }
        fout << '\n';
    }
    

    std::cout << "Content of " << argv[1] << " and " << argv[2] << " copied to " << argv[3] << std::endl;
    fin1.close();
    fin2.close();
    fout.close();
    
    
    return 0;
}


