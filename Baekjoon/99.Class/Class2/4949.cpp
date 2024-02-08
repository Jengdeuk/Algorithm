#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool Check(string Input)
{
	stack<int> CheckStack;

	for (int i = 0; i < Input.size(); ++i)
	{
		if (Input[i] == '(')
		{
			CheckStack.push(1);
		}
		else if (Input[i] == ')')
		{
			if (CheckStack.empty()
				|| CheckStack.top() != 1)
			{
				return false;
			}

			CheckStack.pop();
		}
		else if (Input[i] == '[')
		{
			CheckStack.push(2);
		}
		else if (Input[i] == ']')
		{
			if (CheckStack.empty()
				|| CheckStack.top() != 2)
			{
				return false;
			}

			CheckStack.pop();
		}
	}

	if (!CheckStack.empty())
	{
		return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		string Input;
		getline(cin, Input);

		if (Input == ".")
		{
			break;
		}

		if (Check(Input))
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
}