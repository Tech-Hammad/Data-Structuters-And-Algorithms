#include "LinkedList.h"

class myLL :public LinkedList
{

public:
	void insertAtTail(int);
	void insertAtHead(int);
	void display();
	bool isEmpty();
	int deleteFromTail();
	int deleteFromHead();
	bool search(int);
	bool deleteValue(int);
	void insertSorted(int);
};



bool myLL::isEmpty()
{
	return tail == nullptr;
}

void myLL::insertAtHead(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	if (isEmpty()) //empty LL
	{
		tail = nn;
		tail->next = tail;
	}

	else //non-empty LL
	{

		nn->next = tail->next;
		tail->next = nn;
	}
}


void myLL::insertAtTail(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	if (isEmpty()) //empty LL
	{
		tail = nn;
		tail->next = tail;
	}

	else //non-empty LL
	{

		nn->next = tail->next;
		tail->next = nn;
		tail = nn;
	}
}

void myLL::display()
{
	if (isEmpty())
	{
		cout << "Linked List is empty" << endl;
	}
	else
	{
		Node* temp = tail->next;
		while (1)
		{
			cout << temp->data << " -> ";
			temp = temp->next;

			if (temp == tail->next)
			{
				break;
			}
		}
		cout << endl;
	}
}

int myLL::deleteFromHead()
{
	if (isEmpty())
	{
		cout << "List is empty. Cannot delete." << endl;
	}

	Node* head = tail->next;
	int value = head->data;

	// only one node
	if (tail == head) 
	{
		delete head;
		tail = nullptr;
	}
	else
	{
		tail->next = head->next;
		delete head;
	}
	return value;
}

int myLL::deleteFromTail()
{
	if (isEmpty())
	{
		cout << "List is empty. Cannot delete." << endl;
	}

	Node* head = tail->next;
	int value = tail->data;

	// only one node
	if (tail == head) 
	{
		delete tail;
		tail = nullptr;
	}
	else
	{
		Node* temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
		}
		temp->next = tail->next;
		delete tail;
		tail = temp;
	}
	return value;
}

bool myLL::search(int key)
{
	if (isEmpty())
	{
		return false;
	}
	Node* temp = tail->next;
	
	while (temp != tail->next)
	{
		if (temp->data == key)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool myLL::deleteValue(int key)
{
	if (isEmpty())
	{
		return false;
	}
	Node* current = tail->next;
	Node* prev = tail;

	while (current != tail->next)
	{
		if (current->data == key)
		{
			if (current == tail) // deleting tail
			{
				if (tail == tail->next) // only one node
				{
					delete tail;
					tail = nullptr;
				}
				else
				{
					prev->next = current->next;
					delete tail;
					tail = prev;
				}
			}
			else // deleting other than tail
			{
				prev->next = current->next;
				if (current == tail->next) // deleting head
				{
					tail->next = current->next;
				}
				delete current;
			}
			return true;
		}
		prev = current;
		current = current->next;
	} 
	return false;
}

void myLL::insertSorted(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	if (isEmpty())
	{
		tail = nn;
		tail->next = tail;
	}
	Node* current = tail->next;
	Node* prev = tail;

	while (current != tail->next)
	{
		if (value < current->data)
		{
			break;
		}
		prev = current;
		current = current->next;
	}
	nn->next = current;
	prev->next = nn;

	if (prev == tail) // insert at end
	{
		tail = nn;
	}
}

