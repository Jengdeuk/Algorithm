#include <iostream>
using namespace std;

int RC[500][2];
int DP[500][500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> RC[i][0] >> RC[i][1];
	}

	for (int k = 1; k <= N - 1; ++k)
	{
		for (int i = 0; i < N - k; ++i)
		{
			int j = i + k;
			DP[i][j] = 1000000000;

			for (int m = i; m < j; ++m)
			{
				DP[i][j] = min(DP[i][j], DP[i][m] + DP[m + 1][j] + RC[i][0] * RC[m][1] * RC[j][1]);
			}
		}
	}

	cout << DP[0][N - 1];
}