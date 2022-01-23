//Copyright (c) 2022 user1687569
#include <iostream>

void showMenu();
void carnivore();
void pianist();
void tree();
void game();
void defaultCase();

int main()
{
    char ch;

    showMenu();
    std::cin >> ch;

    while (ch != 'q')
    {
        switch (ch)
        {
        case 'c':
            carnivore();
            break;
        case 'p':
            pianist();
            break;
        case 't':
            tree();
            break;
        case 'g':
            game();
            break;
        default:
            defaultCase();
            break;
        }
        showMenu();
        std::cin >> ch;
    }
    
    std::cout << "Byebye!" << std::endl;
    return 0;
}

void showMenu()
{
    std::cout << "Please enter one of the following choices: \n"
                 "c) carnivore           p) pianist\n"
                 "t) tree                g) game\n"
                 "q) quit\n";
}

void carnivore()
{
    std::cout << "Tiger is a kind of carnivore." << std::endl;
}

void pianist()
{
    std::cout << "Li YunDi is a pianist." << std::endl;
}

void tree()
{
    std::cout << "Tree is a kind of plant." << std::endl;
}

void game()
{
    std::cout << "Life is an intresting game." << std::endl;
}

void defaultCase()
{
    std::cout << "[Warning]Please enter character: c, p, t, g: " << std::endl;
}


