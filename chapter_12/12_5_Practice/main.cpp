//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{   
    std::srand(std::time(0));
    std::cout << "Case Study: Bank of Heather Automatice Teller" << std::endl;
    std::cout << "Enter maximum size of queue: ";
    int qs;
    std::cin >> qs;
    Queue line(qs);

    std::cout << "Enter the number of simulation hours: ";
    int hours;
    std::cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    std::cout << "Enter the average number of customers per hour: ";
    double perHour;
    std::cin >> perHour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perHour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for(int cycle = 0; cycle < cyclelimit; cycle++)
    {
        // 判断时候来了新的客户。
        // 如果来了，并且此时队列未满，则将它添加到队列中，否则拒绝客户入队
        if(newcustomer(min_per_cust))
        {
            if(line.isfull())
                turnaways++;    
            else
            {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }

        // 如果没有客户在进行交易，则选取队列的第一个客户
        // 确定该客户的已等候时间，并将wait_time计数器设置为新客户所需的处理时间
        if(wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }

        // 如果客户正在处理中，则将wait_time计数器减一
        if(wait_time > 0)
            wait_time--;
        
        sum_line += line.queuecount();
    }

    // 记录各种数据
    if(customers > 0)
    {
        std::cout << "customer accepted: " << customers << std::endl;
        std::cout << "  customer served: " << served << std::endl;
        std::cout << "        turnaways: " << turnaways << std::endl;
        std::cout << "average queue size: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << (double) sum_line / cyclelimit << std::endl;
        std::cout << " average wait time: " << (double) line_wait / served << " minutes" << std::endl;
    }
    else
        std::cout << "No customers!" << std::endl;
    
    std::cout << "Done!" << std::endl;
    return 0;
}


bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

