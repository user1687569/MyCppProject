//Copyright (c) 2022 user1687569

//类和结构
C++对结构进行了扩展，使之具有与类相同的特性。
他们之间唯一的区别是，结构的默认访问类型是public,
而类为private.


//1 什么是类
类是一种将抽象转换为用户定义类型的C++工具，
它将数据表示和操纵数据的方法组合成一个整洁的包。
//######
类是用户定义的类型的定义。类声明制定了数据将如何存储，
同时指定了用来访问和操纵这些数据的方法（类成员函数）。


//2 类如何实现抽象、封装和数据隐藏
抽象：用户定义类型来实现抽象接口的类设计
封装：
1. 将实现的细节隐藏在私有部分中
2. 将类函数定义和类声明放在不同的文件中
数据隐藏：将数据放在类的私有部分中(防止程序直接访问数据)
//######
可以通过类方法的公有接口对类对象执行操作，这是抽象。
类的数据成员可以是私有的(默认值)，这意味着只能通过成员函数来访问这些数据，这是数据隐藏
实现的具体细节(如数据表示和方法的代码)都是隐藏的，这是封装。


//3 对象和类之间的关系是什么
对象是类声明的变量
//######
类和对象之间的关系同标准类型与其变量之间的关系相同
类定义了一种类型，包括如何使用它。
对象是一个变量或其他数据对象，并根据类定义被创建和使用。


//4 除了函数之外，类函数成员与类数据成员之间的区别是什么
类函数成员可以调用类数据成员
//######
如果创建给定类的多个对象，则每个对象都有其自己的数据内存空间，
但所有的对象都使用同一组成员函数。


//5
class BankAccount
{
private:
    char name[40];
    char account[25];
    double balance;

public:
    BankAccount(const char * client, const char * num, double bal = 0.0);
    void show(void) const;
    void deposit(double cash);
    void withdraw(double cash);
}


//6 类构造函数在何时被调用？类析构函数呢？
类构造函数在创建对象时被调用
当类过期时，类析构函数被调用
什么时候应调用析构函数呢？这由编译器决定，通常不应在代码中
显式地调用析构函数。
如果创建的是静态存储类对象，则其析构函数将在程序结束时自动被调用。
如果创建的是自动存储类对象，则其析构函数将在程序执行完代码块时自动被调用。
如果对象是通过new创建的，则它将驻留在栈内存或自由存储区中，当使用delete来释放内存时，其析构函数将自动被调用
当对象是临时创建时，程序将在结束对该对象的使用时自动调用其析构函数
//######
在创建类对象或显式调用构造函数时，类的构造函数将被调用。
当对象过期时，类的析构函数将被调用。


//7
BankAccount::BankAccount()
{
    strcpy(m_name, "Lee");
    strcpy(m_account, "1234567890");
    m_deposit = 168.90;
}

BankAccount::BankAccount(const char * client, const char * num, double bal = 0.0);
{
    strcpy(name, client);
    strcpy(account, num);
    balance = bal;
}

BankAccount::BankAccount(const std::string & client,
                         const std::string & num, double bal)
{
    name = client;
    acctnum = num;
    balance = bal;
}


//8 什么是默认构造函数，拥有默认构造函数有何好处
默认构造函数是在未提供显式初始值时，用来创建对象的构造函数。
默认构造函数没有参数，因为声明中不包含值。
//######
默认构造函数是没有参数或所有参数都有默认值的构造函数。
好处：
1. 拥有默认构造函数后，可以声明对象，而不初始化它，即使已经定义了初始化构造函数
2. 使得能够声明数组


//9
class Stock
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock();
    Stock(const std::string & co, long n = 0; double pr = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    const Stock & topval(const Stock & s) const;

    const std::string & getCompany() const { return company; }
    int getShares() const { return shares; }
    double getShareVal() const { return share_val; }
    double getTotalVal() const { return total_val; }
}


//10
this指针指向调用对象，如果方法需要引用整个调用对象，
则可以使用表达式*this。
this -> this是对象的地址
*this -> *this是对象本身







