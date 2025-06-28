#pragma once
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
	virtual void insertAtHead(int) = 0;
	virtual void insertAtTail(int) = 0;
	virtual void displayFromHead() = 0;
	virtual void displayFromTail() = 0;
	virtual Node* removeFromFront() = 0;
	virtual void mergeList(LinkedList& other) = 0;
};

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}