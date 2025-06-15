#include <iostream>
#include "myQueue.h"
using namespace std;

int main()
{
    myQueue<int>Q(20);   
    myQueue<int>q1(20);  
    myQueue<int>q2(20);
    myQueue<int>q3(20);
    myQueue<int>q4(20);

    Q.Enqueue(12);
    Q.Enqueue(9);
    Q.Enqueue(5);
    Q.Enqueue(8);
    Q.Enqueue(7);
    Q.Enqueue(6);
    Q.Enqueue(3);
    Q.Enqueue(10);

    while (!Q.isEmpty())
    {
        int passport = Q.Dequeue();

        if (passport % 4 == 0)
        {
            q4.Enqueue(passport);
        }
        else if (passport % 3 == 0)
        {
            q3.Enqueue(passport);
        }
        else if (passport % 2 == 0)
        {
            q2.Enqueue(passport);
        }
        else
        {
            q1.Enqueue(passport);
        }
    }

    cout << "Q: ";
    Q.display();

    cout << "\nq1: ";
    q1.display();

    cout << "\nq2: ";
    q2.display();

    cout << "\nq3: ";
    q3.display();

    cout << "\nq4: ";
    q4.display();

    return 0;
}
