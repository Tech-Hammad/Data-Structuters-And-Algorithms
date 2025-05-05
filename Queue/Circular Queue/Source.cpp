#include "myQueue.h"

int main()
{
	myQueue<int> obj(4);

	obj.enqueue(265);
	obj.enqueue(1985);
	obj.enqueue(-3);
	obj.enqueue(91);

	cout << "Dequeue Value: " << obj.dequeue() << endl << endl;
	cout << "Dequeue Value: " << obj.dequeue() << endl << endl;
	obj.enqueue(1000);
	cout << "Dequeue Value: " << obj.dequeue() << endl << endl;
	obj.enqueue(88);
	cout << "Dequeue Value: " << obj.dequeue() << endl << endl;

	cout << "Dequeue Value: " << obj.dequeue() << endl << endl;


	cout << "Peeked Value: " << obj.peek() << endl;

	cout << "int display: " << endl;
	obj.display();


	return 0;
}