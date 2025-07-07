#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    BST bst;
   
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    if (bst.isBST())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

	return 0;
}