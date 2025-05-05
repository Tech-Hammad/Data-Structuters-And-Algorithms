// Implementation of minimum and maximum value in stack

#include <iostream>
#include <string>
#include "myStack.h"
using namespace std;

int main()
{
	int size;
	cout << "Enter size of stack: ";
	cin >> size;

	myStack<int>s(size);
	myStack<int>tempstack(size);
	int choice;

	int value;  // To be Decided According to Stack Data
	do
	{
		cout << "\n------ Stack Menu ------\n";
		cout << "1. Push Element\n";
		cout << "2. Pop Element\n";
		cout << "3. Top Element\n";
		cout << "4. Display Stack\n";
		cout << "5. Maximum Element\n";
		cout << "6. Minimum Element\n";
		cout << "7. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter value to push: ";
			cin >> value;
			s.Push(value);
			break;
		}
		case 2:
		{
			cout << "Popped: " << s.Pop() << "\n";
			break;
		}
		case 3:
		{
			cout << "Top: " << s.Top() << "\n";
			break;
		}
		case 4:
		{
			s.display();
			break;
		}
		case 5:
		{
			if (s.isEmpty())
			{
				cout << "Stack is Empty.\n";
			}

			int maxElement = s.Top();
			tempstack.Push(s.Pop());

			while (!s.isEmpty())
			{
				if (s.Top() > maxElement)
				{
					maxElement = s.Top();
				}
				tempstack.Push(s.Pop());
			}

			while (!tempstack.isEmpty())
			{
				s.Push(tempstack.Pop());
			}

			cout << "Maximum Element: " << maxElement << "\n";
			break;
		}

		case 6:
		{
			int minimumElement = s.Top();
			tempstack.Push(s.Pop());

			while (!s.isEmpty())
			{
				if (s.Top() < minimumElement)
				{
					minimumElement = s.Top();
				}
				tempstack.Push(s.Pop());
			}

			while (!tempstack.isEmpty())
			{
				s.Push(tempstack.Pop());
			}

			cout << "Minimum Element: " << minimumElement << "\n";
			break;
		}
		case 7:
		{
			cout << "Exiting the Program...\n";
			break;
		}

		default:
			cout << "Invalid choice!\n";
			break;
		}

	} while (choice != 7);

	return 0;
}