#include<iostream>
using namespace std;

template<typename T>
class Stack
{
protected:
	T* arr;
	int maxSize;
	int currentSize;
public:
	Stack(int size);
	virtual void Push(T value) = 0;
	virtual T Pop() = 0;
	virtual T Top() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual bool isOperator(char ch) = 0;
	virtual int applyOperation(char operation, int op1, int op2) = 0;

};

template<typename T>
Stack<T>::Stack(int size)
{
	arr = new T[size];
	currentSize = 0;
	maxSize = size;
}