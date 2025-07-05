#include <iostream>
#include "Node.h"
using namespace std;

class Tree
{
protected:
    Node* root;
public:
    Tree();
    virtual void insert(int) = 0;
    virtual bool search(int) = 0;
    virtual void PreOrder() = 0;   // Helper
    virtual void PreOrder(Node* root) = 0;
    virtual void PostOrder() = 0;  // Helper
    virtual void PostOrder(Node* root) = 0;
    virtual void InOrder() = 0;   // Helper
    virtual void InOrder(Node* root) = 0;

    virtual void printParent(int value) = 0;

    virtual void LeafNodes() = 0;
    virtual void LeafNodes(Node* node) = 0;

    virtual int Predeccessor(int) = 0;
    virtual int Successor(int value) = 0;

    virtual bool deleteNode(int value) = 0;
};

Tree::Tree()
{
    root = nullptr;
}