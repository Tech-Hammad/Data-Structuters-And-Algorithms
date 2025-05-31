#include "LinkedList.h"

class myDLL :public LinkedList
{

public:
	void insertAtTail(int);
	void insertAtHead(int);
	void display();
	bool isEmpty();
	bool search(int);
	int deleteFromTail();
	int deleteFromHead();
	bool deleteValue(int);
};

void myDLL::insertAtTail(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;
	nn->prev = nullptr;

	if (head == nullptr) //empty LL
	{
		head = nn;
		head->prev = nn;
		nn->next = head;
	}

	else //non-empty LL
	{
		nn->next = head;
		nn->prev = head->prev;
		head->prev = nn;
		head->prev->prev->next = nn; //nn->prev->next = nn;
	}
}

void myDLL::insertAtHead(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;
	nn->prev = nullptr;

	if (head == nullptr) //empty LL
	{
		head = nn;
		head->prev = nn;
		nn->next = head;
	}

	else //non-empty LL
	{
		nn->next = head;
		nn->prev = head->prev;
		head->prev = nn;
		head->prev->prev->next = nn; //nn->prev->next = nn;
		head = nn;
	}
}

bool myDLL::isEmpty()
{
	return head == nullptr;
}

void myDLL::display()
{
	if (head == nullptr)
	{
		cout << "LL is empty" << endl;
	}
	else
	{
		Node* temp = head;
		while (1)
		{
			cout << temp->data << " -> ";
			temp = temp->next;

			if (temp == head)
			{
				break;
			}
		}
		cout << endl;
	}
}

bool myDLL::search(int value)
{
	if (isEmpty())
	{
		return false;
	}
	Node* temp = head;
	while (temp != head)
	{
		if (temp->data == value)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool myDLL::deleteValue(int value)
{
	if (isEmpty())
	{
		return false;
	}
	Node* temp = head;
	
	while (temp != head)
	{
		if (temp->data == value)
		{
			if (temp == head && temp == head->prev) // Only one node
			{
				delete temp;
				head = nullptr;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;

				if (temp == head)
				{
					head = head->next;
				}
				delete temp;
			}
			return true;
		}
		temp = temp->next;
	}
	return false;
}

int myDLL::deleteFromHead()
{
	if (isEmpty())
	{
		cout << "List is empty" << endl;
	}

	int val = head->data;

	if (head->next == head) // Single node
	{
		delete head;
		head = nullptr;
	}
	else
	{
		Node* temp = head;
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
		delete temp;
	}
	return val;
}

int myDLL::deleteFromTail()
{
	if (isEmpty())
	{
		cout << "List is empty" << endl;
	}

	Node* tail = head->prev;
	int val = tail->data;

	if (tail == head) // Single node
	{
		delete head;
		head = nullptr;
	}
	else
	{
		tail->prev->next = head;
		head->prev = tail->prev;
		delete tail;
	}
	return val;
}
