//Copyright (c) 2022 user1687569
#include <iostream>
#include "practice.h"


int main()
{
    Frabjous frabOne("Hello");
    frabOne.tell();

    Gloam gloamZero;
    gloamZero.tell();

    Gloam gloamOne(1, "practice Gloam");
    gloamOne.tell();

    Gloam gloamTwo(2, frabOne);
    gloamTwo.tell();

    return 0;
}


