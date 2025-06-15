#include <iostream>
#include "LinkedList.h"
using namespace std;

class myLL :public LinkedList
{
public:
	bool isEmpty();
	void insertAtHead(int);
	void insertAtTail(int);
	void display();
	int deleteFromHead();
};


bool myLL::isEmpty()
{
	return head == nullptr && tail == nullptr;
}

void myLL::insertAtHead(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	// Empty Linked List
	if (head == nullptr && tail == nullptr)
	{
		head = nn;
		tail = nn;
	}

	// Non-Empty Linked List
	else
	{
		nn->next = head;
		head = nn;

	}
}

void myLL::insertAtTail(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	// Empty Linked List
	if (head == nullptr && tail == nullptr)
	{
		head = nn;
		tail = nn;
	}

	// Non-Empty Linked List
	else
	{
		tail->next = nn;
		tail = nn;
	}
}
 
void myLL::display()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty" << endl;
	}
	else
	{
		Node* temp = head;

		while (1)
		{
			cout << temp->data << "  ->  ";
			temp = temp->next;

			if (temp == nullptr)
			{
				break;
			}
		}
	}
}

int myLL::deleteFromHead()
{
	if (isEmpty())
	{
		return NULL;
	}

	if (head == tail)
	{
		int returningValue = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		Node* temp = head;
		int returningValue = head->data;

		head = head->next;
		delete temp;
		temp = nullptr;

		return returningValue;
	}
}

int checkIfWon(myLL ticketLinkedList)
{
	int digits[20]; 
	int size = 0;
	int sum = 0;

	while (!ticketLinkedList.isEmpty())
	{
		int digit = ticketLinkedList.deleteFromHead();
		digits[size++] = digit;
		sum = sum + digit;
	}

	bool isPalindrome = true;
	for (int i = 0; i < size / 2; i++)
	{
		if (digits[i] != digits[size - 1 - i])
		{
			isPalindrome = false;
		}
	}

	for (int i = 0; i < size; i++)
	{
		ticketLinkedList.insertAtTail(digits[i]);
	}

	if (isPalindrome && size == 4 && sum > 20)
	{
		return 3000;
	}
	else if (isPalindrome)
	{
		return 2000;
	}
	else if (size == 4 && sum > 20)
	{
		return 1000;
	}
	else
	{
		return 0;
	}
}
