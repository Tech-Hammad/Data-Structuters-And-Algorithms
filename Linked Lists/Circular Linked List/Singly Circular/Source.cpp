#include <iostream>
#include "myLL.h"  
using namespace std;

int main()
{
	myLL list;

	cout << "Inserting values at tail: 10, 20, 30\n";
	list.insertAtTail(10);
	list.insertAtTail(20);
	list.insertAtTail(30);
	list.display();

	cout << "\nInserting values at head: 5, 1\n";
	list.insertAtHead(5);
	list.insertAtHead(1);
	list.display();

	cout << "\nSearching for 20 and 100:\n";
	cout << "20 found? " << list.search(20) << endl;
	cout << "100 found? " << list.search(100) << endl;

	cout << "\nDeleting from head...\n";
	cout << "Deleted value: " << list.deleteFromHead() << endl;
	list.display();

	cout << "\nDeleting from tail...\n";
	cout << "Deleted value: " << list.deleteFromTail() << endl;
	list.display();

	cout << "\nDeleting value 10 from list...\n";
	if (list.deleteValue(10))
	{
		cout << "Value 10 deleted.\n";
	}
	else
	{
		cout << "Value 10 not found.\n";
	}
	list.display();

	cout << "\nDeleting value 999 (non-existent)...\n";
	if (list.deleteValue(999))
	{
		cout << "Value deleted.\n";
	}
	else
	{
		cout << "Value not found.\n";
	}
	list.display();

	cout << "\nInserting values using insertSorted: 15, 7, 100, 3\n";
	list.insertSorted(15);
	list.insertSorted(7);
	list.insertSorted(100);
	list.insertSorted(3);
	list.display();

	return 0;
}
