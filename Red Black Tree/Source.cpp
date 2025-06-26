#include <iostream>
#include <fstream>
#include "BST.h"

int main()
{

    ifstream fin("input.txt");
    int choice = 0, value;
    BST rbt;

    do
    {
        cout << "\n===== Menu =====\n";
        cout << "Press 1 to insert values in the tree(one by one)\n";
        cout << "Press 2 for searching a value from the tree\n";
        cout << "Press 3 for pre - order traversal NLR\n";
        cout << "Press 4 for in - order traversal LNR\n";
        cout << "Press 5 for post - order traversal LRN\n";
        cout << "Press 6 for pre - order traversal 2 NRL\n";
        cout << "Press 7 for in - order traversal 2 RNL\n";
        cout << "Press 8 for post - order traversal 2 RLN\n";
        cout << "Press 9 for displaying parent of a node present in Tree\n";
        cout << "Press 10 to read integer values from the file input.txt.\n";
        cout << "Press 11 to destroy the complete tree\n";
        cout << "Press 12 to EXIT\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            {
                cout << "Enter the Value: ";
                cin >> value;
                rbt.insert(value);
                break;
            }
        case 2:
        {
            cout << "Enter the Searching Value: ";
            cin >> value;
            if (rbt.search(value))
            {
                cout << "Value Found.\n";
            }
            else
            {
                cout << "Value Not Found.\n";
            }
            break;
        }
        case 3:
        {
            rbt.PreOrder();
            break;
        }
        case 4:
        {
            rbt.InOrder();
            break;
        }
        case 5:
        {
            rbt.PostOrder();
            break;
        }
        case 6:
        {
            rbt.PreOrder2();
            break;
        }
        case 7:
        {
            rbt.PostOrder2();
            break;
        }
        case 8:
        {
            rbt.InOrder2();
            break;
        }
        case 9:
        {
            cout << "Enter the Value: ";
            cin >> value;
            rbt.printParent(value);
            break;
        }
        case 10:
        {
            if (fin)
            {
                while (fin >> value)
                {
                    rbt.insert(value);
                }
            }
            fin.close();
            break;
        }
        case 11:
        {
            rbt.destroyTree();
            break;
        }

        }

    } while (choice != 12);

    return 0;
}