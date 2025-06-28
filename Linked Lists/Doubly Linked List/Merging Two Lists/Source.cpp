#include <iostream>
#include "myDLL.h"
using namespace std;

int main()
{
	myDLL list1, list2;

    list1.insertAtTail(1);
    list1.insertAtTail(3);
    list1.insertAtTail(5);

    list2.insertAtTail(2);
    list2.insertAtTail(4);
    list2.insertAtTail(6);

    cout << "List 1: ";
    list1.displayFromHead();

    cout << "List 2: ";
    list2.displayFromHead();

    // Merge list2 into list1 (the easy way)
    list1.mergeList(list2);

    cout << "Merged List: ";
    list1.displayFromHead();

    cout << "List 2 (should be empty): ";
    list2.displayFromHead();

	return 0;
}