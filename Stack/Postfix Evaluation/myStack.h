#include"Stack.h"
#include <string>

template <typename T>
class myStack :public Stack<T>
{
public:
	myStack(int size);
	bool isEmpty();
	bool isFull();
	void Push(T value);
	T Pop();
	T Top();
	void display() const;
	bool isOperator(char ch);
	int applyOperation(char operation, int op1, int op2);

};


template <typename T>
myStack<T>::myStack(int size) :Stack<T>(size)
{

}


template <typename T>
bool myStack<T>::isEmpty()
{
	return Stack<T>::currentSize == 0;
}


template <typename T>
bool myStack<T>::isFull()
{
	return Stack<T>::currentSize == Stack<T>::maxSize;
}


template <typename T>
void myStack<T>::Push(T value)
{
	if (isFull())
	{
		cout << "Stack is Full.\n";
	}
	else
	{
		Stack<T>::arr[Stack<T>::currentSize] = value;
		Stack<T>::currentSize++;
	}
}


template <typename T>
T myStack<T>::Pop()
{
	if (isEmpty())
	{
		cout << "Stack is Empty.\n";
		return NULL;
	}
	else
	{
		Stack<T>::currentSize--;
		return Stack<T>::arr[Stack<T>::currentSize];
	}
}


template <typename T>
T myStack<T>::Top()
{
	if (isEmpty())
	{
		cout << "Stack is Empty.\n";
		return NULL;
	}
	else
	{
		return Stack<T>::arr[Stack<T>::currentSize - 1];
	}
}


template <typename T>
void myStack<T>::display() const
{
	cout << "\nMaximum Size: " << Stack<T>::maxSize << "\n";
	cout << "Current Size: " << Stack<T>::currentSize << "\n\n";

	for (int i = 0;i < Stack<T>::currentSize;i++)
	{
		cout << i << ". " << Stack<T>::arr[i] << "\n";
	}
}

template <typename T>
bool myStack<T>::isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

template <typename T>
int myStack<T>::applyOperation(char operation, int op1, int op2)
{
	switch (operation)
	{
	case'+':
	{
		return op1 + op2;
	}
	case'-':
	{
		return op1 - op2;
	}
	case'*':
	{
		return op1 * op2;
	}
	case'/':
	{
		return op1 / op2;
	}
	}
}