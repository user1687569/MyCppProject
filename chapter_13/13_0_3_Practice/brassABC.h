//Copyright (c) 2022 user1687569
#ifndef _BRASSABC_H_
#define _BRASSABC_H_
#include <iostream>
#include <string>

class BrassABC
{
private:
    std::string fullName;
    long accountNum;
    double balance;

protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & FullName() const { return fullName; }
    long AcctNum() const { return accountNum; }
    Formatting SetFormat() const;
    void Restore(Formatting & f) const;

public:
    BrassABC(const std::string & s = "Nullbody",
             long an = -1,
             double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0;  // pure virtual function
    double Balance() const { return balance; }
    virtual void ViewAcct() const = 0;      // pure virtual function
    virtual ~BrassABC() {} 
};


class Brass : public BrassABC
{
public:
    Brass(const std::string & s = "Nullbody",
          long an = -1,
          double bal = 0.0,
          ) : BrassABC(s, an, bal) {}
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass();
};


class BrassPlus : public BrassABC
{
private:
    double maxLoan;
    double rate;
    double owesBank;

public:
    BrassPlus(const std::string & s = "Nullbody",
              long an = -1,
              double bal = 0.0,
              double ml = 500,
              double r = 0.10);
    BrassPlus(const Brass & ba,
              double ml = 500,
              double r = 0.1);
    
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};


#endif