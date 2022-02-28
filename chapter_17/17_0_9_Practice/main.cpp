//Copyright (c) 2022 user1687569
#include <iostream>
#include <exception>

// 异常用于捕获不正常的意外情况，
// 但这个例子将输入错误作为一种退出循环的方式


// Enter numbers: 20 30 40 pi 6
// terminate called after throwing an instance of 'std::ios_base::failure'
//   what():  basic_ios::clear

// exceptions()方法返回一个字段，它包含3位，
// 分别对应于eofbit, faillbit 和 badbit.
// 修改流状态涉及clear() 或 setstate()， 这都将使用 clear().
// 修改流状态后，clear()方法将当前的流状态与exceptions()返回的值进行比较。
// 如果在返回值中某一位被设置，而当前状态中的对应位也被设置，
// 则clear()及那个引发 ios_base::failure异常。
// 如果exceptions()返回goodbit, 这不会引发任何异常

// 为什么需要重新设置流状态呢？
// 在输入不匹配或到达文件尾时，
// 需要使用不带参数的clear()重新打开


int main()
{
    // std::cin.exceptions(std::ios_base::failbit);
    std::cin.exceptions(std::ios_base::goodbit);
    std::cout << "Enter numbers: ";
    int sum = 0;
    int input;

    try{
        while (std::cin >> input)
        {
            sum += input;
        }
    }catch(std::ios_base::failure & bf)
    {
        std::cout << bf.what() << std::endl;
        std::cout << "O! the horror!\n";
    }

    std::cout << "Last value entered = " << input << std::endl;
    std::cout << "Sum = " << sum << std::endl;

    return 0;
}


