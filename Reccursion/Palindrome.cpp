#include <iostream>
using namespace std;

bool isPalindrome(const char str[], int start, int end) 
{
    if (start >= end)
    {
        return true; // Base case: when indices cross, it's a palindrome
    }
    if (str[start] != str[end])
    {
        return false; // If characters don't match, it's not a palindrome
    }
    return isPalindrome(str, start + 1, end - 1); // Recursive call moving inward
}

int main() {
    char str[100]; 

    cout << "Enter a string: ";
    cin >> str;

    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }

    if (isPalindrome(str, 0, length - 1))
    {
        cout << "The string \"" << str << "\" is a palindrome.\n";
    }
    else
    {
        cout << "The string \"" << str << "\" is NOT a palindrome.\n";
    }
    return 0;
}
