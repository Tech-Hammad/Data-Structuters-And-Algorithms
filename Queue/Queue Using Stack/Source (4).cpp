// Implementing Queue Operations Using Stack Data Structure
#include<iostream>
#include"myStack.h"
using namespace std;


int main()
{
	myStack<int>stack1(5);
	myStack<int>stack2(5);

	int value;  // Datatype To be Decided According to Stack Data
	int choice;
	do
	{
		cout << "------ Queue Menu ------";
		cout << "1. Enqueue Element\n";
		cout << "2. Dequeue Element\n";
		cout << "3. Front Element\n";
		cout << "4. Display Queue\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter value to Enqueue: ";
			cin >> value;

			while (!stack1.isEmpty())
			{
				stack2.Push(stack1.Top());
				stack1.Pop();
			}

			stack1.Push(value);

			while (!stack2.isEmpty())
			{
				stack1.Push(stack2.Top());
				stack2.Pop();
			}
			break;
		}
		case 2:
		{
			if (stack1.isEmpty() && stack2.isEmpty())
			{
				cout << "Queue is empty!\n";
				break;
			}

			int front = stack1.Top();
			stack1.Pop();

			cout << "Dequeued Value: " << front << "\n";
			break;
		}
		case 3:
		{
			if (!stack1.isEmpty())
			{
				cout << "Front element: " << stack1.Top() << "\n";
			}
			break;
		}
		case 4:
		{
			myStack<int>temp1(5);
			myStack<int>temp2(5);
			cout << "Queue Elements Front to Rear: ";

			while (!stack1.isEmpty())
			{
				temp1.Push(stack1.Pop());
			}

			while (!temp1.isEmpty())
			{
				stack1.Push(temp1.Pop());
			}

			while (!stack1.isEmpty())
			{
				temp2.Push(stack1.Pop());
			}

			temp2.display();
			cout << "\n";
			break;
		}
		case 5:
		{
			cout << "Exiting the Program...\n";
			break;
		}

		default:
			cout << "Invalid choice!\n";
			break;
		}

	} while (choice != 5);

	return 0;
}
