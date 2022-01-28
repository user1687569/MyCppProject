//Copyright (c) 2022 user1687569
#include <iostream>
// const double * f1(const double ar[], int n);
// const double * f2(const double [], int);
// const double * f3(const double *, int); // const double * f3(const double ar*, int);

// const double * (*p1)(const double *, int) = f1;
// auto p2 = f2;

// std::cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << std::endl;
// std::cout << p2(av, 3) << ": " << *p2(av, 3) << std::endl;

// (*p1)(av, 3)和p2(av, 3) 都调用指向的函数，这里指f1()和f2(),
// 并将av和3作为参数。因此，显示的是这两个函数的返回值。
// 返回值的类型为const double * (即double值的地址)。
// 为查看存储在这些地址处的实际值，需要将运算符*应用于这些地址，
// 如表达式 *(*p1)(av, 3)和 *p2(av, 3)所示。

// 函数指针数组
// const double * (*pa[3])(const double *, int) = {f1, f2, f3};

// 自动类型推断只能用于单值初始化，而不能用于初始化列表。
// 但声明数组pa后，生命同样类型的数组就很简单了:
// auto pb = pa;

// const double * px = pa[0](av, 3);
// const double * py = (*pb[1])(av, 3);

// double x = *pa[0](av, 3);
// double y = *(*pb[1])(av, 3);

// 创建指向整个数组的指针。
// auto pc = &pa;

const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main()
{
    double av[3] = {1112.3, 1542.6, 2227.9};

    const double * (*p1)(const double *, int) = f1;
    auto p2 = f2;

    std::cout << "Using pointers to functions: " << std::endl;
    std::cout << "Address   Value" << std::endl;
    std::cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << std::endl;
    std::cout << p2(av, 3) << ": " << *p2(av, 3) << std::endl;

    const double * (*pa[3])(const double *, int) = {f1, f2, f3};
    auto pb = pa;

    std::cout << "Using an array of pointers to functions: " << std::endl;
    std::cout << "Address   Value" << std::endl;
    for(int i = 0; i < 3; i++)
        std::cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << std::endl;

    std::cout << "Using a pointer to a pointer to a function: " << std::endl;
    std::cout << "Address   Value" << std::endl;
    for(int i = 0; i < 3; i++)
        std::cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << std::endl;
    
    
    std::cout << "Using pointer to an array of pointers: " << std::endl;
    std::cout << "Address   Value" << std::endl;
    auto pc = &pa;
    std::cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << std::endl;

    const double * (*(*pd)[3])(const double *, int) = &pa;
    const double * pdb = (*pd)[1](av, 3);
    std::cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << std::endl;

    return 0;
}


const double * f1(const double * ar, int n)
{
    return ar;
}


const double *f2(const double ar[], int n)
{
    return ar + 1;
}


const double * f3(const double ar[], int n)
{
    return ar + 2;
}






