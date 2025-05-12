#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Queue
{
protected:
	T* arr;
	int maxSize;
	int currentSize;
public:
	virtual void Enqueue(T value) = 0;
	virtual T Dequeue() = 0;
	Queue(int size);
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual T Rear() = 0;
	virtual int getCurrentSize() = 0;
	virtual int getCapacity() = 0;
};

template<typename T>
Queue<T>::Queue(int size)
{
	maxSize = size;
	currentSize = 0;
	arr = new T[size];
}