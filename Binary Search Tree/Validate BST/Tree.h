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
    virtual void PreOrder() = 0;   // Helper
    virtual void PreOrder(Node* root) = 0;
    virtual void PostOrder() = 0;  // Helper
    virtual void PostOrder(Node* root) = 0;
    virtual void InOrder() = 0;   // Helper
    virtual void InOrder(Node* root) = 0;

    virtual int findMax() = 0;
    virtual int findMin() = 0;

    virtual bool isBST() = 0;
    virtual bool isBST(Node* root, int, int) = 0;
};

Tree::Tree()
{
    root = nullptr;
}