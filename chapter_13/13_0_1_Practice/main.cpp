//Copyright (c) 2022 user1687569
#include <iostream>
#include "tabletennis.h"


int main()
{
    // TableTennisPlayer player1("Chuck", "Blizzard", true);
    // TableTennisPlayer player2("Tara", "Boomdea", false);

    // player1.Name();
    // if(player1.HasTable())
    //     std::cout << ": has a table." << std::endl;
    // else
    //     std::cout << ": hasn't a table." << std::endl;
    
    // player2.Name();
    // if(player2.HasTable())
    //     std::cout << ": has a table" << std::endl;
    // else
    //     std::cout << ": hasn't a table" << std::endl;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer ratedPlayer1(1140, "Mallory", "Duck", true);

    ratedPlayer1.Name();
    if(ratedPlayer1.HasTable())
        std::cout << ": has a table." << std::endl;
    else
        std::cout << ": hasn't a table." << std::endl;
    
    player1.Name();
    if(player1.HasTable())
        std::cout << ": has a table" << std::endl;
    else
        std::cout << ": hasn't a table." << std::endl;
    
    std::cout << "Name: ";
    ratedPlayer1.Name();
    std::cout << "; Rating: " << ratedPlayer1.Rating() << std::endl;

    RatedPlayer ratedPlayer2(1212, player1);
    std::cout << "Name: ";
    ratedPlayer2.Name();
    std::cout << "; Rating: " << ratedPlayer2.Rating() << std::endl;

    return 0;
}

