#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

class myDLL :public LinkedList
{

public:
	bool isEmpty();
	void insertAtHead(Student);
	void insertAtTail(Student);
	void displayFromHead();
	void displayFromTail();
	Student deleteFromTail();
	Student deleteFromHead();
	bool deleteValue(Student);
	bool search(Student);

	Node* getHead();
	Node* getTail();
};

bool myDLL::isEmpty()
{
	return head == nullptr && tail == nullptr;
}

void myDLL::insertAtHead(Student value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;
	nn->prev = nullptr;

	// Empty LL
	if (head == nullptr && tail == nullptr)
	{
		head = nn;
		tail = nn;
	}
	// non-empty LL
	else
	{
		nn->next = head;
		head->prev = nn;
		head = nn;

	}
}

void myDLL::insertAtTail(Student value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;
	nn->prev = nullptr;

	// Empty LL
	if (head == nullptr && tail == nullptr)
	{
		head = nn;
		tail = nn;
	}
	// Non-empty LL
	else
	{
		nn->prev = tail;
		tail->next = nn;
		tail = nn;
	}
}

void myDLL::displayFromHead()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "Linked List is Empty" << endl;
	}
	else
	{
		Node* temp = head;

		while (1)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
			if (temp == nullptr)
			{
				cout << "NULL\n";
				break;
			}
		}
	}
}

void myDLL::displayFromTail()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "Linked List is Empty" << endl;
	}
	else
	{
		Node* temp = tail;

		while (1)
		{
			cout << temp->data << " -> ";
			temp = temp->prev;

			if (temp == nullptr)
			{
				cout << "NULL\n";
				break;
			}
		}
	}
}

bool myDLL::deleteValue(Student value)
{
	if (isEmpty())
	{
		return false;
	}
	// Single Node
	else if (head == tail)
	{
		if (head->data == value)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return true;
		}
		else
		{
			return false;
		}
	}

	else if (head->data == value)
	{
		deleteFromHead();
		return true;
	}

	else if (tail->data == value)
	{
		deleteFromTail();
		return true;
	}

	else
	{
		Node* temp = head;

		while (1)
		{
			if (temp->data == value)
			{
				break;
			}
			else
			{
				temp = temp->next;
			}
			if (temp == tail)
			{
				return false;
			}
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		temp = nullptr;

		return true;
	}

}

Student myDLL::deleteFromHead()
{
	if (isEmpty())
	{
		return Student();
	}
	// Single node case
	if (head == tail)
	{
		Student returningValue = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		Student returningValue = head->data;

		head = head->next;
		delete head->prev;
		head->prev = nullptr;

		return returningValue;

	}
}

Student myDLL::deleteFromTail()
{
	if (isEmpty())
	{
		return Student();
	}
	// single node case
	if (head == tail)
	{
		Student returningValue = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}
	else
	{
		Student returningValue = tail->data;
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
		return returningValue;
	}
}

bool myDLL::search(Student value)
{
	if (isEmpty())
	{
		return false;
	}
	Node* temp = head;

	while (temp != nullptr)
	{
		if (temp->data == value)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

Node* myDLL::getHead()
{
	return head;
}

Node* myDLL::getTail()
{
	return tail;
}