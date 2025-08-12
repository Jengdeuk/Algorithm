#include <iostream>
using namespace std;

typedef pair<int, int> p;

int N, M, P[301][21], DP[301][21];
p T[301][21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int Price;
		cin >> Price;
		for (int j = 1; j <= M; ++j)
		{
			cin >> P[Price][j];
		}
	}

	for (int n = 1; n <= N; ++n)
	{
		for (int j = 1; j <= M; ++j)
		{
			for (int i = 0; i <= n; ++i)
			{
				int NP = DP[n - i][j - 1] + P[i][j];
				if (NP > DP[n][j])
				{
					DP[n][j] = NP;
					T[n][j] = p(j, i);
				}
			}
		}
	}

	int a = 0;
}