//Copyright (c) 2022 user1687569
#ifndef _STOCK_H_
#define _STOCK_H_

#include <string>

class Stock
{
private:
    // std::string company;
    char * company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock();
    Stock(const char * co, long n = 0, double pr = 0.0);
    ~Stock();

    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    friend std::ostream & operator<<(std::ostream & os, const Stock & st);
    //括号后的const表明，该函数不会修改被隐式访问的对象
    const Stock & topval(const Stock & s) const;
};


#endif