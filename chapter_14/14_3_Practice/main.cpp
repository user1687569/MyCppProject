//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "queuetp.h"
#include "worker.h"


int main()
{
    std::cout << "Enter maximum size of queue: ";
    int qs;
    std::cin >> qs;

    Queue<Worker *> queueList(qs);
    char ch;

    Worker * pWorker;

    std::cout << "Please enter A to add a worker, " << std::endl
              << "P to dequeue a worker, or Q to quit." << std::endl;
    while (std::cin >> ch && std::toupper(ch) != 'Q')
    {
        while (std::cin.get() != '\n')
            continue;
        if(!std::isalpha(ch))
        {
            std::cout << '\a';
            continue;
        }

        switch (ch)
        {
        case 'A':
        case 'a':
            if(queueList.isfull())
                std::cout << "Queue already full" << std::endl;
            else
            {
                char choice;
                std::cout << "Enter the employee category: " << std::endl
                        << "w: waiter     s: singer     "
                        << "t: singing waiter     q: quit" << std::endl;
                std::cin >> choice;
                while (strchr("wstq", choice) == NULL)
                {
                    std::cout << "Please enter a w, s, t, or q: ";
                    std::cin >> choice;
                }

                if(choice == 'q')
                    break;
                
                switch (choice)
                {
                case 'w':
                    pWorker = new Waiter;
                    break;
                case 's':
                    pWorker = new Singer;
                    break;
                case 't':
                    pWorker = new SingingWaiter;
                    break;
                default:
                    break;
                }
                std::cin.get();
                pWorker->Set();

                queueList.enqueue(pWorker);
            }
            break;
        case 'P':
        case 'p':
            if(queueList.isempty())
                std::cout << "stack already empty" << std::endl;
            else
            {
                queueList.dequeue(pWorker);
                std::cout << "Dequeue worker is: " << std::endl;
                pWorker->Show();
                delete pWorker;
                break;
            }
        default:
            break;
        }
        std::cout << "Please enter A to add a worker, " << std::endl
              << "P to dequeue a worker, or Q to quit." << std::endl;
    }

    std::cout << "Bye" << std::endl;
    return 0;
}




