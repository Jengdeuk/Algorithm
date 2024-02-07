#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> MyDeque;

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

	if (First.compare("push_back") == 0)
	{
		MyDeque.push_back(stoi(Second));
	}
	else if (First.compare("push_front") == 0)
	{
		MyDeque.push_front(stoi(Second));
	}
	else if (First.compare("pop_front") == 0)
	{
		if (MyDeque.empty())
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << MyDeque.front() << '\n';
			MyDeque.pop_front();
		}
	}
	else if (First.compare("pop_back") == 0)
	{
		if (MyDeque.empty())
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << MyDeque.back() << '\n';
			MyDeque.pop_back();
		}
	}
	else if (First.compare("size") == 0)
	{
		cout << MyDeque.size() << '\n';
	}
	else if (First.compare("empty") == 0)
	{
		if (MyDeque.empty())
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
		if (MyDeque.empty())
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << MyDeque.front() << '\n';
		}
	}
	else if (First.compare("back") == 0)
	{
		if (MyDeque.empty())
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << MyDeque.back() << '\n';
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