//#include <iostream>
//using namespace std;
//
//int power(double x, int n) 
//{
//    // Base case: anything raised to power 0 is 1
//    if (n == 0)
//    {
//        return 1;
//    }
//    if (n < 0)
//    {
//        return 1 / power(x, n--); // Handle negative exponent
//    }
//    return x * power(x, n - 1); // Recursive call
//}
//
//int main()
//{
//    int x;
//    int n;
//
//    cout << "Enter base (x): ";
//    cin >> x;
//    cout << "Enter exponent (n): ";
//    cin >> n;
//
//    cout << x << "^" << n << " = " << power(x, n) << endl;
//
//    return 0;
//}