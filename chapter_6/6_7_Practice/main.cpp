//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <cctype>

int main()
{   
    std::string words;
    int numOfVowel = 0;
    int numOfConsonant = 0;
    int numOfOther = 0;

    std::cout << "Enter words (q to quit): " << std::endl;

    while(std::cin >> words && words != "q")
    {
        if(isalpha(words.front()))
        {
            if(words.front() == 'A' || words.front() == 'a' ||
               words.front() == 'E' || words.front() == 'e' ||
               words.front() == 'I' || words.front() == 'i' ||
               words.front() == 'O' || words.front() == 'o' ||
               words.front() == 'U' || words.front() == 'u')
            {
                numOfVowel += 1;
            }
            else 
                numOfConsonant += 1;
        }
        else
            numOfOther += 1;
    }

    std::cout << numOfVowel << " words beginning with vowels" << std::endl;
    std::cout << numOfConsonant << " words beginning with consonants" << std::endl;
    std::cout << numOfOther << " others" << std::endl;

    return 0;
}



