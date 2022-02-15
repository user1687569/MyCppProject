//Copyright (c) 2022 user1687569
#include <iostream>
#include "stoneweight.h"


int main()
{
    StoneWeight incognito = 275; // use StoneWeight(double lbs), converting int to double
    StoneWeight wolfe(285.7);
    StoneWeight taft(21, 8.8);

    std::cout << "The celebrity weighed ";
    std::cout << incognito;

    std::cout << "The detective weighed ";
    std::cout << wolfe;

    std::cout << "The President weighed ";
    std::cout << taft;

    incognito = 276.8;
    std::cout << "After dinner, the celebrity weighed ";
    std::cout << incognito;
    incognito.int_pounds_mode();
    std::cout << incognito;
    incognito.float_pounds_mode();
    std::cout << incognito;

    taft = 325;
    std::cout << "After dinner, the President weighed ";
    taft.float_pounds_mode();
    std::cout << taft;

    StoneWeight pingpong(10, 8);
    double pingpongweight = pingpong;
    int nPingpongweight = pingpong;
    std::cout << "pingpong weight(double): " << pingpongweight << std::endl;
    std::cout << "pingpong weight(integer): " << nPingpongweight << std::endl;

    StoneWeight pingpong2;
    pingpong2 = pingpong * 2.0;
    std::cout << "pingpong2 weighed(integer): ";
    std::cout << pingpong2;
    std::cout << "pingpong2 weighed(double): ";
    pingpong2.float_pounds_mode();
    std::cout << pingpong2;


    StoneWeight pingpong3;
    pingpong3 = 3.0 * pingpong;
    std::cout << "pingpong3 weighed(integer): ";
    std::cout << pingpong3;
    std::cout << "pingpong3 weighed(double): ";
    pingpong3.float_pounds_mode();
    std::cout << pingpong3;

    int nVal;
    double dVal;
    StoneWeight pingpong4(2, 1.2);
    StoneWeight addResult;
    addResult = pingpong + pingpong4;
    nVal = addResult;
    dVal = addResult;
    std::cout << addResult;
    addResult.float_pounds_mode();
    std::cout << addResult;
    std::cout << "(Integer)pingpong + pingpong4 = " << nVal << std::endl;
    std::cout << "(Double)pingpong + pingpong4 = " << dVal << std::endl;

    StoneWeight pingpong5(2, 10);
    StoneWeight substractResult;
    substractResult = pingpong - pingpong5;
    nVal = substractResult;
    dVal = substractResult;
    std::cout << substractResult;
    substractResult.float_pounds_mode();
    std::cout << substractResult;
    std::cout << "(Integer)pingpong - pingpong5 = " << nVal << std::endl;
    std::cout << "(Double)pingpong - pingpong5 = " << dVal << std::endl;

    return 0;
}



