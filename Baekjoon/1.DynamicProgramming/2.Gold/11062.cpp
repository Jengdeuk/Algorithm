#include <iostream>
#include <cstring>
using namespace std;

int N, S[1001], DP[1001][1001];

void Test()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> S[i];
	}

	memset(DP, 0, sizeof(DP));

	if (N % 2 == 0)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j <= N; ++j)
			{
				if (i % 2 == 0)
				{
					DP[j - i][j] = min(DP[j - i][j - 1], DP[j - i + 1][j]);
				}
				else
				{
					DP[j - i][j] = max(DP[j - i][j - 1] + S[j], S[j - i] + DP[j - i + 1][j]);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j <= N; ++j)
			{
				if (i % 2 == 0)
				{
					DP[j - i][j] = max(DP[j - i][j - 1] + S[j], S[j - i] + DP[j - i + 1][j]);
				}
				else
				{
					DP[j - i][j] = min(DP[j - i][j - 1], DP[j - i + 1][j]);
				}
			}
		}
	}

	cout << DP[1][N] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) Test();
}