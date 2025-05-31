#include "myDLL.h"

int main()
{
	myDLL obj;

	obj.insertAtHead(10);
	obj.insertAtHead(20);
	obj.insertAtHead(30);
	obj.insertAtHead(40);
	obj.insertAtHead(50);
	obj.insertAtHead(60);
	obj.insertAtHead(70);
	obj.insertAtHead(80);
	obj.insertAtTail(-10);
	obj.insertAtTail(-10);
	obj.insertAtTail(-30);
	obj.insertAtTail(-40);
	obj.insertAtTail(-50);
	obj.insertAtTail(-60);
	obj.insertAtTail(-70);
	obj.insertAtTail(-80);
	obj.insertAtTail(-90);

	cout << "Delete From head:- " << obj.deleteFromHead() << endl;
	cout << "Delete From Tail:- " << obj.deleteFromTail() << endl;

	cout << "Delete 40 Value: " << obj.deleteValue(40) << endl;
	cout << "Delete -30 Value: " << obj.deleteValue(-30) << endl;
	cout << "Delete 1020 Value: " << obj.deleteValue(1020) << endl;

	cout << "\nDisplay From Head:-" << endl;
	obj.displayFromHead();

	cout << endl << endl;

	cout << "Display From Tail:-" << endl;
	obj.displayFromTail();

	cout << "\n\nSearch in List 60: " << obj.search(60) << "\n";
	cout << "Search in List -10: " << obj.search(-10) << "\n";
	cout << "Search in List 120: " << obj.search(120) << "\n";

	return 0;
}