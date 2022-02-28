//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstdio>

int main(int argc, char * argv[])
{
    std::cout << "This system can generate up to " << TMP_MAX
              << " temporary names of up to " << L_tmpnam
              << " characters.\n";
    char pszName[L_tmpnam] = {'\0'};
    std::cout << "Here are ten names:\n";
    for(int i = 0; 10 > i; i++)
    {
        tmpnam(pszName);
        std::cout << pszName << std::endl;
    } 

    return 0;
}


