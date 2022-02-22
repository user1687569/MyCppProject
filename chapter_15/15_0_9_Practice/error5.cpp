//Copyright (c) 2022 user1687569
#include <iostream>
#include <new>
#include <cstdlib>  // for exit(), EXIT_FAILURS


// logic_error 描述了典型的逻辑错误
// invalid_argument 指出给函数传递了一个意料外的值
// length_error 指出没有足够的空间来执行所需的操作
// out_of_bounds 用于指示索引错误
// runtime_error 描述了可能在运行期间发生但难以预计和防范的错误
//      range_error 
//      overflow_error
//      underflow_error 
// bad_alloc异常和new


struct Big
{
    double stuff[20000];
};


int main()
{
    Big * pb;
    try{
        std::cout << "Trying to get a big block of memory: " << std::endl;
        pb = new (std::nothrow) Big[10000];
        std::cout << "Got past the new request: " << std::endl;
    }
    catch(std::bad_alloc & ba)
    {
        std::cout << "Caught the exception!" << std::endl;
        std::cout << ba.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Memory successfully allocated" << std::endl;
    pb[0].stuff[0] = 4;
    std::cout << pb[0].stuff[0] << std::endl;
    delete [] pb;

    return 0;
}

