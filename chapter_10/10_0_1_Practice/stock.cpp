//Copyright (c) 2022 user1687569
#include <iostream>
#include "stock.h"

Stock::Stock()
{
    std::cout << "Default constructor called" << std::endl;
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}


Stock::Stock(const std::string & co, long n, double pr)
{
    std::cout << "Constructor using" << co << " called" << std::endl;
    company = co;

    if(n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0." << std::endl; 
        shares = 0;
    }
    else
        shares = n;
    
    share_val = pr;
    set_tot();

}


Stock::~Stock()
{
    std::cout << "Bye, " << company << "!" << std::endl;
}


void Stock::buy(long num, double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. " 
                  << "Transaction is aborted." << std::endl;
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}


void Stock::sell(long num, double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares sold can't be negative. "
                  << "Transaction is aborted." << std::endl;
    }
    else if(num > shares)
    {
        std::cout << "You can't sell more than you have!" 
                  << "Transaction is aborted." << std::endl;
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}


void Stock::update(double price)
{
    share_val = price;
    set_tot();
}


void Stock::show() const
{
    // set format to #.###
    std::ios_base::fmtflags original = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
                                                    //fixed-> Write floating point values in fixed-point notation
    // std::ios_base::fmtflags original = std::cout.setf(std::ios_base::scientific, std::ios_base::floatfield);
    // std::ios_base::fmtflags original = std::cout.setf(std::ios_base::hex, std::ios_base::basefield);

    std::streamsize precision = std::cout.precision(3);

    std::cout << "Company: " << company << std::endl
              << "Shares: " << shares << std::endl
              << "Share Price: $" << share_val << std::endl;

    // set format to #.##
    std::cout.precision(2);          
    std::cout << "Total Worth: $" << total_val << std::endl << std::endl;

    std::cout.setf(original, std::ios_base::floatfield);
    std::cout.precision(precision);
}


const Stock & Stock::topval(const Stock & s) const
{
    if(s.total_val > total_val)
        return s;
    else
        return *this;
}





