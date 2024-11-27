#include <iostream>
#include <climits>
#include <stack>
using namespace std;

const int Inf = INT_MAX;

int N;
int P[1000001], DP[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		DP[i] = Inf;
	}
	
	DP[N] = 0;
	P[N] = -1;
	for (int i = N; i > 1; --i)
	{
		int NewValue = DP[i] + 1;

		if (i % 3 == 0 && NewValue < DP[i / 3])
		{
			DP[i / 3] = NewValue;
			P[i / 3] = i;
		}

		if (i % 2 == 0 && NewValue < DP[i / 2])
		{
			DP[i / 2] = NewValue;
			P[i / 2] = i;
		}

		if (NewValue < DP[i - 1])
		{
			DP[i - 1] = NewValue;
			P[i - 1] = i;
		}
	}

	stack<int> ST;
	ST.emplace(1);
	while (P[ST.top()] != -1)
	{
		ST.emplace(P[ST.top()]);
	}

	cout << DP[1] << '\n';
	while (!ST.empty())
	{
		cout << ST.top() << ' ';
		ST.pop();
	}
}