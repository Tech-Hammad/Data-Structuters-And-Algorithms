#include <iostream>
#include "myLL.h" 
using namespace std;

int main()
{
    myLL list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.insertAtHead(40);
    list.insertAtHead(20);
    list.insertAtHead(50);
    list.display();


    cout << "\n\nTesting insertAtTail():" << endl;
    list.insertAtTail(40);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(50);
    list.display();


    cout << "\n\nTesting deleteFromHead():" << endl;
    cout << "Deleted: " << list.deleteFromHead() << endl;
    list.display();


    cout << "\n\nTesting deleteFromTail():" << endl;
    cout << "Deleted: " << list.deleteFromTail() << endl;
    list.display();


    cout << "\n\nTesting search():" << endl;
    cout << "Searching : " << list.search(10) << endl;
    cout << "Searching : " << list.search(100) << endl;


    cout << "\n\nTesting insertSorted():" << endl;
    list.insertSorted(25);
    list.insertSorted(5);
    list.insertSorted(100);
    list.display();

    cout << "\n\nTesting deleteValue():" << endl;
    cout << "Deleting : " << list.deleteValue(25) << endl;
    cout << "Deleting : " << list.deleteValue(5) << endl;
    cout << "Deleting : " << list.deleteValue(999) << endl;
    list.display();


    cout << "\n\nRemoving duplicates from list:" << endl;
    list.removeDuplicates();
    list.display();

    return 0;
}