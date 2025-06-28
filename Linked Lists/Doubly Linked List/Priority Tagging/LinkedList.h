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
	virtual void insertAtHead(Student) = 0;
	virtual void insertAtTail(Student) = 0;
	virtual void displayFromHead() = 0;
	virtual void displayFromTail() = 0;
	virtual Student deleteFromTail() = 0;
	virtual Student deleteFromHead() = 0;
	virtual bool deleteValue(Student) = 0;
	virtual bool search(Student value) = 0;
	virtual Node* getHead() = 0;
	virtual Node* getTail() = 0;
};

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}