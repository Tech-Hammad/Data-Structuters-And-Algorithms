#include <iostream>
#include "myQueue.h"
using namespace std;

int main()
{
	myQueue<int> q(5);
	myQueue<int> temp(5); // Temporary queue to store reversed elements

	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.Enqueue(40);
	q.Enqueue(50);

	int n = 0;
	while (!q.isEmpty())
	{
		int val = q.Dequeue();
		temp.Enqueue(val);
		n++;
	}
	// Restore original elements back to q
	while (!temp.isEmpty())
	{
		q.Enqueue(temp.Dequeue());
	}

	// Reverse process
	for (int i = 0; i < n; i++)
	{
		// Move first (n - i) elements to the end to access the last element
		for (int j = 0; j < n - i -1; j++)
		{
			q.Enqueue(q.Dequeue());
		}

		// Remove and store the last element in temp
		temp.Enqueue(q.Dequeue());
	}

	// Push reversed elements back into the original queue
	while (!temp.isEmpty())
	{
		q.Enqueue(temp.Dequeue());
	}

	cout << "\nReversed Queue:-\n";
	q.display();

	return 0;
}
