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

    void deleteNode(int value);
    int findMin();
    int findMax();
    int findFloor(int key);
    int findCeil(int key);
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
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
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

    cout << root->data << " ";      // Node
    PreOrder2(root->rightChild);    // Right
    PreOrder2(root->leftChild);     // Left
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

    PostOrder2(root->rightChild);   // RIGHT
    PostOrder2(root->leftChild);    // LEFT
    cout << root->data << "  ";     // NODE
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
    InOrder2(root->rightChild);   // RIGHT
    cout << root->data << " ";    // NODE
    InOrder2(root->leftChild);    // LEFT
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
            current = current->leftChild;
        }
        else
        {
            parent = current;
            current = current->rightChild;
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

    destroyTree(node->leftChild);
    destroyTree(node->rightChild);
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

    if (node->leftChild == nullptr && node->rightChild == nullptr)
    {
        cout << node->data << " ";
        return;
    }

    LeafNodes(node->leftChild);
    LeafNodes(node->rightChild);
}

void BST::deleteNode(int value)
{
    Node* current = root;
    Node* parent = nullptr;

    if (root == nullptr)
    {
        return;
    }

    // Searching Node
    while (current != nullptr && current->data != value)
    {
        parent = current;

        if (value < current->data)
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }

    if (current == nullptr)
    {
        cout << "Node with value " << value << " not found.\n";
        return;
    }

    if (current->leftChild != nullptr && current->rightChild != nullptr)
    {
        Node* successor = current->rightChild;
        Node* successorParent = current;

        while (successor->leftChild != nullptr)
        {
            successorParent = successor;
            successor = successor->leftChild;
        }

        // Copy successor value to current node
        current->data = successor->data;

        // Now we will delete successor 
        current = successor;
        parent = successorParent;
    }

    Node* child = nullptr;
    
    if (current->leftChild != nullptr)
    {
        child = current->leftChild;
    }
    else if (current->rightChild != nullptr)
    {
        child = current->rightChild;
    }
    else
    {
        child = nullptr;  // leaf node
    }

    if (parent == nullptr)
    {
        root = child;
    }
    else if (parent->leftChild == current)
    {
        parent->leftChild = child;
    }
    else
    {
        parent->rightChild = child;
    }

    delete current;
    cout << "Node with value " << value << " Deleted.\n";
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

int BST::findFloor(int key)
{
    Node* current = root;
    int floor = 0;

    while (current != nullptr)
    {
        if (current->data == key)
        {
            return current->data;
        }
        else if (key > current->data)
        {
            floor = current->data;
            current = current->rightChild;
        }
        else 
        {
            current = current->leftChild;
        }
    }
    return floor;
}

int BST::findCeil(int key)
{
    Node* current = root;
    int Ceil = 0;

    while (current != nullptr)
    {
        if (current->data == key)
        {
            return current->data;
        }
        else if (key < current->data)
        {
            Ceil = current->data;
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }
    return Ceil;
}
