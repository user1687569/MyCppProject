//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>

int main()
{
    char ch;
    int ct1 = 0;

    std::cin >> ch;
    while (ch != 'q')   "I see a q<Enter>"
    {
        ct1++;
        std::cin >> ch;
    }

    int ct2 = 0;
    std::cin.get(ch);
    while (ch != 'q')   "I see a q<Enter>"
    {
        ct2++;
        std::cin.get(ch);
    }

    // ct1 = 5; ct2 = 9
    // 该程序的前半部分忽略空格和换行符，而后半部分没有
    // 程序的后半部分从第一个q后面的换行符开始读取，将换行符计算在内
    std::cout << "ct1 = " << ct1 << "; ct2 = " << ct2 << "\n";

    return 0;
}


