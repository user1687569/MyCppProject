//Copyright (c) 2022 user1687569

The cin.clear() clears the error flag on cin 
(so that future I/O operations will work correctly), 
and then cin.ignore(10000, '\n') skips to the next newline 
(to ignore anything else on the same line as the non-number 
so that it does not cause another parse failure). 
It will only skip up to 10000 characters, so the code 
is assuming the user will not put in a very long, invalid line.
#include <map>

//1
使用函数的3个步骤：
1.提供函数定义
2.提供函数原型
3.调用函数

//2
2.a void igor();
2.b float tofu(int);
2.c double mpg(double, double);
2.d long summation(long [], int);
2.e double doctor(const char *);
2.f void ofcourse(boss);
2.g char * plot(std::map<typename, typename> *);

//3
void fillIntArray(int array[], int length, int n)
{
    for(int i = 0; i < length; i++)
    {
        array[i] = n;
    }

    return;
}

//4
void fillIntArray(int *begin, int *end, int n)
{
    int * pt;
    for(pt = begin; pt != end; pt++)
    {
        *pt = n;
    }

    return;
}

#include <limits>

//5
double pickMaxValue(double list[], int length)
{
    double max = numeric_limits<double>::min();
    for(int i = 0; i < length; i++)
    {
        max = max > list[i] ? max : list[i];
    }

    return max;
}
//======Example Code======
double biggest(const double foot[], int size)
{
    double max;
    if(size < 1)
    {
        std::cout << "Invalid array size of " << size << std::endl;
        std::cout << "Returning a value of 0\n";
        return 0;
    }
    else
    {
        max = foot[0];
        for(int i = 1; i < size; i++)
            if(foot[i] > max)
                max = foot[i];
        
        return max;
    }
}


//6
类型为基本类型的函数参数是按值传递，在调用函数中修改其值，
并不会改变原先函数中该类型的值。
//=============
将const限定符用于指针，以防止指向的原始数据被修改。程序传递
基本类型（如int或double）时，它将按值传递，以便函数使用副本。
这样，原始数据将得到保护。


//7
C++程序可使用的3中C-风格字符串格式：
1. char数组
2. 用引号括起的字符串常量（也称字符串字面值）
3. 被设置为字符串的地址的char指针

//8
int replace(char * str, char c1, char c2)
{
    char *pt;
    int count = 0;
    pt = str;
    while(*pt != '\0')
    {
        if(*pt == c1)
        {
            *pt = c2;
            count += 1;
        }
        pt++;
    }

    return count;
}
//=================
int replace(char * str, char c1, char c2)
{
    int count = 0;
    while(*str)
    {
        if(*str == c1)
        {
            *str = c2;
            count++;
        }
        str++;
    }

    return count;
}


//9
*"pizza": 获取字符串常量"pizza"所在地址中的字符串。 XXX[Wrong] 
"taco"[2]: 字符串常量"taco"中的第三个字符
//=============
犹豫C++将|"pizza"解释为其第一个元素的地址，因此使用*运算符将得到
第一个元素的值，即字符p。由于C++将"taco"解释为第一个元素的地址，
因此它将"taco"[2]解释为第三个元素的值，即字符c。换句话来说，
字符串常量的行为与数组名相同。

//10
如果glitz是一个结构变量，
按值传递：void fucntion(glitz struct_glitz);
按地址传递：void function(glitz * pGlitz);
这两种方法的利弊？
按值传递，传递的是整个结构，当结构较小时，按值传递结构最合理；
当结构较大时，则复制结构将增加内存要求，降低系统运行速度。
按地址传递，节省时间和空间，充分利用指针的效率。
//=================
要按值传递它，只要传递结构名glitz即可。要传递它的地址，
请使用地址运算符&glitz。按值传递将自动保护原始数据，
但这是以时间和内存为代价的。按地址传递可节省时间和内存，
但不能保护原始数据，除非对函数参数使用了const限定符。
另外，按值传递意味着可以使用常规的结构成员表示法，
但传递指针则必须使用间接成员运算符。

//11
int judge(int (*p)(const char *));

//12
struct applicant
{
    char name[30];
    int credit_ratings[3];
};

a. void showInfo(applicant oneApplicant)
{
    std::cout << "Name: " << oneApplicant.name << std::endl;
    std::cout << "Credit Rating[1]: " << oneApplicant.credit_ratings[0] << std::endl;
    std::cout << "Credit Rating[2]: " << oneApplicant.credit_ratings[1] << std::endl;
    std::cout << "Credit Rating[3]: " << oneApplicant.credit_ratings[2] << std::endl; 
}

b. void showStructPointerInfo(applicant * pApplicant)
{
    std::cout << "Name: " << pApplicant->name << std::endl;
    std::cout << "Credit rating[1]: " << pApplicant->credit_ratings[0] << std::endl;
    std::cout << "Credit rating[2]: " << pApplicant->credit_ratings[1] << std::endl;
    std::cout << "Credit rating[3]: " << pApplicant->credit_ratings[2] << std::endl;
}


//13
void (*p1)(applicant * a) = f1;
const char * (*p2)(const applicant * a1, const applicant * a2) = f2;

void (*ap[5])(applicant * a);
const char * (*(*pa)[10])(const applicant * a1, const applicant * a2);
//===============
//===============
typedef void (*p_f1)(applicant *);
p_f1 p1 = f1;
typedef const char * (*p_f2)(const applicant *, const applicant *);
p_f2 p2 = f2;
p_f1 ap[5];
p_f2 (*pa)[10];










 


