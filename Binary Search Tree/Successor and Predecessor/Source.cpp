#include <iostream>
#include "BST.h"

int main()
{
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(55);
    bst.insert(65);

    cout << "Pre Order Traversal\n";
    bst.PreOrder();

    cout << "\n\nPost Order Traversal\n";
    bst.PostOrder();

    cout << "\n\nIn Order Traversal\n";
    bst.InOrder();

    cout << "\n\nInorder Successor of Value 60 is : " << bst.Successor(60) << "\n";
    cout << "\nInorder PreDeccessor of Value 60 is : " << bst.Predeccessor(60) << "\n";

    return 0;
}