#include <iostream>
using namespace std;

int findMinRec(int arr[], int n) 
{
    if (n == 1)
    {
        return arr[0];
    }

    int restMin = findMinRec(arr, n - 1);
	
    if (arr[n - 1] < restMin) 
    {
        return arr[n - 1];
    }
    else
    {
        return restMin;
    }
}

int main() 
{
    int arr[] = {5, 2, 8, 1, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int minVal = findMinRec(arr, size);
    cout << "Minimum value in array: " << minVal << endl;

    return 0;
}
