#include <iostream>
#include "BST.h"  
using namespace std;

int main()
{
    BST tree;

    tree.insert(5, "Stanford University");
    tree.insert(3, "Harvard University");
    tree.insert(7, "MIT");
    tree.insert(2, "Oxford University");
    tree.insert(4, "Cambridge University");
    tree.insert(6, "Caltech");
    tree.insert(8, "Princeton University");
    

    cout << "Universities in descending order of ranking (highest rank on top):\n";
    tree.InOrder2();  
    cout << endl;

    string searchName = "Harvard University";
    if (tree.search(searchName))
    {
        cout << searchName << " found in the tree.\n";
    }
    else
    {
        cout << searchName << " not found in the tree.\n";
    }

    string deleteName = "MIT";
    tree.deleteNode(deleteName);

    cout << "\nAfter deleting: " << deleteName << endl;
    cout << "Universities in descending order of ranking:\n";
    tree.InOrder2();  
    cout << endl;

    cout << "\nLeaf nodes in the tree:\n";
    tree.LeafNodes();
    cout << endl;

    tree.destroyTree();

    return 0;
}
