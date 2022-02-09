//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
// #include <string>

struct stringy
{
    char *str;
    int ct;
};

void set(stringy & destination, const char * origin);

void show(const stringy & str);
void show(const stringy & str, int count);
void show(const char * str);
void show(const char * str, int count);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    
    testing[0] = 'D';
    testing[1] = 'u';

    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}


void set(stringy & destination, const char * origin)
{
    int length;
    length = strlen(origin);
    destination.str = new char[length + 1];
    strcpy(destination.str, origin);
    destination.ct = length;
}


void show(const stringy &str)
{
    std::cout << str.str << std::endl;
}


void show(const stringy &str, int count)
{
    for(int i = 0; i < count; i++)
        show(str);
}


void show(const char * str)
{
    std::cout << str << std::endl;
}


void show(const char * str, int count)
{
    for(int i = 0; i < count; i++)
        show(str);
}

