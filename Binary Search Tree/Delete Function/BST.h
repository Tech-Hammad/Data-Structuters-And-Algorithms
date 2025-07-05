#include <iostream>
#include "Tree.h"
using namespace std;

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
