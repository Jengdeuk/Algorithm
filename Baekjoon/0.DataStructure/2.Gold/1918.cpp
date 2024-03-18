#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Origin;
	cin >> Origin;

	stack<char> Operator;
	for (int i = 0; i < Origin.size(); ++i)
	{
		char Ch = Origin[i];
		if (Ch >= 'A')
		{
			cout << Ch;
			continue;
		}

		switch (Ch)
		{
		case '(':
			Operator.push(Ch);
			break;

		case ')':
			while (Operator.top() != '(')
			{
				cout << Operator.top();
				Operator.pop();
			}
			Operator.pop();
			break;

		case '*':
		case '/':
			if (!Operator.empty()
				&& (Operator.top() == '*' || Operator.top() == '/'))
			{
				cout << Operator.top();
				Operator.pop();
			}
			Operator.push(Ch);
			break;

		case '+':
		case '-':
			while (!Operator.empty()
				&& Operator.top() != '(')
			{
				cout << Operator.top();
				Operator.pop();
			}
			Operator.push(Ch);
			break;
		}
	}

	while (!Operator.empty())
	{
		cout << Operator.top();
		Operator.pop();
	}
}