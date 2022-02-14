//Copyright (c) 2022 user1687569
#ifndef _SALES_H_
#define _SALES_H_

namespace SALES
{
class Sales
{
private:
    static const int QUARTERS = 4;
    double m_sales[QUARTERS];
    double m_average;
    double m_max;
    double m_min;

public:
    Sales() {}
    Sales(const double ar[], int n);
    Sales & setSales();
    void showSales() const;

};
}


#endif