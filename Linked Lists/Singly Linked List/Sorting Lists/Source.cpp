#include <iostream>
#include "myLL.h" 
using namespace std;

int main()
{
    myLL list;

    list.insertAtHead(10);
    list.insertAtHead(6);
    list.insertAtHead(5);
    list.insertAtHead(14);
    list.insertAtHead(20);
    list.insertAtHead(1);
    list.insertAtHead(9);
    cout << "List Before Sorting:-\n";
    list.display();

    list.sort();
    
    cout << "\nList After Sorting:-\n";
    list.display();

    list.reverse();
    cout << "\nList After Reverse:-\n";
    list.display();

    cout << "\nTotal Elements in List:- ";
    cout << list.getSize();

    cout << "\nMinimum Value in List:- ";
    cout << list.findMinimum();

    return 0;
}