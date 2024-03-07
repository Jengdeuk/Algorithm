#include <iostream>
using namespace std;

int Shop[100][2];
int DP[101][5002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	int MaxS = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> Shop[i][0] >> Shop[i][1];
		MaxS = max(MaxS, Shop[i][1]);
	}

	MaxS = MaxS * K + 1;
	for (int i = 0; i <= K; ++i)
	{
		for (int j = 0; j <= MaxS; ++j)
		{
			DP[i][j] = -1;
		}
	}

	DP[0][1] = 0;
	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j <= MaxS; ++j)
		{
			if (DP[i][j] == -1)
			{
				continue;
			}

			DP[i + 1][j] = max(DP[i + 1][j], DP[i][j] + j);

			for (int k = 0; k < N; ++k)
			{
				int Cost = Shop[k][0];
				int Add = Shop[k][1];

				DP[i + 1][j + Add] = max(DP[i + 1][j + Add], DP[i][j] - Cost);
			}
		}
	}

	int Max = 0;
	for (int j = 1; j <= MaxS; ++j)
	{
		Max = max(Max, DP[K][j]);
	}

	cout << Max;
}