//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>

std::string version1(const std::string & s1, const std::string & s2);
const std::string & version2(std::string & s1, const std::string & s2);
const std::string & version3(std::string & s1, const std::string & s2);


int main()
{
    std::string input;
    std::string copy;
    std::string result;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    copy = input;
    std::cout << "Your string as entered: " << input << std::endl;

    result = version1(input, "***");
    std::cout << "Your string enhanced: " << result << std::endl;
    std::cout << "Your original string: " << input << std::endl;

    result = version2(input, "###");
    std::cout << "Your string enhanced: " << result << std::endl;
    std::cout << "Your original string: " << input << std::endl;

    std::cout << "Resetting original string: " << std::endl;
    input = copy;
    result = version3(input, "@@@");
    std::cout << "Your string enhanced: " << result << std::endl;
    std::cout << "Your original string: " << input << std::endl;

    return 0;
}


//temp是一个新的string对象，只在函数version1()中有效，
//该函数执行完毕后，它将不在存在。因此，返回指向temp的引用不可行，
//因此该函数的返回类型为string,这意味着temp的内容被复制到一个名为
//result的string中
std::string version1(const std::string & s1, const std::string & s2)
{
    std::string temp;

    temp = s2 + s1 + s2;
    return temp;
}


// 函数version2()不创建临时string对象，而是直接修改原来的string对象
const std::string & version2(std::string & s1, const std::string & s2)
{
    s1 = s2 + s1 + s2;      // Safe to return reference passed to function
    return s1;
}


// 存在一个致命的缺陷
// 程序试图引用已经释放的内存
const std::string & version3(std::string & s1, const std::string & s2)
{
    std::string temp;

    temp = s2 + s1 + s2;    // Unsafe to return reference to local variable
    return temp;
}

