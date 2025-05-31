#include <iostream>
#include "myDLL.h" 
using namespace std;

int main()
{
	myDLL list;

	cout << "Inserting at tail: 10, 20, 30\n";
	list.insertAtTail(10);
	list.insertAtTail(20);
	list.insertAtTail(30);
	cout << "Display from head:\n";
	list.display();

	cout << "\nInserting at head: 5, 1\n";
	list.insertAtHead(5);
	list.insertAtHead(1);
	cout << "Display from head:\n";
	list.display();

	cout << "\nDisplay from tail:\n";
	list.display();

	cout << "\nSearching for 20 and 99:\n";
	cout << "20 found? " << list.search(20) << endl;
	cout << "99 found? " << list.search(99) << endl;

	cout << "\nDeleting value 10...\n";
	if (list.deleteValue(10))
	{
		cout << "10 deleted.\n";
	}
	else
	{
		cout << "10 not found.\n";
	}
	list.display();

	cout << "\nDeleting value 1 (head)...\n";

	if (list.deleteValue(1))
	{
		cout << "1 deleted.\n";
	}
	else
	{
		cout << "1 not found.\n";
	}
	list.display();

	cout << "\nDeleting value 30 (tail)...\n";
	if (list.deleteValue(30))
	{
		cout << "30 deleted.\n";
	}
	else
	{
		cout << "30 not found.\n";
	}
	list.display();

	cout << "\nDeleting from head:\n";
	cout << "Deleted value: " << list.deleteFromHead() << endl;
	list.display();

	cout << "\nDeleting from tail:\n";
	cout << "Deleted value: " << list.deleteFromTail() << endl;
	list.display();

	cout << "\nTrying to delete from empty list:\n";
	cout << "Deleted from head: " << list.deleteFromHead() << endl;
	cout << "Deleted from tail: " << list.deleteFromTail() << endl;

	return 0;
}
