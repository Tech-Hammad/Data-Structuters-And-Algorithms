#include <iostream>
using namespace std;

int findLargest(int arr[], int size, int index = 0, int maxVal = -1)
{
	if (index == size)
	{
		return maxVal;
	}
	if (arr[index] > maxVal)
	{
		maxVal = arr[index];
	}
	return findLargest(arr, size, index + 1, maxVal);
}

bool isSubsetSum(int arr[], int size, int index, int target)
{
	if (target == 0)
	{
		return true;
	}
	if (index == size)
	{
		return false;
	}
	if (arr[index] > target)
	{
		return isSubsetSum(arr, size, index + 1, target);
	}
	return isSubsetSum(arr, size, index + 1, target - arr[index]) ||
		isSubsetSum(arr, size, index + 1, target);
}

void removeNumber(int original[], int size, int numberToRemove, int newArr[], int& newSize)
{
	if (size == 0)
	{
		newSize = 0;
		return;
	}
	if (original[0] != numberToRemove)
	{
		newArr[0] = original[0];
		int tempSize;
		removeNumber(original + 1, size - 1, numberToRemove, newArr + 1, tempSize);
		newSize = tempSize + 1;
	}
	else
	{
		removeNumber(original + 1, size - 1, numberToRemove, newArr, newSize);
	}
}

int findMagicNumber(int arr[], int size)
{
	if (size == 0)
	{
		return -1;
	}
	int largest = findLargest(arr, size);

	int* reducedArr = new int[size - 1];
	int newSize = 0;
	removeNumber(arr, size, largest, reducedArr, newSize);

	if (isSubsetSum(reducedArr, newSize, 0, largest))
	{
		delete[] reducedArr;
		return largest;
	}

	int result = findMagicNumber(reducedArr, newSize);
	delete[] reducedArr;
	return result;
}

int main()
{
	int arr[] = { 2, 3, 5, 8, 13 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int magicNumber = findMagicNumber(arr, size);
	if (magicNumber != -1)
	{
		cout << "Magic number is: " << magicNumber << endl;
	}
	else
	{
		cout << "No magic number found.\n";
	}

	return 0;
}
