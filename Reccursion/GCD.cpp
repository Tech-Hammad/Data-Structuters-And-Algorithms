#include <iostream>
using namespace std;

int gcd(int a, int b) 
{
    if (b == 0)
    {
        return a;            // base case
    }
    else
    {
        return gcd(b, a % b); 
    }
}

int main()
{
    int num1, num2;
    cout << "Enter two positive integers: ";
    cin >> num1 >> num2;
    int result = gcd(num1, num2);

    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
