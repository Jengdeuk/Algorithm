#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	stack<int> ST;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Command;
		cin >> Command;
		switch (Command)
		{
		case 1:
			int X;
			cin >> X;
			ST.emplace(X);
			break;

		case 2:
			if (!ST.empty())
			{
				cout << ST.top() << '\n';
				ST.pop();
			}
			else
			{
				cout << -1 << '\n';
			}
			break;

		case 3:
			cout << ST.size() << '\n';
			break;

		case 4:
			cout << ST.empty() << '\n';
			break;

		case 5:
			if (!ST.empty())
			{
				cout << ST.top() << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
			break;
		}
	}
}