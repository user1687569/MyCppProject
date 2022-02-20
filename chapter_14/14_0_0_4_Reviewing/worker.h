//Copyright (c) 2022 user1687569
#ifndef _WORKER_H_
#define _WORKER_H_
#include <string>

// 在祖先相同时，使用MI-Multiple inheritance必须引入虚基类
// 并修改构造函数初始化列表的规则

class Worker
{
private:
    std::string fullname;
    long id;

protected:
    // 模块化方式
    virtual void Data() const;
    virtual void Get();

public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string & s, long n) : fullname(s), id(n) {}
    virtual ~Worker() = 0;  // pure virtual function
    
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

// 使用虚基类
class Waiter : virtual public Worker
{
private:
    int panache;

protected:
    // 模块化方式
    void Data() const;
    void Get();

public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string & s, long n, int p = 0) : Worker(s, n), panache(p) {}
    Waiter(const Worker &wk, int p = 0) : Worker(wk), panache(p) {}
    
    void Set();
    void Show() const;
};


// 虚基类
class Singer : virtual public Worker
{
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};

    // 模块化方式
    void Data() const;
    void Get();

private:
    static char *pv[Vtypes];
    int voice;

public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string & s, long n, int v = other) : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = other) : Worker(wk), voice(v) {}

    void Set();
    void Show() const;
};


// 由于 Singer和Waiter都使用了虚基类
// 所以 SingingWaiter 将只包含 Worker对象的一个副本
// 从本质上，继承的Singer和Waiter对象共享一个Worker对象
// 使虚行为成为多MI, Multiple inheritance 的准则
class SingingWaiter : public Singer, public Waiter
{
protected:
    void Data() const;
    void Get();

public:
    SingingWaiter() {}
    SingingWaiter(const std::string & s, long n, int p = 0, int v = other)
        : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
    SingingWaiter(const Worker & wk, int p = 0, int v = other)
        : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    SingingWaiter(const Waiter & wt, int v = other)
        : Worker(wt), Waiter(wt), Singer(wt, v) {}
    SingingWaiter(const Singer & wt, int p = 0)
        : Worker(wt), Waiter(wt, p), Singer(wt) {}
    
    // 多重继承可能导致函数调用的二义性， 可使用模块化方式来化解
    void Set();
    void Show() const;
};


#endif
