#include <iostream>
#include <stack>
using namespace std;

string Str;
stack<char> Left;
stack<char> Right;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> Str;

	for (int i = 0; i < Str.size(); ++i)
	{
		Left.emplace(Str[i]);
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		char C;
		cin >> C;
		switch (C)
		{
		case 'L':
			if (!Left.empty())
			{
				Right.emplace(Left.top());
				Left.pop();
			}
			break;

		case 'D':
			if (!Right.empty())
			{
				Left.emplace(Right.top());
				Right.pop();
			}
			break;

		case 'B':
			if (!Left.empty())
			{
				Left.pop();
			}
			break;

		case 'P':
			char ch;
			cin >> ch;
			Left.emplace(ch);
			break;
		}
	}

	while (!Left.empty())
	{
		Right.emplace(Left.top());
		Left.pop();
	}

	while (!Right.empty())
	{
		cout << Right.top();
		Right.pop();
	}
}