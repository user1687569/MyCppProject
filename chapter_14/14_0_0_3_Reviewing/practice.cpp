//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "practice.h"


Frabjous::Frabjous(const char * s)
{
    strcpy(fab, s);
}


Gloam::Gloam(int g, const char * s)
    : glip(g), Frabjous(s)
{
}


Gloam::Gloam(int g, const Frabjous & f)
    : glip(g), Frabjous(f)
{
}

void Gloam::tell()
{
    Frabjous::tell();
    std::cout << glip << std::endl;
}






