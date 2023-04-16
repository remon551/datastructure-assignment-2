#include <bits/stdc++.h>
#include"stack.cpp"

using namespace std;

int LongestValidParentheses()
{
	Stack<char> s;
	int counter = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else
		{
			if (!s.isEmpty())
			{
				s.pop();
				counter += 2;
			}
		}
	}
	return counter;
}

int main()
{
	cout << LongestValidParentheses() << endl;
}


