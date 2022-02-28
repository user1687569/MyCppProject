//Copyright (c) 2022 user1687569
#ifndef _STORE_H_
#define _STORE_H_
#include <iostream>
#include <string>
#include <fstream>

class Store
{
private:
    std::ostream & os;

public:
    Store(std::ostream & o) : os(o) {}
    inline void operator()(const std::string & s);
    // {
    //     std::size_t len = s.length();
    //     // store string length
    //     os.write((char *)&len, sizeof(std::size_t));
    //     // store string data
    //     os.write(s.data(), len);
    // }
};


void Store::operator()(const std::string & s)
{
    std::size_t len = s.length();

    // store string length
    os.write((char *)&len, sizeof(std::size_t));

    // store string data
    os.write(s.data(), len);
}


#endif
