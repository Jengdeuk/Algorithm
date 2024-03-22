#include <iostream>
#include <stack>
using namespace std;

int Sequence[1000];
int DP[1000];
stack<int> LIS;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int Max = 0;

	int Index = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Sequence[i];

		for (int j = 0; j < i; ++j)
		{
			if (Sequence[j] < Sequence[i]
				&& DP[j] > DP[i])
			{
				DP[i] = DP[j];
			}
		}

		DP[i] += 1;
		if (DP[i] > Max)
		{
			Index = i;
			Max = DP[i];
		}
	}

	LIS.emplace(Sequence[Index]);

	int j = Index;
	for (int i = Index - 1; i >= 0; --i)
	{
		if (DP[i] == DP[j] - 1)
		{
			LIS.emplace(Sequence[i]);
			j = i;
		}
	}

	cout << Max << '\n';
	while (!LIS.empty())
	{
		cout << LIS.top() << ' ';
		LIS.pop();
	}
}