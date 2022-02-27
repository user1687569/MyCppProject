//Copyright (c) 2022 user1687569
#include <iostream>
#include <list>
#include <algorithm>


void Show(int);
const int LIM = 10;


int main()
{
    int ar[LIM] = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};
    std::list<int> la(ar, ar + LIM);
    std::list<int> lb(la);
    std::cout << "Original list contents:\n\t";
    for_each(la.begin(), la.end(), Show);       // 4 5 4 2 2 3 4 8 1 4
    std::cout << std::endl;

    la.remove(4);
    std::cout << "After using the remove() method:" << std::endl;
    std::cout << "la:\t";
    // remove()方法将链表的la从10个元素减少到6个元素
    for_each(la.begin(), la.end(), Show);       // 5 2 2 3 8 1
    std::cout << std::endl;

    std::list<int>::iterator last;
    // remove()函数不是方法，不能调整链表的长度
    // 它将没被删除的元素放在链表的开始位置，
    // 并返回一个指向新的超尾值的迭代器
    // 这样，便可以用该迭代器来修改容器的长度
    last = remove(lb.begin(), lb.end(), 4);
    std::cout << "After using the remove() function:" << std::endl;
    std::cout << "lb:\t";
    for_each(lb.begin(), lb.end(), Show);       // 5 2 2 3 8 1 4 8 1 4
    std::cout << std::endl;

    // 对链表lb应用remove()函数后，它仍然包含10个元素
    // 最后4个元素可任意处理，
    // 因为其中每个元素要么为4，要么与已经转移到链表开头的值相同
    lb.erase(last, lb.end());
    std::cout << "After using the erase() method:" << std::endl;
    std::cout << "lb:\t";
    for_each(lb.begin(), lb.end(), Show);       // 5 2 2 3 8 1
    std::cout << std::endl;

    return 0;
}


void Show(int v)
{
    std::cout << v << ' ';
}

