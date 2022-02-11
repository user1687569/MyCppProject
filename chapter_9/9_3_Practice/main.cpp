//Copyright (c) 2022 user1687569
#include <iostream>
#include <new>
#include <cstring>

const int LEN = 512;
char buffer[LEN];

struct chaff        //chaff: 糠，谷壳
{   
    char dross[20]; //dross：渣滓，浮渣，碎屑
    int slag;       //slag：炉渣，矿渣
};


int main()
{
    int i;
    chaff * pChaff1 = new (buffer) chaff[2];
    
    strcpy(pChaff1[0].dross, "iphone");
    pChaff1[0].slag = 7;
    strcpy(pChaff1[1].dross, "HuaWei");
    pChaff1[1].slag = 8;

    std::cout << "Show Chaff Info: " << std::endl;
    for(i = 0; i < 2; i++)
    {
        std::cout << "Num: " << i + 1;
        std::cout << ", dross: " << pChaff1[i].dross;
        std::cout << ", slag: " << pChaff1[i].slag << std::endl;
    }

    char * buffer2 = new char[LEN];
    chaff * pChaff2 = new (buffer2) chaff[2];
    
    strcpy(pChaff2[0].dross, "Sun");
    pChaff2[0].slag = 10;
    strcpy(pChaff2[1].dross, "Moon");
    pChaff2[1].slag = 20;

    std::cout << "Show Chaff2 Info: " << std::endl;
    for(i = 0; i < 2; i++)
    {
        std::cout << "Num: " << i + 1;
        std::cout << ", dross: " << pChaff2[i].dross;
        std::cout << ", slag: " << pChaff2[i].slag << std::endl;
    }

    delete [] buffer2;

    return 0;
}


