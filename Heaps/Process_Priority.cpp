#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int* arr;
    int maxSize;

    MaxHeap(int size)
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
        while (i > 1 && arr[i] > arr[i / 2])
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
        while (i > 1 && arr[i] > arr[i / 2])
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
            int largest = i;

            if (left <= arr[0] && arr[left] > arr[largest])
            {
                largest = left;
            }
            if (right <= arr[0] && arr[right] > arr[largest])
            {
                largest = right;
            }
            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
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

            if (left <= arr[0] && arr[i] < arr[left])
            {
                return false;
            }
            if (right <= arr[0] && arr[i] < arr[right])
            {
                return false;
            }
        }
        return true;
    }

    void Process()
    {
        if (arr[0] == 0)
        {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "Processing Package with Priority: " << arr[1] << "\n";

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
};

int main()
{
    MaxHeap h(10);
    
    h.insert(4);
    h.insert(10);
    h.insert(3);
    h.insert(5);
    h.insert(1);

    h.Process();
    h.Process();
    
    return 0;
}
