#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList
{
protected:
	Node* head;
	Node* tail;
public:
	LinkedList();
	virtual bool isEmpty() = 0;
	virtual void CreateNode(int value) = 0;
	virtual void display() = 0;
	virtual void displayReverse() = 0;
};

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}