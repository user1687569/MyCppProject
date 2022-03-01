//Copyright (c) 2022 user1687569
#include <iostream>


class Useless
{
private:
    int n;
    char * pc;
    static int ct;
    void ShowObject() const;

public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless & f); // regular copy constructor
    Useless(Useless && f);      // move constructor
    ~Useless();
    char * getPc() const;
    Useless operator+(const Useless & f) const;
    Useless & operator=(const Useless & f); // copy assignment
    Useless & operator=(Useless && f);      // move assignment
    void ShowData() const;
};

int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    std::cout << "default constructor called; number of objects: " << ct << std::endl;
    ShowObject();
}


Useless::Useless(int k) : n(k)
{
    ++ct;
    std::cout << "int constructor called; number of objects: " << ct << std::endl;
    pc = new char[n];
    ShowObject();
}


Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    std::cout << "int, char constructor called; number of objects: " << ct
              << std::endl;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = ch;
    ShowObject();
}


// 进行深复制
Useless::Useless(const Useless & f) : n(f.n)
{
    ++ct;
    std::cout << "copy const called; number of objects: " << ct << std::endl;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    ShowObject();
}


Useless::Useless(Useless && f) : n(f.n)
{
    ++ct;
    pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
}


Useless::~Useless()
{
    std::cout << "destructor called; objected left: " << --ct << std::endl;
    std::cout << "deleted object: " << std::endl;
    ShowObject();
    delete [] pc;
}


char * Useless::getPc() const
{
    return pc;
}


Useless Useless::operator+(const Useless & f) const
{
    std::cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for(int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for(int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
    std::cout << "temp object:\n";
    std::cout << "Leaving operator+()\n";

    return temp;
}


Useless & Useless::operator=(const Useless & f)
{
    std::cout << "copy assignment operator called:\n";
    if(this == &f)
        return *this;
    delete [] pc;

    n = f.n;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = f.pc[i];

    return *this;
}


Useless & Useless::operator=(Useless && f)
{
    std::cout << "move assignment operator called:\n";
    if(this == &f)
        return *this;
    delete [] pc;

    n = f.n;
    pc = f.pc;
    f.pc = nullptr;

    return *this;
}


void Useless::ShowObject() const
{
    std::cout << "Number of elements: " << n;
    std::cout << " Data address: " << (void *) pc << std::endl << std::endl;
}


void Useless::ShowData() const
{
    if(n == 0)
        std::cout << "(object empty)";
    else
        for(int i = 0; i < n; i++)
            std::cout << pc[i];
    std::cout << std::endl << std::endl;
}


int main()
{
    {
        Useless one(10, 'x');
        // one是左值， one + one 是右值
        Useless two = one + one;        // calls move constructor
        std::cout << "object one: ";
        one.ShowData();

        std::cout << "Object two: ";
        two.ShowData();

        Useless three, four;
        std::cout << "three = one\n";
        three = one;    // automatic copy assignment
        std::cout << "now object three = ";
        three.ShowData();

        std::cout << "and object one = ";
        one.ShowData();

        std::cout << "four = one + two\n";
        four = one + two;
        std::cout << "now object four = ";
        four.ShowData();

        std::cout << "four = move(one)\n";
        four = std::move(one);      // force move assignment
        std::cout << "now object four = ";
        four.ShowData();
        std::cout << " Four Data address: " << (void *) four.getPc() << std::endl << std::endl;

        // static_cast
        std::cout << "\n\n" << "Use static_cast: " << std::endl;
        Useless five(10, '#');
        Useless six(20, '*');
        std::cout << "Object six: ";
        six.ShowData();
        std::cout << " Object six Data address: " << (void *) six.getPc() << std::endl << std::endl;

        std::cout << "Object five: ";
        five.ShowData();
        std::cout << " Object five Data address: " << (void *) five.getPc() << std::endl << std::endl;

        five = static_cast<Useless &&>(six);
        std::cout << std::endl;
        std::cout << "After static_cast, Object five: ";
        five.ShowData();
        std::cout << " Object five Data address: " << (void *) five.getPc() << std::endl << std::endl;
    }

    return 0;
}


