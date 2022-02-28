//Copyright (c) 2022 user1687569
#ifndef _EMP_H_
#define _EMP_H_
#include <iostream>
#include <string>
#include <fstream>

// 在祖先相同时，使用MI-Multiple inheritance必须引入虚基类
// 并修改构造函数初始化列表的规则

enum classkind
{
    Employee = 0,
    Manager,
    Fink,
    Highfink
};

class abstr_emp
{
private:
    std::string fname;
    std::string lname;
    std::string job;

public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string & ln, const std::string & j);
    
    virtual ~abstr_emp() = 0;
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual std::ofstream & writeall(std::ofstream & of) const;
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
};


class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string & fn, const std::string & ln, const std::string & j)
            : abstr_emp(fn, ln, j) {}
    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream & writeall(std::ofstream & of) const;
};


class manager : virtual public abstr_emp
{
private:
    int inchargeof;

protected:
    int InChargeOf() const { return inchargeof; }
    int & InChargeOf() { return inchargeof; }

public:
    manager() : abstr_emp(), inchargeof(0) {}
    manager(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0)
            : abstr_emp(fn, ln, j), inchargeof(ico) {}
    manager(const abstr_emp & e, int ico)
            : abstr_emp(e), inchargeof(ico) {}
    manager(const manager & m);

    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream & writeall(std::ofstream & of) const;
};


class fink : virtual public abstr_emp
{
private:
    std::string reportsto;

protected:
    std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo() { return reportsto; }  

public:
    fink() : abstr_emp(), reportsto("") {}
    fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
            : abstr_emp(fn, ln, j), reportsto(rpo) {}
    fink(const abstr_emp & e, const std::string & rpo)
            : abstr_emp(e), reportsto(rpo) {}
    fink(const fink & e);

    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream & writeall(std::ofstream & of) const;
};


class highfink : public manager, public fink
{
public:
    highfink() {}
    highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico) 
            : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

    highfink(const abstr_emp & e, const std::string & rpo, int ico)
            : abstr_emp(e), manager(e, ico), fink(e, rpo) {}

    highfink(const fink & f, int ico)
            : abstr_emp(f), manager(f, ico), fink(f) {}

    highfink(const manager & m, const std::string & rpo)
            : abstr_emp(m), manager(m), fink(m, rpo) {}

    highfink(const highfink & h);

    // 多重继承可能导致函数调用的二义性， 可使用模块化方式来化解
    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream & writeall(std::ofstream & of) const;
};


#endif
