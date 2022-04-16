//Copyright (c) 2022 user1687569

//1 
a. 语法是正确的，当该构造函数没有将str指针初始化。该构造函数应将指针设置为NULL或使用new[]来初始化它。
b. 该构造函数没有创建新的字符串，而只是复制了原有字符串的地址。它应当使用new[] 和 strcpy().
c. 它复制了字符串，但没有给它分配存储空间，应使用new char[len + 1]来分配适当数量的内存


//2 如果您定义了一个类，其指针成员是使用new初始化的，
//  请指出可能出现的3个问题以及如何纠正这些问题
1. 当这种类型的对象过期时，对象的成员指针指向的数据仍将保留在内存中，
   这将占用空间，同时不可访问，因为指针已经丢失。可以让类析构函数删除
   构造函数中new分配的内存，来解决这种问题。
2. 析构函数释放这种内存后，如果程序将这样的对象初始化为另一个对象，则
   析构函数将试图释放这些内存两次。这是因为将一个对象初始化为另一个对象
   的默认初始化，将复制指针值，但不复制指向的数据，这将使两个指针指向相同的数据。
   解决办法是，定义一个复制构造函数，使初始化复制指向的数据。
3. 将一个对象赋给另一个对象也将导致两个指针指向相同的数据。
   解决办法是重载复制运算符，使之复制数据，而不是指针。


//3 如果没有显式提供类方法，编译器将自动生成哪些类方法？请描述这些隐式生成的函数的行为
如果没有定义构造函数，将提供默认构造函数
如果没有定义复制构造函数，将提供复制构造函数
如果没有定义赋值运算符，将提供赋值运算符
如果没有定义析构函数，将提供析构函数
如果没有定义地址运算符，将提供地址运算符


//4
// One
#include <iostream>
#include <cstring>
class nifty
{
private:
   char * personality;
   int talents;
public:
   nifty();
   nifty(const char * s);
   nifty(const nifty & n);
   ~nifty() { delete [] personality; }
   nifty & operator=(const nifty & n) const;
   friend ostream & operator<<(ostream & os, nifty & n, const nifty & n);
};
nifty::nifty()
{
   personality = NULL;
   talents = 0;
}
nifty::nifty(const char * s)
{
   personality = new char[strlen(s) + 1];
   strcpy(personality, s);
   talents = 0;
}
ostream & nifty:operator<<(ostream & os, const nifty & n)
{
   os << n.personality << '\n';
   os << n.talent << '\n';
   return os;
}

// Two
#include <iostream>
#include <cstring>
class nifty
{
private:
   char personality[40];
   int talents;

public:
   nifty();
   nifty(const char * s);
   friend ostream & operator<<(ostream & os, const nifty & n);
};
nifty::nifty()
{
   personality[0] = '\0';
   talents = 0;
}
nifty::nifty(const char *s)
{
   strcpy(personality, s);
   talents = 0;
}
ostream & operator<<(ostream & os, const nifty & n)
{
   os << n.personality << '\n';
   os << n.talent << '\n';
   return os;
}


//5
class Golfer
{
private:
   char * fullname;
   int games;
   int * scores;
public:
   Golfer();
   Golfer(const char * name, int g = 0);
   Golfer(const Golfer & g);
   ~Golfer();
}

a.
Golfer nancy;                    -> Golfer();
Golfer lulu("Little Lulu");      -> Golfer(const char * name, int g = 0);
Golfer roy("Roy Hobbs", 12);     -> Golfer(const char * name, int g = 0);
Golfer * par = new Golfer;       -> Golfer();
Golfer next = lulu;              -> Golfer(const Golfer & g);
Golfer hazzard = "Weed Thwacker";   -> Golfer(const char * name, int g = 0);
*par = nancy;                    -> 默认的赋值运算符
nancy = "Nancy Putter";          -> Golfer(const char * name, int g = 0); + 默认的赋值运算符


b.
Golfer & operator=(const char * name, int g = 0);
Golfer & operator=(const Golfer & g);
//######
类应该定义一个赋值数据（而不是地址）的赋值运算符

