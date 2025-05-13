#include<iostream>
#include<string>
#include"myStack.h"
using namespace std;

int main()
{
	myStack<char>obj(5);
	string expression;
	cout << "Enter the String Containing Parentheses: ";
	getline(cin, expression);

	if (obj.isValidParentheses(expression))
	{
		cout << "The Parentheses Are Valid.\n";
	}
	else
	{
		cout << "The Parentheses Are Not Valid.\n";
	}
	return 0;
}