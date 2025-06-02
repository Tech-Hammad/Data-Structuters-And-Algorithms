#include <iostream>
using namespace std;

int Sum_Digits(int num)
{
	if (num > 0)
	{
		return Sum_Digits(num / 10) + num % 10;
	}
	if (num == 0)
	{
		return 0;
	}
}

int main()
{
	int number = 2347;
	cout << "The Count of Digits of " << number << " is: " << Sum_Digits(number) << "\n";

	return 0;
}