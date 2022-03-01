//Copyright (c) 2022 user1687569
#include <iostream>
#include <vector>
#include <iterator>

class Z200
{
private:
    int j;
    char ch;
    double z;

public:
    Z200(int jv, char chv, double zv) :j(jv), ch(chv), z(zv) {}
};


int main()
{
    double x = 8.8;
    std::string s = "What a bracing effect!";
    int k(99);
    Z200 zip(200, 'Z', 0.675);
    std::vector<int> ai{3, 9, 4, 7, 1};
    // int ar[5] = {3, 9, 4, 7, 1};
    // int i = 0;
    // for(auto pt = ai.begin(); pt != ai.end(); ++pt, ++i)
    // {
    //     *pt = ar[i];
    // }

    std::ostream_iterator<int, char> out_iter(std::cout, " ");
    copy(ai.begin(), ai.end(), out_iter);
    std::cout << std::endl;

    return 0;
}


