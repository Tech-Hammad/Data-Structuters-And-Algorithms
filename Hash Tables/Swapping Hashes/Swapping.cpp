#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> sample1, sample2;

    sample1 = { { 2, 2 }, { 3, 4 }, { 4, 6 }, { 5, 8 } };
    sample2 = { { 10, 11 }, { 12, 13 }, { 14, 15 }, { 26, 17 } };

    cout << " Elements of maps before swap \n";
    cout << " Elements of first map are : \n";
    for (auto x : sample1)
    {
        cout << x.first << " : " << x.second << endl;
    }
    cout << " Elements of second map are : \n";
    for (auto x : sample2)
    {
        cout << x.first << " : " << x.second << endl;
    }

    sample1.swap(sample2);

    cout << " Elements of maps after swap \n";
    cout << " Elements of first map are : \n";
    for (auto x : sample1)
    {
        cout << x.first << " : " << x.second << endl;
    }
    cout << " Elements of second map are : \n";
    for (auto x : sample2)
    {
        cout << x.first << " : " << x.second << endl;
    }
        
    return 0;
}
