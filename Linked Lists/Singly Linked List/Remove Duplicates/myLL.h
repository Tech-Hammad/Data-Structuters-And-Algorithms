#include <iostream>
#include "LinkedList.h"
using namespace std;

class myLL :public LinkedList
{
public:
	bool isEmpty();
	void insertAtHead(int);
	void insertAtTail(int);
	int deleteFromTail();
	int deleteFromHead();
	bool search(int);
	void insertSorted(int value);
	bool deleteValue(int value);
	void display();
	void removeDuplicates();
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

int myLL::deleteFromHead()
{
	if (isEmpty())
	{
		return NULL;
	}

	// If there is Single Node in Linked List
	if (head == tail)
	{
		int returningValue = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	// If there is more than one Node in Linked List
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


int myLL::deleteFromTail()
{
	// If the Linked List is Empty
	if (isEmpty())
	{
		return NULL;
	}

	// If there is Single Node in Linked List
	if (head == tail)
	{
		int returningValue = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	// If there is more than One Node in Linked List
	else
	{
		Node* temp = head;

		while (1)
		{
			if (temp->next == tail)
			{
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
		int returningValue = tail->data;
		delete tail;
		tail = temp;
		temp->next = nullptr;
		return returningValue;
	}
}

bool myLL::search(int value)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		Node* temp = head;

		while (1)
		{
			if (temp->data == value)
			{
				return true;
			}
			temp = temp->next;

			if (temp == nullptr)
			{
				return false;
			}
		}
	}
}

void myLL::insertSorted(int value)
{
	if (isEmpty())
	{
		Node* nn = nullptr;
		nn = new Node;
		nn->data = value;
		nn->next = nullptr;

		head = nn;
		tail = nn;
	}

	else if (value <= head->data)
	{
		insertAtHead(value);
	}
	else if (value >= tail->data)
	{
		insertAtTail(value);
	}

	// Case: Insert in Between
	else
	{
		Node* nn = nullptr;
		nn = new Node;
		nn->data = value;
		nn->next = nullptr;

		Node* temp = head;

		while (1)
		{
			if (temp->data < value && temp->next->data >= value)
			{
				break;
			}
			else
			{
				temp = temp->next;
			}
		}

		nn->next = temp->next;
		temp->next = nn;
	}

}

bool myLL::deleteValue(int value)
{
	if (isEmpty())
	{
		return false;
	}

	// Single Node Case
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
			if (temp->next->data == value)
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

		Node* t2 = temp->next;
		temp->next = temp->next->next;
		delete t2;
		t2 = nullptr;

		return true;
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
			cout << temp->data << "   ->   ";
			temp = temp->next;

			if (temp == nullptr)
			{
				break;
			}
		}
	}
}

void myLL::removeDuplicates()
{
	 if (isEmpty()) 
	{
		cout << "Linked List is Empty.\n";
		return;
	}

	Node* current = head;
	Node* prev = nullptr;

	while (current != nullptr) 
	{
		Node* checker = head;
		bool foundDuplicate = false;

		// Check if current->data has appeared earlier in the list
		while (checker != current)
		{
			if (checker->data == current->data) 
			{
				foundDuplicate = true;
				break;
			}
			checker = checker->next;
		}

		if (foundDuplicate) 
		{
			// Remove current node
			Node* temp = current;
			prev->next = current->next;

			/*If the Node being Deleted was the Last Node we Update the Tail Pointer 
			to point to the Previous Node (prev).*/

			if (current == tail)
			{
				tail = prev;
			}
			current = current->next;
			delete temp;
		}

		else
		{
			prev = current;
			current = current->next;
		}
	}
}

