//Copyright (c) 2022 user1687569
#include <iostream>
#include <iterator>
#include <vector>
#include <list>         // std::list
#include <algorithm>    // std::copy


// 演示如何使用copy(), istream迭代器和反向迭代器


int main()
{
    int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
    std::vector<int> dice(10);

    copy(casts, casts + 10, dice.begin());
    std::cout << "Let the dice be cast!" << std::endl;

    // 输出迭代器
    std::ostream_iterator<int, char> out_iter(std::cout, " ");
    copy(dice.begin(), dice.end(), out_iter);
    std::cout << std::endl;

    // 隐式的反向迭代器
    std::cout << "Implicit use of reverse iterator." << std::endl;
    copy(dice.rbegin(), dice.rend(), out_iter);
    std::cout << std::endl;

    // 显式的反向迭代器
    std::cout << "Explicit use of reverse iterator." << std::endl;
    std::vector<int>::reverse_iterator ri;
    for(ri = dice.rbegin(); ri != dice.rend(); ++ri)
        std::cout << *ri << ' ';
    std::cout << std::endl;
    
    
    // 输入迭代器示例
    double value1, value2;
    std::cout << "std::istream_iterator example: " << std::endl;
    std::cout << "Please insert two values: "; 
    std::istream_iterator<double> eos;              // end-of-stream iterator
    std::istream_iterator<double> iit (std::cin);   // stdin iterator
    if(iit != eos)
        value1 = *iit;
    ++iit;
    if(iit != eos)
        value2 = *iit;
    std::cout << value1 << " * " << value2 << " = " << (value1 * value2) << std::endl;


    // insert_iterator
    std::list<int> foo, bar;
    for(int i = 1; i <= 5; i++)
    {
        foo.push_back(i);           // foo: 1 2 3 4 5
        bar.push_back(i * 10);      // bar 10 20 30 40 50
    }

    std::list<int>::iterator it = foo.begin();
    
    // advance(_InputIterator& __i, _Distance __n);
    // 这将 __i 增加 __n. 用于双向和随机访问迭代器，__n可能是负的，在这种情况下 __i递减。  
    advance(it, 3);

    std::insert_iterator<std::list<int>> insert_it(foo, it);    // 指示插入位置的构造函数
    std::copy(bar.begin(), bar.end(), insert_it);

    // foo:  1 2 3 10 20 30 40 50 4 5
    std::cout << "foo: ";
    for(std::list<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}


