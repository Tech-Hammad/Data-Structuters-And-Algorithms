#include <iostream>
#include "Tree.h"

class BST :public Tree
{
public:
    void insert(int, string);
    bool search(string);
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

    void printParent(string);

    void destroyTree();           // Helper
    void destroyTree(Node* node);

    void LeafNodes();
    void LeafNodes(Node* node);

    void deleteNode(string);
};

void BST::insert(int rank,string n)
{
    Node* nn = new Node;
    nn->Ranking = rank;
    nn->name = n;
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
            // Greater
            if (rank > t->Ranking) 
            {
                if (t->rightChild == nullptr)
                {

                    t->rightChild = nn;
                    break;
                }

                else
                {
                    t = t->rightChild;
                }
            }

            else //smaller or equal (left case)
            {
                if (t->leftChild == nullptr)
                {
                    t->leftChild = nn;
                    break;
                }

                else
                {
                    t = t->leftChild;
                }
            }
        }
    }
}

bool BST::search(string n)
{
    Node* temp = root;

    while (temp != nullptr)
    {
        if (n == temp->name)
        {
            return true;
        }
        else if (n < temp->name)
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

    cout << root->name << " --- Ranking: " << root->Ranking << "\n";     // Node
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
    cout << root->name << " --- Ranking: " << root->Ranking << "\n";;      // NODE
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
    cout << root->name << " --- Ranking: " << root->Ranking << "\n";     // NODE
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

    cout << root->name << " --- Ranking: " << root->Ranking << "\n";      // Node
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
    cout << root->name << " --- Ranking: " << root->Ranking << "\n";     // NODE
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
    cout << root->name << " --- Ranking: " << root->Ranking << "\n";    // NODE
    InOrder2(root->leftChild);    // LEFT
}


void BST::printParent(string n)
{
    if (root == nullptr)
    {
        cout << "Tree is empty.\n";
        return;
    }

    if (root->name == n)
    {
        cout << "Node " << n << " is the root and has no parent.\n";
        return;
    }

    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr)
    {
        if (n == current->name)
        {
            if (parent != nullptr)
            {
                cout << "Parent of " << n << " is: " << parent->name << endl;
            }
            else
            {
                cout << "No parent found.\n";
            }
            return;
        }
        else if (n < current->name)
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

    cout << "Node with value " << n << " not found in the tree.\n";
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
        cout << "University: " << node->name << " ---- Ranking: " << node->Ranking << "\n";
        return;
    }

    LeafNodes(node->leftChild);
    LeafNodes(node->rightChild);
}


void BST::deleteNode(string n)
{
    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr && current->name != n)
    {
        if (n < current->name)
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
        cout << "Value not FOund in Tree.\n";
        return;
    }


    if (current->leftChild != NULL && current->rightChild)
    {
        Node* successorParent = current;
        Node* successor = current->rightChild;

        while (successor->leftChild != NULL)
        {
            successorParent = successor;
            successor = successor->leftChild;
        }

        // Copy successor's data to current node
        current->name = successor->name;
        current->Ranking = successor->Ranking;

        // Now delete successor node instead
        current = successor;
        parent = successorParent;
    }
    // Now handle case where current has at most one child
    Node* child = nullptr;
    if (current->leftChild != nullptr)
    {
        child = current->leftChild;
    }
    else if (current->rightChild != nullptr)
    {
        child = current->rightChild;
    }

    // If deleting root node
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
    cout << "Deleted node with Name " << n << endl;
}