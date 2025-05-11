#include <iostream>
#include "myLL.h" 
using namespace std;

int main()
{
    myLL list1;
    myLL list2;

    list1.insertAtHead(10);
    list1.insertAtHead(20);
    list1.insertAtHead(30);
    list1.insertAtHead(40);
    list1.insertAtHead(50);
    list1.display();

    list2.insertAtHead(10);
    list2.insertAtHead(20);
    list2.insertAtHead(30);
    list2.insertAtHead(40);
    list2.insertAtHead(50);
    list2.display();
    
    cout << "\nComparing Lists:- \n";
    if (list1.compareLinkedLists(list2))
    {
        cout << "Both List have same size and same Elemnts.\n";
    }
    else
    {
        cout << "Lists not matched.\n";
    }

    return 0;
}