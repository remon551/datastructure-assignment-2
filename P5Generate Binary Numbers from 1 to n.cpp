#include<bits/stdc++.h>
#include"qeueu.cpp"
using namespace std;

void BinaryGenerator()
{
	Queue<char> q;
	string str = "";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int value = i;
		while (value != 0)
		{
			q.enqueue((value % 2) + 48);
			value /= 2;
		}
		while (!q.isEmpty())
		{
			str += q.dequeue();
		}
		reverse(str.begin(), str.end());
		cout << str << ((i < n) ? " " : "");
		str = "";
		q.clear();
	}
	cout << endl;
}


int main()
{
	BinaryGenerator();
}
