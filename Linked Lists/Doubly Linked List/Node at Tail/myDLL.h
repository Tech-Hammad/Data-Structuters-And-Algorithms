#include "LinkedList.h"

class myDLL :public LinkedList
{
public:
	bool isEmpty();
	void CreateNode(int value);
	void display();
	void displayReverse();
};

bool myDLL::isEmpty()
{
	return head == nullptr && tail == nullptr;
}


// CreateNode: Inserts a node at the tail
void myDLL::CreateNode(int value) 
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	if (head == nullptr)
	{
		// First node in the list
		head = newNode;
		tail = newNode;
	}
	else
	{
		// Add at the end using tail
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}


void myDLL::display()
{
	if (isEmpty())
	{
		cout << "The list is empty.\n";
	}

	Node* temp = head;
	cout << "List elements: ";
	
	while (temp != nullptr)
	{
		cout << temp->data << " <--> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

void myDLL::displayReverse() 
{
	if (isEmpty()) 
	{
		cout << "The list is empty.\n";		
	}

	Node* temp = tail;
	cout << "List in reverse: ";
	while (temp != nullptr) 
	{
		cout << temp->data << " <--> ";
		temp = temp->prev;
	}
	cout << "NULL\n";
}

