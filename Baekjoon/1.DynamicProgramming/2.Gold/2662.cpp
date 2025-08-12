#include <iostream>
using namespace std;

int N, M, P[301][21], DP[301][21];

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

	for (int i = 1; i <= M; ++i)
	{
		for (int j = N; j >= 0; --j)
		{
			for (int k = 0; k <= j; ++k)
			{
				int NDP = DP[j - k][0] + P[k][i];
				if (NDP > DP[j][0])
				{
					DP[j][0] = NDP;
					for (int l = 1; l <= M; ++l)
					{
						if (l == i)
						{
							DP[j][i] = k;
						}
						else
						{
							DP[j][l] = DP[j - k][l];
						}
					}
				}
			}
		}
	}

	cout << DP[N][0] << '\n';
	for (int i = 1; i <= M; ++i)
	{
		cout << DP[N][i] << ' ';
	}
}