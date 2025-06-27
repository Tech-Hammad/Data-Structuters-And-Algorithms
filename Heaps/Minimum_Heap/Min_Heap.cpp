#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

class MinHeap 
{
public:
    int* arr;
    int maxSize;

    MinHeap(int size) 
    {
        maxSize = size + 1;    // +1 because arr[0] holds size info
        arr = new int[maxSize];
        arr[0] = 0; // Initially heap size is 0
    }

    void insert(int val) 
    {
        if (arr[0] + 1 >= maxSize) 
        {
            cout << "Heap is full!\n";
            return;
        }
        
        arr[0]++;
        int i = arr[0];
        arr[i] = val;

        // Heapify-up
        while (i > 1 && arr[i] < arr[i / 2]) 
        {
            swap(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }

    void deleteValue(int value)
    {
        int i;
        for (i = 1;i <= arr[0];i++)
        {
            if (arr[i] == value)
            {
                break;
            }
        }
        if (i > arr[0]) 
        {
            cout << "Value not found in heap.\n";
            return;
        }

        // Replaced With Last Element
        arr[i] = arr[arr[0]];
        arr[0]--;

        // Try heapify-down first
        heapifyDown(i);

        // If heapify-down didn't move the element up (value was smaller),
        // then try heapify-up
        heapifyUp(i);
    }

    void heapifyUp(int i) 
    {
        while (i > 1 && arr[i] < arr[i / 2])
        {
            swap(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }

    void heapifyDown(int i)
    {
        while (2 * i <= arr[0])
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;

            if (left <= arr[0] && arr[left] < arr[smallest])
            {
                smallest = left;
            }
            if (right <= arr[0] && arr[right] < arr[smallest])
            {
                smallest = right;
            }
            if (smallest != i)
            {
                swap(arr[i], arr[smallest]);
                i = smallest;
            }
            else
            {
                break;
            }
        }
    }

    void printHeap()
    {
        cout << "Heap: ";
        for (int i = 1; i <= arr[0]; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    bool isHeap()
    {
        for (int i = 1; i <= arr[0]; i++)
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left <= arr[0] && arr[i] > arr[left])
            {
                return false;
            }
            if (right <= arr[0] && arr[i] > arr[right])
            {
                return false;
            }
        }
        return true;
    }

    void deleteMin() 
    {
        if (arr[0] == 0)
        {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "Minimum (Root) Element Deleted: " << arr[1] << "\n";

        // Replace root with last element
        arr[1] = arr[arr[0]];
        arr[0]--;

        // Restoring heap property
        heapifyDown(1);
    }

    int getCurrentSize()
    {
        return arr[0];
    }

    void buildHeap()
    {
        for (int i = arr[0] / 2; i >= 1; i--)
        {
            heapifyDown(i);
        }
    }

};

int main() 
{
    MinHeap h(10); 
    int choice, value;
   
    do
    {
        cout << "\n==== Min Heap Menu ====\n";
        cout << "1) Insert Value.\n";
        cout << "2) Delete Value.\n";
        cout << "3) Display Heap.\n";
        cout << "4) Check isHeap.\n";
        cout << "5) Delete Minimum.\n";
        cout << "6) Heap Sort.\n";
        cout << "7) Generate Rando Heap.\n";
        cout << "0) Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
        {
            cout << "Enter Value: ";
            cin >> value;
            h.insert(value);
            break;
        }
        case 2:
        {
            cout << "Enter Delete Value: ";
            cin >> value;
            h.deleteValue(value);
            break;
        }
        case 3:
        {
            h.printHeap();
            break;
        }
        case 4:
        {
            if (h.isHeap())
            {
                cout << "The Heap is Valid.\n";
            }
            else
            {
                cout << "The Heap is Invalid.\n";
            }
            break;
        }
        case 5:
        {
            h.deleteMin();
            break;
        }
        case 6:
        {
            if (h.isHeap() == false)
            {
                cout << "Heap is empty..\n";
                break;
            }

            int sizeBackup = h.getCurrentSize();
            int* Backup = new int[sizeBackup + 1];

            for (int i = 0;i < sizeBackup;i++)
            {
                Backup[i] = h.arr[i];
            }
            stack<int>sortedStack;

            while (h.arr[0] > 0)
            {
                sortedStack.push(h.arr[1]);
                h.deleteMin();
            }

            cout << "Heap Sort (Ascending)\n";
            while (!sortedStack.empty())
            {
                cout << sortedStack.top() << " ";
                sortedStack.pop();
            }

            // Restore original heap
            for (int i = 0; i <= sizeBackup; i++)
            {
                h.arr[i] = Backup[i];
            }
            delete[] Backup;

            break;
        }
        case 7:
        {
            int n;
            cout << "How many random values to generate (max " << h.maxSize - 1 << ")? ";
            cin >> n;

            h.arr[0] = n;
            for (int i = 1;i <= n;i++)
            {
                h.arr[i] = rand() % 100;
            }

            cout << "Array before buildHeap():\n";
            h.printHeap();

            h.buildHeap();

            cout << "Heap after applying buildHeap():\n";
            h.printHeap();
        }

        }
    } while (choice != 0);

    return 0;
}
