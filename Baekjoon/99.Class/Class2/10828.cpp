#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CustomStack
{
private:
	vector<int> Array;

public:
	void Push(int Number) { Array.emplace_back(Number); }
	void Pop()
	{ 
		if (Array.empty())
		{
			cout << -1 << '\n';
			return;
		}

		cout << Array.back() << '\n';
		Array.pop_back();
	}
	void Size() { cout << Array.size() << '\n'; }
	void Empty()
	{
		if (Array.empty())
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	void Top()
	{
		if (Array.empty())
		{
			cout << -1 << '\n';
			return;
		}

		cout << Array.back() << '\n';
	}
};

CustomStack StackInstance;

void Command()
{
	string First;
	getline(cin, First);

	string Second;
	int Index = First.find(' ');
	if (Index != string::npos)
	{
		Second = First.substr(Index + 1, First.length() - Index);
		First = First.substr(0, Index);
	}

	if (First.compare("push") == 0)
	{
		StackInstance.Push(stoi(Second));
	}
	else if (First.compare("pop") == 0)
	{
		StackInstance.Pop();
	}
	else if (First.compare("size") == 0)
	{
		StackInstance.Size();
	}
	else if (First.compare("empty") == 0)
	{
		StackInstance.Empty();
	}
	else if (First.compare("top") == 0)
	{
		StackInstance.Top();
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