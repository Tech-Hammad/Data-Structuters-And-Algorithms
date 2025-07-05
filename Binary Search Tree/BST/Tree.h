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
    virtual bool search(int value) = 0;
    virtual void PreOrder() = 0;   // Helper
    virtual void PreOrder(Node* root) = 0;
    virtual void PostOrder() = 0;  // Helper
    virtual void PostOrder(Node* root) = 0;
    virtual void InOrder() = 0;   // Helper
    virtual void InOrder(Node* root) = 0;

    virtual void PreOrder2() = 0;   // Helper
    virtual void PreOrder2(Node* root) = 0;
    virtual void PostOrder2() = 0;  // Helper
    virtual void PostOrder2(Node* root) = 0;
    virtual void InOrder2() = 0;   // Helper
    virtual void InOrder2(Node* root) = 0;

    virtual void printParent(int value) = 0;

    virtual void destroyTree() = 0;           // Helper
    virtual void destroyTree(Node* node) = 0;

    virtual void LeafNodes() = 0;
    virtual void LeafNodes(Node* node) = 0;

    virtual void deleteNode(int value) = 0;
    virtual int findMin() = 0;
    virtual int findMax() = 0;
    virtual int findFloor(int key) = 0;
    virtual int findCeil(int key) = 0;
};

Tree::Tree()
{
    root = nullptr;
}
