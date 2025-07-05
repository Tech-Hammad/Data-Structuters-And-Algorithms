#include "Tree.h"

class BST :public Tree
{
public:
    int depth(int target);
    int depth(Node* node, int target, int currentDepth);
};


int BST::depth(int target)
{
    return depth(root, target, 0); // start from root depth 0
}

int BST::depth(Node* node, int target, int currentDepth)
{
    if (node == nullptr)
    {
        return -1; // target not found
    }
    if (node->data == target)
    {
        return currentDepth; // found target node
    }
    if (target < node->data)
    {
        return depth(node->leftChild, target, currentDepth + 1);
    }
    else
    {
        return depth(node->rightChild, target, currentDepth + 1);
    }
}
