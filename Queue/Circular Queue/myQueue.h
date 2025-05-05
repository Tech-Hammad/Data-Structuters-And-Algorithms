#include "Queue.h"

//CIRCULAR QUEUE

template <class T>
class myQueue :public Queue<T>
{
	int front;	//for dequeue; shows the first value in queue
	int rear;	// for enqueue; to add values
public:
	void enqueue(T value);
	T dequeue();
	T peek();
	myQueue(int s);
	void display();
	bool isEmpty();
	bool isFull();
};

template <class T>
bool myQueue<T>::isFull()		// O(1)
{
	return Queue<T>::maxSize == Queue<T>::currentSize;
}

template <class T>
bool myQueue<T>::isEmpty()	    // O(1)
{
	return Queue<T>::currentSize == 0;
}


template <class T>
myQueue<T>::myQueue(int s) :Queue<T>(s)
{
	front = 0;
	rear = 0;
}

template <class T>			// O(1)
void myQueue<T>::enqueue(T value)
{
	if (isFull())
	{
		cout << "Queue is FULL" << endl;
	}

	else
	{
		Queue<T>::arr[rear % Queue<T>::maxSize] = value;
		Queue<T>::currentSize++;
		rear++;
	}

}

template <class T>			// O(1)
T myQueue<T>::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
		return NULL;
	}

	else
	{
		Queue<T>::currentSize--;
		return Queue<T>::arr[front++ % Queue<T>::maxSize];
	}

}


template <class T>			// O(1)
T myQueue<T>::peek()
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
		return NULL;
	}

	else
	{
		return Queue<T>::arr[front % Queue<T>::maxSize];
	}

}

template <class T>
void myQueue<T>::display()				// O(N)
{
	cout << "Max Size = " << Queue<T>::maxSize << endl;
	cout << "Current Size = " << Queue<T>::currentSize << endl;
	cout << "Front = " << front << endl;
	cout << "Rear = " << rear << endl;
	cout << "Current Size (rear - front) = " << rear - front << endl;

	for (int i = front; i < rear; i++)
	{
		cout << i % myQueue<T>::maxSize << ". " << myQueue<T>::arr[i % myQueue<T>::maxSize] << endl;
	}
}