#include <iostream>
#include "Tree.h"

class BST:public Tree
{
public:
    void insert(int);
    bool search(int);
    void PreOrder();   // Helper
    void PreOrder(Node* root);
    void PostOrder();  // Helper
    void PostOrder(Node* root);
    void InOrder();    // Helper
    void InOrder(Node* root);

    void PreOrder2();   // Helper
    void PreOrder2(Node* root);
    void PostOrder2();  // Helper
    void PostOrder2(Node* root);
    void InOrder2();    // Helper
    void InOrder2(Node* root);

    void printParent(int value);

    void destroyTree();           // Helper
    void destroyTree(Node* node);

    void LeafNodes();
    void LeafNodes(Node* node);

    void rotateRight(Node* x);
    void rotateLeft(Node* y);
    void fixInsert(Node* node);
};

void BST::insert(int value)
{
    Node* nn = new Node;
    nn->data = value;
    nn->left = nullptr;
    nn->right = nullptr;
    nn->colour = 'R';

    if (root == nullptr)
    {
        nn->colour = 'B';
        root = nn;
        return;
    }

    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (value < parent->data)
    {
        parent->left = nn;
    }
    else
    {
        parent->right = nn;
    }
    fixInsert(nn);
}


bool BST::search(int value)
{
    Node* temp = root;

    while (temp != nullptr)
    {
        if (value == temp->data)
        {
            return true;
        }
        else if (value < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
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

    cout << root->data << " (" << root->colour << ") ";     // Node with COlour
    PreOrder(root->left);     // Left
    PreOrder(root->right);    // Right
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

    PostOrder(root->left);     // LEFT
    PostOrder(root->right);    // RIGHT
    cout << root->data << " (" << root->colour << ") ";      // NODE
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

    InOrder(root->left);       // LEFT
    cout << root->data << " (" << root->colour << ") ";     // NODE
    InOrder(root->right);      // RIGHT
}


void BST::PreOrder2()
{
    PreOrder2(root);
}

void BST::PreOrder2(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // Reccursive Calls until root is null

    cout << root->data << " (" << root->colour << ") ";      // Node
    PreOrder2(root->right);    // Right
    PreOrder2(root->left);     // Left
}

void BST::PostOrder2()
{
    PostOrder2(root);
}

void BST::PostOrder2(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // Reccursive Calls until root is null

    PostOrder2(root->right);   // RIGHT
    PostOrder2(root->left);    // LEFT
    cout << root->data << " (" << root->colour << ") ";     // NODE
}

void BST::InOrder2()
{
    InOrder2(root);
}

void BST::InOrder2(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // Reccursive Calls until root is null
    InOrder2(root->right);   // RIGHT
    cout << root->data << " (" << root->colour << ") ";    // NODE
    InOrder2(root->left);    // LEFT
}


void BST::printParent(int value)
{
    if (root == nullptr)
    {
        cout << "Tree is empty.\n";
        return;
    }

    if (root->data == value)
    {
        cout << "Node " << value << " is the root and has no parent.\n";
        return;
    }

    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr)
    {
        if (value == current->data)
        {
            if (parent != nullptr)
                cout << "Parent of " << value << " is: " << parent->data << endl;
            else
                cout << "No parent found.\n";
            return;
        }
        else if (value < current->data)
        {
            parent = current;
            current = current->left;
        }
        else
        {
            parent = current;
            current = current->right;
        }
    }

    cout << "Node with value " << value << " not found in the tree.\n";
}

void BST::destroyTree()
{
    destroyTree(root);
    root = nullptr;
    cout << "Tree Destroyed.\n";
}

void BST::destroyTree(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

void BST::LeafNodes()
{
    if (root == nullptr)
    {
        cout << "Tree is Empty.\n";
        return;
    }
    LeafNodes(root);
}

void BST::LeafNodes(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        cout << node->data << " (" << node->colour << ") ";
        return;
    }

    LeafNodes(node->left);
    LeafNodes(node->right);
}

void BST::rotateLeft(Node* x)
{
    if (x == nullptr || x->right == nullptr)
    {
        return;
    }

    Node* y = x->right;
    x->right = y->left;
    y->left = x;

    if (x == root)
    {
        root = y;
    }
    else
    {
        Node* parent = root;
        Node* prev = nullptr;
        while (parent != nullptr && parent != x)
        {
            prev = parent;
            if (x->data < parent->data)
            {
                parent = parent->left;
            }
            else
            {
                parent = parent->right;
            }
        }

        if (prev != nullptr)
        {
            if (x == prev->left)
            {
                prev->left = y;
            }
            else
            {
                prev->right = y;
            }
        }
    }
}

void BST::rotateRight(Node* x)
{
    if (x == nullptr || x->left == nullptr)
    {
        return;
    }
    Node* y = x->left;
    x->left = y->right;
    y->right = x;

    if (x == root)
    {
        root = y;
    }
    else
    {
        Node* parent = root;
        Node* prev = nullptr;
        while (parent != nullptr && parent != x)
        {
            prev = parent;
            if (x->data < parent->data)
            {
                parent = parent->left;
            }
            else
            {
                parent = parent->right;
            }
        }

        if (prev != nullptr)
        {
            if (x == prev->left)
            {
                prev->left = y;
            }
            else
            {
                prev->right = y;
            }
        }
    }
}

void BST::fixInsert(Node* node)
{
    while (node != root)
    {
        Node* parent = nullptr;
        Node* grandparent = nullptr;
        Node* uncle = nullptr;
        Node* current = root;

        while (current != node)
        {
            grandparent = parent;
            parent = current;

            if (node->data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        if (parent == nullptr || parent->colour == 'B')
        {
            break;
        }
        if (grandparent != nullptr)
        {
            if (parent == grandparent->left)
            {
                uncle = grandparent->right;
            }
            else
            {
                uncle = grandparent->left;
            }
        }

        // Case 1
        if (uncle != nullptr && uncle->colour == 'R')
        {
            parent->colour = 'B';
            uncle->colour = 'B';
            grandparent->colour = 'R';
            node = grandparent;
        }
        else
        {
            // Case 2 & 3: Uncle is black or null
            if (grandparent != nullptr)
            {
                // Left-Right Case
                if (parent == grandparent->left && node == parent->right)
                {
                    rotateLeft(parent);
                    node = parent;
                }
                // Right-Left Case
                else if (parent == grandparent->right && node == parent->left)
                {
                    rotateRight(parent);
                    node = parent;
                }

                // Left-Left Case
                if (node == parent->left && parent == grandparent->left)
                {
                    rotateRight(grandparent);
                    parent->colour = 'B';
                    grandparent->colour = 'R';
                }
                // Right-Right Case
                else if (node == parent->right && parent == grandparent->right)
                {
                    rotateLeft(grandparent);
                    parent->colour = 'B';
                    grandparent->colour = 'R';
                }
                break;
            }
        }
    }
    root->colour = 'B';
}
