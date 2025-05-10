#include <iostream>
#include <string>
#include "myStack.h"
using namespace std;

int main()
{
	string expression = "* + 2 3 + 2 3";
	myStack<int>st(20);
	cout << "Prefix Expression: " << expression << "\n";
	for (int i = expression.length() - 1;i >= 0;i--)
	{
		char c = expression[i];
		
		if (c == ' ')
		{
			// cout << "Do Nothing.";
		}

		if (isdigit(c))
		{
			// st.Push(c); //it will push ascii value
			st.Push(c - '0');
		}

		else if(st.isOperator(c))
		{
			int op1 = st.Pop();
			int op2 = st.Pop();

			int result = st.applyOperation(c, op1, op2);

			st.Push(result);
		}
	}
	cout << "Final Result: " << st.Pop() << "\n";

	return 0;
}