#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> T;

void PrintStack()
{
	while (!T.empty())
	{
		cout << T.top();
		T.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	getline(cin, S);

	bool bForward = false;
	for (int i = 0; i < S.size(); ++i)
	{
		if (S[i] == '<')
		{
			bForward = true;
		}
		else if (S[i] == '>')
		{
			bForward = false;
		}
		else if (S[i] != ' ' && !bForward)
		{
			T.emplace(S[i]);
			continue;
		}

		PrintStack();
		cout << S[i];
	}

	PrintStack();
}