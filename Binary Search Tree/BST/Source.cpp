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
    
    if (bst.search(30))
    {
        cout << "Found\n";
    }
    else
    {
        cout << "Not Found\n";
    }

    cout << "Pre Order Traversal\n";
    bst.PreOrder();

    cout << "\n\nPost Order Traversal\n";
    bst.PostOrder();

    cout << "\n\nIn Order Traversal\n";
    bst.InOrder();

    cout << "\n\nPre Order-2 Traversal\n";
    bst.PreOrder2();

    cout << "\n\nPost Order-2 Traversal\n";
    bst.PostOrder2();

    cout << "\n\nIn Order-2 Traversal\n";
    bst.InOrder2();
    
    cout << "\n\n";

    bst.printParent(30);
    bst.printParent(80);
    bst.printParent(60);

    // bst.destroyTree();

    bst.LeafNodes();

    cout << "\nMinimum Value in Tree: " << bst.findMin();
    cout << "\nMaximum Value in Tree: " << bst.findMax();
    cout << "\nFloor of Value: " << bst.findFloor(58);
    cout << "\nCeil of Value: " << bst.findCeil(75);
    
    return 0;
}
