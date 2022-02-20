//Copyright (c) 2022 user1687569
#ifndef _QUEUETP_H_
#define _QUEUETP_H_
#include <iostream>
#include "worker.h"


template <class Type>
class Queue
{
private:
    enum {Q_SIZE = 10};
    struct Node { Type item;  struct Node * next; };

    Node * front;
    Node * rear;
    int items;
    const int qsize;
    Queue(const Queue & q) : qsize(0) {}
    Queue & operator=(const Queue & q) { return *this; }

public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Type &item);
    bool dequeue(Type & item);
};


template <class Type>
Queue<Type>::Queue(int qs) : qsize(qs)
{
    front = rear = NULL;
    items = 0;
}


template <class Type>
Queue<Type>::~Queue()
{
    Node *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}


template <class Type>
bool Queue<Type>::isempty() const
{
    return items == 0;
}


template <class Type>
bool Queue<Type>::isfull() const
{
    return items == qsize;
}


template <class Type>
int Queue<Type>::queuecount() const
{
    return items;
}


template <class Type>
bool Queue<Type>::enqueue(const Type & item)
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


template <class Type>
bool Queue<Type>::dequeue(Type & item)
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


#endif