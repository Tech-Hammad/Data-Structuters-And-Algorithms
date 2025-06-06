#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList
{
protected:
	Node* head;
public:
	LinkedList();
	virtual bool isEmpty() = 0;
	virtual void insertAtHead(int) = 0;
	virtual void insertAtTail(int) = 0;
	virtual int deleteFromHead() = 0;
	virtual int deleteFromTail() = 0;
	virtual bool search(int value) = 0;
	virtual void display() = 0;
	virtual bool deleteValue(int) = 0;
	virtual void insertSorted(int) = 0;
	virtual bool compareLinkedLists(LinkedList& otherList) = 0;
	Node* getHead() 
	{
		return head;
	}
};

LinkedList::LinkedList()
{
	head = nullptr;
}
