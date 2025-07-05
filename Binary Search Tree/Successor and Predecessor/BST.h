#include <iostream>
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

    void printParent(int value);

    void LeafNodes();
    void LeafNodes(Node* node);

    int Successor(int value);
    int Predeccessor(int value);

    bool deleteNode(int value);
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

int BST::Successor(int value)
{
    Node* current = root;
    int answer = 0; 

    while (current != nullptr)
    {
        if (current->data > value)
        {
            answer = current->data;
            current = current->leftChild; // try to find a smaller successor
        }
        else
        {
            current = current->rightChild;
        }
    }
    return answer;
}

int BST::Predeccessor(int value)
{
    Node* current = root;
    int answer = 0;

    while (current != nullptr)
    {
        if (current->data < value)
        {
            answer = current->data;
            current = current->rightChild;
        }
        else
        {
            current = current->leftChild;
        }
    }
    return answer;
}

bool BST::deleteNode(int value)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (root->leftChild == nullptr && root->rightChild == nullptr) //single node case
    {
        if (root->data == value)
        {
            delete root;
            root = nullptr;
            return true;
        }
        return false;
    }

    // when root has a single child, YOU (means YOU means YOU means NOT me, but YOU means STUDENT) has to do it
    // single child can be RIGHT or LEFT

    else
    {
        Node* p = root;
        Node* c = root;

        while (1)
        {
            if (c->data == value)
            {
                break;
            }
            if (value < c->data) // left
            {
                p = c;
                c = c->leftChild;
            }

            else // right
            {
                p = c;
                c = c->rightChild;
            }

            if (c == nullptr)
            {
                return false;

            }
        }

        // 2 children case
        if (c->rightChild != nullptr && c->leftChild != nullptr)
        {
            Node* t = c;
            p = t; //p = t->rightChild == not good, because...
            c = t->rightChild;
            while (1)
            {
                if (c->leftChild == nullptr)
                {
                    break;
                }
                p = c;
                c = c->leftChild;
            }
            t->data = c->data;
            value = c->data;
        }

        if (c->leftChild == nullptr && c->rightChild == nullptr) //leaf node
        {
            if (c->data < p->data) // left child of your parent
            {
                delete c;
                c = nullptr;
                p->leftChild = nullptr;

            }
            else    // right child of your parent
            {
                delete c;
                c = nullptr;
                p->rightChild = nullptr;
            }
            return true;
        }

        else if (c->rightChild == nullptr && c->leftChild != nullptr) //single child case 1
        {
            if (c->data < p->data) // left child of your parent
            {
                p->leftChild = c->leftChild;
                delete c;
                c = nullptr;
            }
            else    // right child of your parent
            {
                p->rightChild = c->leftChild;
                delete c;
                c = nullptr;
            }
            return true;
        }

        else if (c->rightChild != nullptr && c->leftChild == nullptr) //single child case 2
        {
            if (c->data < p->data) // left child of your parent
            {
                p->leftChild = c->rightChild;
                delete c;
                c = nullptr;
            }
            else    // right child of your parent
            {
                p->rightChild = c->rightChild;
                delete c;
                c = nullptr;
            }
            return true;
        }
    }
}