#include "Tree.h"

int BST::height()
{
    return height(root);
}

int BST::height(Node* root)
{
    if (root == nullptr)
    {
        return -1;
    }
    else 
    {
        int leftHeight = height(root->leftChild);
        int rightHeight = height(root->rightChild);
        
        return 1 + max(leftHeight, rightHeight);
    }
}
