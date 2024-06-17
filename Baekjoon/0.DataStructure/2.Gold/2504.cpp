#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef pair<char, int> p;

string S;
int N;

stack<p> ST;
int SC[30];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> S;
	N = S.size();

	bool bClose = false;
	for (int i = 0; i < N; ++i)
	{
		char C = S[i];
		switch (C)
		{
		case '(':
		case '[':
			ST.emplace(C, i);
			bClose = false;
			break;

		case ')':
		case ']':
			if (ST.empty()
				|| (C == ')' && ST.top().first != '(')
				|| (C == ']' && ST.top().first != '['))
			{
				cout << 0;
				return 0;
			}

			int TS = ST.top().second;
			ST.pop();

			int G = (C == ')' ? 2 : 3);
			if (!bClose)
			{
				SC[TS] = G;
			}
			else
			{
				int K = 0;
				for (int j = TS; j <= i; ++j)
				{
					K += SC[j];
					SC[j] = 0;
				}
				SC[TS] = K * G;
			}

			bClose = true;
			break;
		}
	}

	if (!ST.empty())
	{
		cout << 0;
		return 0;
	}

	int Score = 0;
	for (int i = 0; i < N; ++i)
	{
		Score += SC[i];
	}

	cout << Score;
}