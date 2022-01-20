//1(a) 
char actors[30];

//1(b)
short betsie[100];

//1(c)
float chuck[13];

//1(d)
long double dipsea[64];

//2
array<char, 30> actors;
array<short, 100> betsie;
array<float, 13> chuck;
array<long double, 64> dipsea;

//3
int arrayInt[5] = {1, 3, 5, 7, 9};
array<int, 5> arrayInt = {1, 3, 5, 7, 9};

//4
int even = arrayInt[0] + arrayInt[-1];
int even = arrayInt[0] + arrayInt[4];

//5
std::cout << "second item in ideas is: " << ideas[1] << std::endl;

//6
char str[20] = "cheeseburger";
char str[] = "cheeseburger";

//7
str::string str = "cheeseburger";

//8
struct fish
{
    char breed[20]; // char kind[20];
    int weight_ounce;
    double length_inch;
};

//9
fish fishOne = {"shark", 2, 5.3};

//10
enum Response
{
    YES = 1,
    NO = 0,
    MAYBE =2
};

or
enum Response {No, Yes, Maybe};

//11
double ted = 5.0;
double* pd = &ted;

//12
float treacle[10];
float* pf = treacle;
std::cout << "First item is: " << *pf << std::endl;
std::cout << "Last item is: " << *(pf + 9) << std::endl;

//13
int count;
std::cin >> count;
int* integerList = new int[5];
delete [] integerList;

vector<int> integerList(count);

//14
Valid
One return example: 0x405065

//15
fish* fishOne = new fish;
std::cin.get(fishOne->breed, 20);
std::cin >> fishOne->weight_ounce;
std::cin >> fishOne->length_inch;

//16
Cannot determine if the input string is out of bounds
使用cin >> address 将使得程序跳过空白，直到找到非空白符为止。
然后它将读取字符，直到再次遇到空白为止。因此，它将跳过数字输入后
的换行符，从而避免这种问题。另一方面，它只读取一个单词，而不是整行。

//17
#include <iostream>
#include <string>
#include <array>
#include <vector>
const int count = 10;
st::vector<std::string> strList(count);
std::array<std::string, 10> strList;









