#include "LinkedList.h"

class myLL :public LinkedList
{

public:
	bool isEmpty();
	void insertAtHead(int);
	void insertAtTail(int);
	int deleteFromHead();
	int deleteFromTail();
	bool search(int);
	void display();
	bool deleteValue(int);
	void insertSorted(int);
	void sort();
	void reverse();
	int getSize();
	int findMinimum();

};

bool myLL::isEmpty()
{
	return head == nullptr;
}

void myLL::insertAtHead(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	// Empty Linked List
	if (head == nullptr)
	{
		head = nn;
	}

	else // Non-Empty Linked List
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

	// Empty Linked List Case
	if (head == nullptr)
	{
		head = nn;
	}

	// Non-Empty Linked List Case
	else
	{
		Node* temp = head;

		while (1)
		{
			if (temp->next == nullptr)
			{
				break;
			}
			temp = temp->next;
		}
		temp->next = nn;
	}
}

int myLL::deleteFromHead()
{
	if (isEmpty())
	{
		return NULL;
	}

	// Single Node Case
	if (head->next == nullptr)
	{
		int returningValue = head->data;
		delete head;
		head = nullptr;
		return returningValue;
	}

	// Multiple Node Case
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
	if (isEmpty())
	{
		return NULL;
	}

	// Single Node Case
	if (head->next == nullptr)
	{
		int returningValue = head->data;
		delete head;
		head = nullptr;
		return returningValue;
	}

	// More than One Node Case
	else
	{
		Node* temp = head;

		while (1)
		{
			if (temp->next->next == nullptr)
			{
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
		int returningValue = temp->next->data;
		delete temp->next;
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

void myLL::display()
{
	if (head == nullptr)
	{
		cout << "Linked List is empty" << endl;
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

void myLL::insertSorted(int value)
{
	Node* nn = nullptr;
	nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	// Case 1: Empty list or value to be inserted at head
	if (isEmpty() || value < head->data)
	{
		nn->next = head;
		head = nn;
		return;
	}

	// Case 2: Traverse to find insertion point
	Node* temp = head;
	while (temp->next != nullptr && temp->next->data < value)
	{
		temp = temp->next;
	}

	nn->next = temp->next;
	temp->next = nn;
}

bool myLL::deleteValue(int value)
{
	if (isEmpty())
	{
		return false;
	}

	// Case 1: Value is in the head node
	if (head->data == value)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return true;
	}

	// Case 2: Search for the node before the one to delete
	Node* current = head;
	while (current->next != nullptr && current->next->data != value)
	{
		current = current->next;
	}

	// If value not found
	if (current->next == nullptr)
	{
		return false;
	}

	// Value found in current->next
	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
	return true;
}

void myLL::sort()
{
	Node* current;
	Node* index;
	int temp;

	for (current = head;current != nullptr;current=current->next)
	{
		for (index = current->next;index != nullptr;index = index->next)
		{
			if (current->data >  index->data)
			{
				temp = current->data;
				current->data = index->data;
				index->data = temp;
			}
		}
	}
}

void myLL::reverse()
{
	Node* prev = nullptr;
	Node* current = head;
	Node* front = nullptr;
	
	while (current != nullptr)
	{
		front = current->next;  // Store next
		current->next = prev;   // Reverse link
		prev = current;         // Move prev forward
		current = front;        // Move current forward
	}
	head = prev;
}

int myLL::getSize()
{
	Node* current = head;
	int count = 0;

	while (current != nullptr)
	{
		count++;
		current = current->next;
	}
	return count;
}

int myLL::findMinimum()
{
	int minValue = head->data;
	Node* temp = head;
	
	while (temp != nullptr)
	{
		if (temp->data < minValue)
		{
			minValue = temp->data;
		}
		temp = temp->next;
	}
	return minValue;
}