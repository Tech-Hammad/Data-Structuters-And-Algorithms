// Sort Stack Using Array

//template <typename T>
//void sortStack(myStack<T>& s,int size)
//{
//    myStack<T> temp(size); 
//
//    while (!s.isEmpty()) 
//    {
//        // Step 1: Pop out the top element
//        T tempValue = s.Pop();
//
//        // Step 2: While temp stack is not empty and top of temp > tempValue
//        while (!temp.isEmpty() && temp.Top() > tempValue)
//        {
//            s.Push(temp.Pop());
//        }
//
//        // Step 3: Push tempValue into temp stack
//        temp.Push(tempValue);
//    }
//
//    while (!temp.isEmpty())
//    {
//        s.Push(temp.Pop());
//    }
//}


#include <iostream>
#include "myStack.h"
using namespace std;

int main() 
{
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    myStack<int> s(size);

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        s.Push(value);
    }

    cout << "\nOriginal Stack:\n";
    s.display();

    // Step 1: Pop all elements into an array
    int* arr = new int[size];
    int index = 0;
    while (!s.isEmpty())
    {
        arr[index++] = s.Pop();
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++) // `size - i - 1` for optimization
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Step 3: Push sorted elements back into the stack
    for (int i = 0; i < size; i++) 
    {
        s.Push(arr[i]);
    }

    cout << "\nSorted Stack (smallest at bottom, largest at top):\n";
    s.display();

    delete[] arr; // free the memory
    return 0;
}
