#include "myStack.h"
using namespace std;

int main()
{
	int size;
	cout << "Enter size of stack: ";
	cin >> size;

	myStack<int>stack(size);
	myStack<int>tempstack(size);

	cout << "Enter Elements of Stack:-\n";
	for (int i = 0; i < size; i++)
	{
		int element;
		cout << i << ". ";
		cin >> element;
		stack.Push(element);
	}

	int index, newValue;
	cout << "Enter the Index with Value to be Change: ";
	cin >> index >> newValue;

	int count = 0;

	while (!stack.isEmpty() && count < index)
	{
		tempstack.Push(stack.Pop());
		count++;
	}

	if (!stack.isEmpty())
	{
		stack.Pop();   // Remove Old Element
		stack.Push(newValue);   // Push New Element
	}

	// Now Pop Back Remaning ELements from the Temp Stack

	while (!tempstack.isEmpty())
	{
		stack.Push(tempstack.Pop());
	}

	stack.display();

	return 0;
}