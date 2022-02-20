//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "practice.h"


Frabjous::Frabjous(const char * s)
{
    strcpy(fab, s);
}


Gloam::Gloam(int g, const char * s)
    : glip(g), fb(s)
{
}


Gloam::Gloam(int g, const Frabjous & f)
    : glip(g), fb(f)
{
}

void Gloam::tell()
{
    std::cout << glip << std::endl;
    fb.tell();
}






