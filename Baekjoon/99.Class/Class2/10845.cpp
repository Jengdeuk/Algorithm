#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<int> MyQueue;

void Command()
{
	string First;
	getline(cin, First);

	string Second;
	int FindIndex = First.find(' ');
	if (FindIndex != string::npos)
	{
		Second = First.substr(FindIndex + 1, First.size());
		First = First.substr(0, FindIndex);
	}

	if (First.compare("push") == 0)
	{
		MyQueue.push(stoi(Second));
	}
	else if (First.compare("pop") == 0)
	{
		if (MyQueue.empty())
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << MyQueue.front() << '\n';
			MyQueue.pop();
		}
	}
	else if (First.compare("size") == 0)
	{
		cout << MyQueue.size() << '\n';
	}
	else if (First.compare("empty") == 0)
	{
		if (MyQueue.empty())
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	else if (First.compare("front") == 0)
	{
		if (MyQueue.empty())
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << MyQueue.front() << '\n';
		}
	}
	else if (First.compare("back") == 0)
	{
		if (MyQueue.empty())
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << MyQueue.back() << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; ++i)
	{
		Command();
	}
}