//Copyright (c) 2022 user1687569
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char * argv[])
{
    std::string lit = "It was a dark and stormy day, and "
                      " the full moon glowed brilliantly. ";
    std::istringstream instr(lit);
    std::string word;
    while (instr >> word)   // read a word one time
    {
        std::cout << word << std::endl;
    }
    
    return 0;
}

// It
// was
// a
// dark
// and
// stormy
// day,
// and
// the
// full
// moon
// glowed
// brilliantly.


