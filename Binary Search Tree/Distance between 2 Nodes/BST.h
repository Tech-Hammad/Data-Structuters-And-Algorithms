#include <iostream>
#include "Tree.h"

class BST :public Tree
{
public:
    int distance(int, int);
};

int BST::distance(int n1, int n2)
{
    Node* current = root;

    // Find LCA of n1 and n2
    while (current != nullptr)
    {
        if (current->data > n1 && current->data > n2)
        {
            current = current->leftChild;
        }
        else if (current->data < n1 && current->data < n2)
        {
            current = current->rightChild;
        }
        else
        {
            // current->data is the LCA if it is between n1 and n2,
            // or equal to n1 or n2

            // Otherwise -> one is on the left, the other on the right OR
            // current->data == n1 or n2 -> current is the LCA.

            break; // Found LCA
        }
    }

    if (current == nullptr)
    {
        return -1;     // LCA not found, nodes not in tree
    }

    // Find distance from LCA to n1
    int count1 = 0;
    Node* temp = current;
    while (temp != nullptr && temp->data != n1)
    {
        if (n1 < temp->data)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
        count1++;
    }

    if (temp == nullptr)
    {
        return -1; // n1 not found
    }

    // Find distance from LCA to n2
    int count2 = 0;
    temp = current;
    while (temp != nullptr && temp->data != n2)
    {
        if (n2 < temp->data)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
        count2++;
    }

    if (temp == nullptr)
    {
        return -1; // n2 not found
    }

    return count1 + count2;
}
