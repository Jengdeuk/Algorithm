#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	bool possible = true;

	int n = 0;
	cin >> n;

	vector<int> sequence;
	sequence.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		int inputNumber = 0;
		cin >> inputNumber;
		sequence.emplace_back(inputNumber);
	}

	stack<int> outputStack;
	for (int i = n; i > 0; --i)
	{
		outputStack.push(i);
	}

	queue<bool> result;
	stack<int> inputStack;
	for (int i = 0; i < n; ++i)
	{
		while ((inputStack.empty() || inputStack.top() < sequence[i])
			&& !outputStack.empty())
		{
			inputStack.push(outputStack.top());
			outputStack.pop();
			result.push(true);
		}

		if (inputStack.top() == sequence[i])
		{
			inputStack.pop();
			result.push(false);
			continue;
		}
		else
		{
			possible = false;
			break;
		}
	}

	if (!possible)
	{
		cout << "NO\n";
		return 0;
	}

	while (!result.empty())
	{
		if (result.front())
		{
			cout << "+\n";
		}
		else
		{
			cout << "-\n";
		}
		result.pop();
	}
}