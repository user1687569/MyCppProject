//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstdlib>
#include "queue.h"


// 对于const数据成员，必须在执行到构造函数体之前，即创建对象时进行初始化
// C++提供了一种特殊的语法来完成工作，它叫做成员初始化列表，
// 成员初始化列表由逗号分隔的初始化列表组成（前面带冒号）
// 这种方法并不限于初始化常量，可以将Queue构造函数写成如下所示:
// Queue::Queue(int qs) : qsize(qs), front(NULL), rear(NULL), items(0)
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL;
    items = 0;
}


Queue::~Queue()
{
    Node *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}


bool Queue::isempty() const
{
    return items == 0;
}


bool Queue::isfull() const
{
    return items == qsize;
}


int Queue::queuecount() const
{
    return items;
}


bool Queue::enqueue(const Item & item)
{
    if(isfull())
        return false;
    
    Node * add = new Node;
    add->item = item;
    add->next = NULL;
    items++;
    if(front == NULL)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}


bool Queue::dequeue(Item & item)
{
    if(front == NULL)
        return false;
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if(items == 0)
        rear = NULL;
    return true;
}


void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}



