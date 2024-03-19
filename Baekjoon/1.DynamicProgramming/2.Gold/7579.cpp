#include <iostream>
using namespace std;

int Memory[101];
int Cost[101];
int DP[101][10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Memory[i];
	}
	for (int i = 1; i <= N; ++i)
	{
		cin >> Cost[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		int Mem = Memory[i];
		int Cst = Cost[i];
		for (int c = 0; c <= 10000; ++c)
		{
			if (c >= Cst)
			{
				DP[i][c] = max(DP[i - 1][c], DP[i - 1][c - Cst] + Mem);
			}
			else
			{
				DP[i][c] = DP[i - 1][c];
			}
		}
	}

	for (int c = 0; c <= 10000; ++c)
	{
		if (DP[N][c] >= M)
		{
			cout << c;
			return 0;
		}
	}
}