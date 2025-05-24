#include "myDLL.h"

int main()
{
	myDLL obj;

	obj.CreateNode(99);
	obj.CreateNode(1024);
	obj.CreateNode(15);
	obj.CreateNode(20);
	obj.CreateNode(43);
	obj.CreateNode(24);
	obj.CreateNode(56);

	obj.display();

	cout << endl << endl;

	cout << "Displaying Reverse List:-\n";
    
	obj.displayReverse();

	cout << endl << endl;

	return 0;
}