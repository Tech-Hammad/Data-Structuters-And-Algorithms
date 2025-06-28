#include "LinkedList.h"

class myDLL :public LinkedList
{

public:
	bool isEmpty();
	void insertAtHead(int);
	void insertAtTail(int);
	void displayFromHead();
	void displayFromTail();
	Node* removeFromFront();
	void mergeList(LinkedList& other);
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

Node* myDLL::removeFromFront()
{
	if (head == nullptr)
	{
		return nullptr;
	}
	Node* removedNode = head;
	head = head->next;

	if (head != nullptr) 
	{
		head->prev = nullptr;
	}
	else 
	{
		tail = nullptr; 
	}
	
	removedNode->next = nullptr;
	removedNode->prev = nullptr;
	return removedNode;
}

void myDLL::mergeList(LinkedList& otherList)
{
	while (!otherList.isEmpty())
	{
		Node* nodeToMove = otherList.removeFromFront();
		insertAtTail(nodeToMove->data);
		delete nodeToMove;
	}
}
