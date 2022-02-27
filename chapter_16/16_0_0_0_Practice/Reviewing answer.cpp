//Copyright (c) 2022 user1687569

// 1
RQ & operator=(const RQ & rq);
不在需要显式定义


// 2 
在易于使用方面，指出sting对象至少两个优于 C-风格字符串的地方
第一，使用string对象不需要考虑内存泄漏
第二，string对象自动从在 operator=()运算符


// 3
编写一个函数，用string对象作为参数，将string对象转换为全部大写
void toLower(std::string & str)
{
    for(int i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
    }
}


// 4
auto_ptr<int> pia = (new int[20]);
[wrong]: use with new, not new[]
[Fix]: auot_ptr<int> pia = (new int);

auto_ptr<string> (new string);
[wrong]: no name for pointer
[Fix]: auto_ptr<string> ptr(new string);

int rigue = 7;
auto_ptr<int> pr(&rigue);
[wrong]: memory not allocated by new

auto_ptr dbl (new double);
[wrong]: omits <double>


// 5
如果可以生成一个存储高尔夫球棍(而不是数字)的栈，
为何它(从概念上说)是一个坏的高尔夫袋子？
答: 栈的LIFO特征意味着 可能必须在到达所需要的球棍(club)
之前删除很多球棍。


// 6 
为什么说对于逐洞记录高尔夫成绩来说，set容器是糟糕的选择？
答：set容器不会存储两个相同的值


// 7
既然指针是一个迭代器，为什么STL设计人员没有简单地使用指针来
地体迭代器呢？
答：使用迭代器使得能够使用接口类似于 指针的对象遍历不以数组方式
组织的数据，如双向链表中的数据


// 8 
为什么STL设计人员仅定义了迭代器基类，而使用继承来派生其他迭代器类型
的类，并根据这些迭代器类来表示算法？
答：STL方法使得可以将STL函数用于指向常规数组的常规指针
以及指向STL容器类的迭代器，因此提高了通用性。


// 9
给出vector对象比常规数组方便的3个例子？
1. 可以将一个 vector对象赋给另一个
2. vector管理自己的内存，因此可以将元素插入到矢量中，并让它自动调整长度
3. 使用at()方法，可以自动检查边界
4. vector可以使用迭代器来操作


// 10
答：random_shuffle()函数要求随机访问迭代器，
而list对象只有双向迭代器。
可以使用list模板类的sort()成员函数，
而不是通用函数来排序，但没有与random_shuffle()等效的成员函数。
然而，可以将链表复制到矢量中，然后打乱矢量，并将结果重新复制到链表中。


// 11
bool bo = TooBif<int>(10)(15);
功能：将15与10进行比较，如果第二个参数大于第一个参数，返回真值 true



