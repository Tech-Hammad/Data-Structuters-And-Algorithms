#include "LinkedList.h"

class myDLL :public LinkedList
{

public:
	bool isEmpty();
	void insertAtHead(int);
	void insertAtTail(int);
	void displayFromHead();
	void displayFromTail();
	int deleteFromTail();
	int deleteFromHead();
	bool deleteValue(int);
	bool search(int);
};

bool myDLL::isEmpty()
{
	return head == nullptr && tail == nullptr;
}

void myDLL::insertAtHead(int value)
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

void myDLL::insertAtTail(int value)
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

bool myDLL::deleteValue(int value)
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

int myDLL::deleteFromHead()
{
	if (isEmpty())
	{
		return NULL;
	}
	// Single node case
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
		int returningValue = head->data;

		head = head->next;
		delete head->prev;
		head->prev = nullptr;

		return returningValue;

	}
}

int myDLL::deleteFromTail()
{
	if (isEmpty())
	{
		return NULL;
	}
	// single node case
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
		int returningValue = tail->data;
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
		return returningValue;
	}
}

bool myDLL::search(int value)
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