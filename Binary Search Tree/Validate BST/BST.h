#include <iostream>
#include <queue>
#include "Tree.h"

class BST :public Tree
{
public:
    void insert(int);
    void PreOrder();   // Helper
    void PreOrder(Node* root);
    void PostOrder();  // Helper
    void PostOrder(Node* root);
    void InOrder();    // Helper
    void InOrder(Node* root);

    int findMax();
    int findMin();

    bool isBST();
    bool isBST(Node* root, int, int);
};

void BST::insert(int value)
{
    Node* nn = new Node;
    nn->data = value;
    nn->leftChild = nullptr;
    nn->rightChild = nullptr;

    if (root == nullptr)
    {
        root = nn;
    }
    else
    {
        Node* t = root;

        while (1)
        {
            if (value < t->data) //smaller
            {
                if (t->leftChild == nullptr)
                {

                    t->leftChild = nn;
                    break;
                }

                else
                    t = t->leftChild;
            }

            else //greater or equal (riht case)
            {
                if (t->rightChild == nullptr)
                {
                    t->rightChild = nn;
                    break;
                }

                else
                    t = t->rightChild;
            }
        }
    }
}

void BST::PreOrder()
{
    PreOrder(root);
}

void BST::PreOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // Reccursive Calls until root is null

    cout << root->data << " ";     // Node
    PreOrder(root->leftChild);     // Left
    PreOrder(root->rightChild);    // Right
}

void BST::PostOrder()
{
    PostOrder(root);
}

void BST::PostOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // Reccursive Calls until root is null

    PostOrder(root->leftChild);     // LEFT
    PostOrder(root->rightChild);    // RIGHT
    cout << root->data << " ";      // NODE
}

void BST::InOrder()
{
    InOrder(root);
}

void BST::InOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // Reccursive Calls until root is null

    InOrder(root->leftChild);       // LEFT
    cout << root->data << "  ";     // NODE
    InOrder(root->rightChild);      // RIGHT
}

int BST::findMin()
{
    if (root == nullptr)
    {
        cout << "Tree is Empty.\n";
    }
    Node* current = root;

    while (current->leftChild != nullptr)
    {
        current = current->leftChild;
    }
    return current->data;
}

int BST::findMax()
{
    if (root == nullptr)
    {
        cout << "Tree is Empty.\n";
    }
    Node* current = root;

    while (current->rightChild != nullptr)
    {
        current = current->rightChild;
    }
    return current->data;
}


bool BST::isBST()
{
    return isBST(root, INT_MIN, INT_MAX);
}

bool BST::isBST(Node* root, int min, int max)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->data <= min || root->data >= max)
    {
        return false;
    }

    // Left subtree must have values < node->data
    // Right subtree must have values > node->data
    return isBST(root->leftChild, min, root->data)
        && isBST(root->rightChild, root->data, max);
}