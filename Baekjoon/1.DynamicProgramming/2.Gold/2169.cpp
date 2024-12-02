#include <iostream>
using namespace std;

int N, M;
int Map[1000][1000];
int DP[1000][1000], LDP[1000], RDP[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Map[i][j];
		}
	}

	DP[0][0] = Map[0][0];
	for (int j = 1; j < M; ++j)
	{
		DP[0][j] = DP[0][j - 1] + Map[0][j];
	}

	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int CurSum = DP[i - 1][j] + Map[i][j];
			LDP[j] = CurSum;
			RDP[j] = CurSum;
		}

		for (int j = 1; j < M; ++j)
		{
			LDP[j] = max(LDP[j], LDP[j - 1] + Map[i][j]);
		}

		for (int j = M - 2; j >= 0; --j)
		{
			RDP[j] = max(RDP[j], RDP[j + 1] + Map[i][j]);
		}

		for (int j = 0; j < M; ++j)
		{
			DP[i][j] = max(LDP[j], RDP[j]);
		}
	}

	cout << DP[N - 1][M - 1];
}