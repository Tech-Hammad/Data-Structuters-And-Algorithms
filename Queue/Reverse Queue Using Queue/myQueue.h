#include <iostream>
#include "Queue.h"
using namespace std;

template <typename T>
class myQueue :public Queue<T>
{
public:
	myQueue(int s);
	void Enqueue(T value);
	T Dequeue();
	T Peek();
	void display();
	bool isEmpty();
	bool isFull();
};

template <typename T>
myQueue<T>::myQueue(int s) :Queue<T>(s)
{

}

template <typename T>
bool myQueue<T>::isFull()
{
	return Queue<T>::maxSize == Queue<T>::currentSize;
}

template <typename T>
bool myQueue<T>::isEmpty()
{
	return Queue<T>::currentSize == 0;
}

template <typename T>
void myQueue<T>::Enqueue(T value)
{
	if (isFull())
	{
		cout << "Queue is FULL" << endl;
	}
	else
	{
		Queue<T>::arr[Queue<T>::currentSize] = value;
		Queue<T>::currentSize++;
	}

}

template <typename T>
T myQueue<T>::Dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
		return NULL;
	}

	else
	{
		T returningValue = Queue<T>::arr[0];
		Queue<T>::currentSize--;
		for (int i = 0; i < Queue<T>::currentSize; i++)
		{
			Queue<T>::arr[i] = Queue<T>::arr[i + 1];
		}

		return returningValue;  // This return the dequeued value
	}

}


template <typename T>
T myQueue<T>::Peek()
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
		return NULL;
	}

	else
	{
		return Queue<T>::arr[0];
	}

}

template <typename T>
void myQueue<T>::display()
{
	cout << "Max Size = " << Queue<T>::maxSize << endl;
	cout << "Current Size = " << Queue<T>::currentSize << endl;

	for (int i = 0; i < Queue<T>::currentSize; i++)
	{
		cout << i << ". " << Queue<T>::arr[i] << endl;
	}
}