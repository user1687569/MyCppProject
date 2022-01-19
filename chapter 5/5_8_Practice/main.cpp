//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>

const char* compareWord = "word";

int main()
{
    int n = 0;
    int inputFlag = 0;
    char inputString[100];
    char inputWord[20];
    char* pNew;
    char* pLast;
    std::cout << "Enter words(to stop, type the word done): " << std::endl;
    std::cin.getline(inputString, 100);
    pLast = inputString;

    while(1)
    {
        if(inputFlag == 1)
        {
            std::cout << "Enter words(to stop, type the word done): " << std::endl;
            std::cin.getline(inputString, 100);
            pLast = inputString;
            inputFlag = 0;
        }
        if(strchr(pLast, ' ') != NULL)
        {
            pNew = strchr(pLast, ' ');
            strncpy(inputWord, pLast, pNew - pLast);
            inputWord[pNew-pLast] = '\0';
        }
        else if(strchr(pLast, ' ') == NULL && strlen(pLast) != 0)
        {
            strcpy(inputWord, pLast);
            inputFlag = 1;
        }
        
        if(strcmp(inputWord, "word") == 0)
        {
            break;
        }
        n++;
        pLast = pNew + 1;
        std::cout << inputWord << std::endl;
    }

    std::cout << "You entered a total of " << n << " words." << std::endl;
    return 0;
}




