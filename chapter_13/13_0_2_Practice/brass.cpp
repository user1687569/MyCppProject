//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include "brass.h"

std::ios_base::fmtflags setFormat();
void restore(std::ios_base::fmtflags f, std::streamsize p); 


Brass::Brass(const std::string & s,
             long an,
             double bal)
{
    fullname = s;
    accountNum = an;
    balance = bal;
}


void Brass::Deposit(double amt)
{
    if(amt < 0)
        std::cout << "Negative deposit not allowed; "
                  << "deposit is cancelled." << std::endl;
    else
        balance += amt;
}


void Brass::Withdraw(double amt)
{
    // set up ###.## format
    std::ios_base::fmtflags initialState = setFormat();
    std::streamsize prec = std::cout.precision(2);

    if(amt < 0)
        std::cout << "Withdrawal amount must be positive; "
                  << "withdrawal cancelled." << std::endl;
    else if (amt <= balance)
        balance -= amt;
    else
        std::cout << "Withdrawal amount of $" << amt
                  << " exceeds your balance." << std::endl
                  << "Withdrawal cancelled." << std::endl;
    
    restore(initialState, prec);
}


double Brass::Balance() const
{
    return balance;
}


void Brass::ViewAcct() const
{
    std::ios_base::fmtflags initialState = setFormat();
    std::streamsize prec = std::cout.precision(2);
    std::cout << "Client: " << fullname << std::endl;
    std::cout << "Account Number: " << accountNum << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
    restore(initialState, prec);
}


BrassPlus::BrassPlus(const std::string & s,
                     long an,
                     double bal,
                     double ml,
                     double r) : Brass(s, an, bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}


BrassPlus::BrassPlus(const Brass & ba,
                     double ml,
                     double r) : Brass(ba)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}


void BrassPlus::ViewAcct() const
{
    std::ios_base::fmtflags initialState = setFormat();
    std::streamsize prec = std::cout.precision(2);

    // view base portion
    Brass::ViewAcct();
    std::cout << "Maximum loan: $" << maxLoan << std::endl;
    std::cout << "Owed to bank: $" << owesBank << std::endl;
    
    // ###.### format
    std::cout.precision(3);
    std::cout << "Loan Rate: " << 100 * rate << "%" << std::endl;
    restore(initialState, prec);
}


void BrassPlus::Withdraw(double amt)
{
    std::ios_base::fmtflags initialState = setFormat();
    std::streamsize prec = std::cout.precision(2);

    double bal = Balance();
    if(amt <= bal)
        Brass::Withdraw(amt);
    else if(amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal; // Here, amt is bigger than balance, advance means that what you want to loan from bank
        owesBank += advance * (1.0 + rate);
        std::cout << "Bank advance: $" << advance << std::endl;
        std::cout << "Finance charge: $" << advance * rate << std::endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        std::cout << "Credit limit exceeded. Transaction cancelled." << std::endl;  

    restore(initialState, prec);
}


std::ios_base::fmtflags setFormat()
{
    return std::cout.setf(std::ios_base::fixed,
                          std::ios_base::floatfield);
}


void restore(std::ios_base::fmtflags format, std::streamsize prec)
{
    std::cout.setf(format, std::ios_base::floatfield);
    std::cout.precision(prec);
}



