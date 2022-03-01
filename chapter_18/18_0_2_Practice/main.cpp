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
    ~Useless();
    Useless operator+(const Useless & f) const;
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


Useless::~Useless()
{
    std::cout << "destructor called; objected left: " << --ct << std::endl;
    std::cout << "deleted object: " << std::endl;
    ShowObject();
    delete [] pc;
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
        Useless two = one;
        Useless three(20, 'o');
        Useless four(one + three);
        std::cout << "object one: ";
        one.ShowData();

        std::cout << "Object two: ";
        two.ShowData();

        std::cout << "Object three: ";
        three.ShowData();
        
        std::cout << "object four: ";
        four.ShowData();
    }

    return 0;
}


