#include <iostream>
using namespace std;

int Minimum(int arr[],int size)
{
	// Base Case
	if (size == 1)
	{
		return arr[0];
	}
	return arr[size - 1] + Minimum(arr, size - 1);
}

int main()
{
	const int size = 5;
	int arr[size] = { 10,20,30,40,50 };
	int result = Minimum(arr,size);
	cout << "Result: " << result << "\n";

	return 0;
}