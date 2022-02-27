//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

const int NUM = 26;
const std::string wordlist[NUM] = {
        "apiary", "beetle", "cereal", "danger", "ensign", "florid",
        "garage", "health", "insult", "jackal", "keeper", "loaner",
        "manage", "nonce", "onset", "plaid", "quilt", "remote",
        "stolid", "train", "useful", "valid", "whence", "xenon",
        "yearn", "zippy"};


int main()
{
    std::srand(std::time(0));
    char play;
    std::cout << "Will you play a word game? <y/n> ";
    std::cin >> play;
    play = tolower(play);

    while(play == 'y')
    {
        std::string target = wordlist[std::rand() % NUM];
        std::cout << "target: " << target << std::endl;
        int length = target.length();
        std::string attempt(length, '-');
        std::string badchars;
        int guesses = 6;
        std::cout << "Guess my secret word. It has " << length
                  << " letters, and you guess" << std::endl
                  << "one letter at a time. You get " << guesses
                  << " wrong guesses." << std::endl;
        std::cout << "Your word: " << attempt << std::endl;

        while (guesses > 0 && attempt != target)
        {
            char letter;
            std::cout << "Guess a letter: ";
            std::cin >> letter;
            if(badchars.find(letter) != std::string::npos || attempt.find(letter) != std::string::npos)
            {
                std::cout << "You already guesses that. Try again." << std::endl;
                continue;
            }

            int loc = target.find(letter);
            if(loc == std::string::npos)
            {
                std::cout << "Oh, bad guess!" << std::endl;
                --guesses;

                // C++实现分配一个比实际字符串大的内存块，为字符串提供了增大空间
                // 然而，如果字符串不断增大，超过了内存块的大小，程序将分配一个
                // 大小为原来两倍的新内存块，以提供组后的增大空间，避免不断地分配新的内存块
                badchars += letter;
            }
            else
            {
                std::cout << "Good guess!" << std::endl;
                attempt[loc] = letter;
                // 对字符串中字符出现的位置后面循环查找
                loc = target.find(letter, loc + 1);
                while (loc != std::string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            std::cout << "Your word: " << attempt << std::endl;
            if(attempt != target)
            {
                if(badchars.length() > 0)
                    std::cout << "Bad choices: " << badchars << std::endl;
                std::cout << guesses << " bad guesses left" << std::endl;
            }
        }
        
        if(guesses > 0)
            std::cout << "That's right!" << std::endl;
        else
            std::cout << "Sorry, the word is " << target << std::endl;
        
        std::cout << "Will you play another? <y/n> ";
        std::cin >> play;
        play = tolower(play);
    }

    std::cout << "Bye" << std::endl;
    return 0;
}



