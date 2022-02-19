//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include "brassABC.h"


BrassABC::BrassABC(const std::string & s, long an, double bal)
{
    fullName = s;
    accountNum = an;
    balance = bal;
}


void BrassABC::Deposit(double amt)
{
    if(amt < 0)
        std::cout << "Negative deposit not allowed; "
                  << "deposit is cancelled." << std::endl;
    else
        balance += amt;
}


void BrassABC::Withdraw(double amt)
{
    balance -= amt;
}


BrassABC::Formatting BrassABC::SetFormat() const
{
    Formatting f;
    f.flag = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    f.pr = std::cout.precision(2);
    return f;
}


void BrassABC::Restore(Formatting & f) const
{
    std::cout.setf(f.flag, std::ios_base::floatfield);
    std::cout.precision(f.pr);
}


void Brass::Withdraw(double amt)
{
    if(amt < 0)
        std::cout << "Withdrawal amount must be positive; "
                  << "withdrawal cancelled." << std::endl;
    else if (amt <= balance)
        BrassABC::Withdraw(amt);
    else
        std::cout << "Withdrawal amount of $" << amt
                  << " exceeds your balance." << std::endl
                  << "Withdrawal cancelled." << std::endl;
}


void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    std::cout << "Brass Client: " << FullName() << std::endl;
    std::cout << "Account Number: " << AcctNum() << std::endl;
    std::cout << "Balance: $" << Balance() << std::endl;
    Restore(f);
}


BrassPlus::BrassPlus(const std::string & s,
                     long an,
                     double bal,
                     double ml,
                     double r) : BrassABC(s, an, bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}


BrassPlus::BrassPlus(const Brass & ba,
                     double ml,
                     double r) : BrassABC(ba)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}


void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();

    std::cout << "BrassPlus Client: " << FullName() << std::endl;
    std::cout << "Account Number: " << AcctNum() << std::endl;
    std::cout << "Balance: $" << Balance() << std::endl;
    std::cout << "Maximum loan: $" << maxLoan << std::endl;
    std::cout << "Owed to bank: $" << owesBank << std::endl;
    
    // ###.### format
    std::cout.precision(3);
    std::cout << "Loan Rate: " << 100 * rate << "%" << std::endl;
    Restore(f);
}


void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();

    double bal = Balance();
    if(amt <= bal)
        BrassABC::Withdraw(amt);
    else if(amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal; // Here, amt is bigger than balance, advance means that what you want to loan from bank
        owesBank += advance * (1.0 + rate);
        std::cout << "Bank advance: $" << advance << std::endl;
        std::cout << "Finance charge: $" << advance * rate << std::endl;
        Deposit(advance);
        BrassABC::Withdraw(amt);
    }
    else
        std::cout << "Credit limit exceeded. Transaction cancelled." << std::endl;  

    Restore(f);
}





