//Copyright (c) 2022 user1687569
#include <iostream>


int main()
{
    char ch;

    while (std::cin.get(ch))
    {
        if(ch != '#')
            std::cout << ch;
        else
        {
            std::cin.putback(ch);   // 读取#字符，然后使用putback()将它插回到输入中
            break;
        }
    }

    if(!std::cin.eof())
    {
        std::cin.get(ch);
        std::cout << std::endl << ch << " is next input character.\n";
    }
    else
    {
        std::cout << "End of file reached.\n";
        std::exit(0);
    }

    while (std::cin.peek() != '#')  // 在读取之前使用peek()查看下一个字符
    {
        std::cin.get(ch);
        std::cout << ch;
    }
    if(!std::cin.eof())
    {
        std::cin.get(ch);
        std::cout << std::endl << ch << " is next input character.\n";
    }    
    else
        std::cout << "End of file reached." << std::endl;

    return 0;
}


