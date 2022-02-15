//Copyright (c) 2022 user1687569

CV -> const and volatile

非成员函数不是由对象调用的，它使用的所有值(包括对象)都是显式参数
有一类特殊的非成员函数可以访问类的私有成员，它们被称为友元函数

类的友元函数是非成员函数，其访问权限与成员函数相同


//1 
StoneWeight operator*(double n) const;
friend StoneWeight operator*(double n, const StoneWeight & st)
{ return st * n; }

StoneWeight StoneWeight::operator*(double n) const
{
    StoneWeight result;
    result = pounds * n;
    return result;
}


// 2 友元函数与成员函数之间的区别是什么
1. 成员函数是类定义的一部分，通过特定的对象来调用
2. 成员函数可以隐式访问调用对象的成员，而无需使用成员运算符
3. 友元函数不是类的组成部分，因此被称为直接函数调用
4. 友元函数不能隐式访问类成员，而必须将成员运算符用于作为参数传递的对象


// 3 非成员函数必须是友元才能访问类成员吗
//######
要访问私有成员，它必须是友元，但要访问公有成员，可以不是友元


//4 
friend StoneWeight operator*(double n, const StoneWeight & st)
{ return st * n; }
//######
// prototype
friend StoneWeight operator*(double mult, const StoneWeight & st);
// definition
StoneWeight operator*(double mult, const StoneWeight & st)
{
    return StoneWeight(mult * s.pounds);
}


//5 哪些运算符不能重载
sizeof运算符        sizeof
成员运算符          .
成员指针运算符       .*
作用域解析运算符     ::
条件运算符          ?::
RTTI运算符          typeid
强制类型转换运算符    const_cast
强制类型转换运算符    dynamic_cast
强制类型转换运算符    reinterpret_cast
强制类型转换运算符    static_cast


// 6 在重载运算符 = () [] 和 -> 时，有什么限制？
1. 重载后的运算符必须至少有一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符
2. 使用运算符时不能违法运算符原来的句法规则
3. 不能修改运算符的优先级
4. 不能创建新运算符
// ######
这些运算符必须使用成员函数来定义


//7 
// prototype
operator double() const;
// definition
Vector::operator double() const
{
    return mag;
}

//######
// prototype and inline definition
operator double() { return mag; }


