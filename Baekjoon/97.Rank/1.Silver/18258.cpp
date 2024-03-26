#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> Q;

void Command()
{
	string Input;
	getline(cin, Input);

	string Number;
	int Index = Input.find(' ');
	if (Index != string::npos)
	{
		Number = Input.substr(Index + 1);
		Input = Input.substr(0, Index);
	}

	if (Input.compare("push") == 0)
	{
		Q.emplace(stoi(Number));
	}
	else if (Input.compare("pop") == 0)
	{
		if (Q.empty())
		{
			cout << -1 << '\n';
			return;
		}

		cout << Q.front() << '\n';
		Q.pop();
	}
	else if (Input.compare("size") == 0)
	{
		cout << Q.size() << '\n';
	}
	else if (Input.compare("empty") == 0)
	{
		cout << Q.empty() << '\n';
	}
	else if (Input.compare("front") == 0)
	{
		if (Q.empty())
		{
			cout << -1 << '\n';
			return;
		}

		cout << Q.front() << '\n';
	}
	else if (Input.compare("back") == 0)
	{
		if (Q.empty())
		{
			cout << -1 << '\n';
			return;
		}

		cout << Q.back() << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; ++i)
	{
		Command();
	}
}