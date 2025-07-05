#include "Tree.h"

int BST::height()
{
    Node* temp = root;

    if (root == nullptr)
    {
        return -1;
    }

    queue<Node*> q;

    q.push(temp);
    int height = -1;

    while (!q.empty())
    {
        int levelSize = q.size();
        height++;

        for (int i = 0;i < levelSize;i++)
        {
            Node* current = q.front();
            q.pop();

            if (current->leftChild)
            {
                q.push(current->leftChild);
            }
            if (current->rightChild)
            {
                q.push(current->rightChild);
            }
        }
    }

    return height;
}
