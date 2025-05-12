#include <iostream>
#include "Queue.h"
using namespace std;

template <typename T>
class myQueue :public Queue<T>
{
private:
	int count;
public:
	myQueue(int s);
	void Enqueue(T value);
	T Dequeue();
	T Rear();
	void display();
	bool isEmpty();
	bool isFull();
	int getCurrentSize();
	int getCapacity();
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
		count++;
	}
}

template <typename T>
T myQueue<T>::Dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
	}

	else
	{
		T returningValue = Queue<T>::arr[0];
		Queue<T>::currentSize--;
		count--;
		for (int i = 0; i < Queue<T>::currentSize; i++)
		{
			Queue<T>::arr[i] = Queue<T>::arr[i + 1];
		}

		return returningValue;  
	}

}

template <typename T>
T myQueue<T>::Rear()
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
	}

	else
	{
		return Queue<T>::arr[Queue<T>::currentSize - 1];
	}

}

template <typename T>
void myQueue<T>::display()
{
	for (int i = 0; i < Queue<T>::currentSize; i++)
	{
		Queue<T>::arr[i].display();
	}
}

template <typename T>
int myQueue<T>::getCurrentSize()
{
	return count;
}

template <typename T>
int myQueue<T>::getCapacity()
{
	return Queue<T>::maxSize;
}
