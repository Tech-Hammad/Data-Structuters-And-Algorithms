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
	bool isValidParentheses(string s);
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
bool myStack<T>::isValidParentheses(string s)
{
	myStack<T>stk(s.length());  // Temp stack for processing and here s.length is built in function

	for (int i = 0; i < s.length(); i++)
	{
		char ch = s[i];

		if (ch == '(' || ch == '{' || ch == '[')
		{
			stk.Push(ch);
		}
		else
		{
			if (stk.isEmpty())
			{
				return false;
			}
			char topChar = stk.Pop();

			if ((ch == ')' && topChar != '(') || (ch == '}' && topChar != '{') ||
				(ch == ']' && topChar != '['))
			{
				return false;
			}
		}
	}
	return stk.isEmpty();
}