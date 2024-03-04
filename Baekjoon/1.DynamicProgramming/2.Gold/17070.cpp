#include <iostream>
using namespace std;

int House[16][16];
int DP[16][16][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> House[i][j];
		}
	}

	DP[0][1][0] = 1;
	for (int i = 2; i < N; ++i)
	{
		if (House[0][i] == 1)
		{
			break;
		}

		DP[0][i][0] = 1;
	}

	for (int i = 1; i < N; ++i)
	{
		for (int j = 2; j < N; ++j)
		{
			if (House[i][j] == 1)
			{
				continue;
			}

			DP[i][j][0] = DP[i][j - 1][0] + DP[i][j - 1][2];
			DP[i][j][1] = DP[i - 1][j][1] + DP[i - 1][j][2];

			if (House[i - 1][j] == 1
				|| House[i][j - 1] == 1)
			{
				continue;
			}

			for (int k = 0; k < 3; ++k)
			{
				DP[i][j][2] += DP[i - 1][j - 1][k];
			}
		}
	}

	int Sum = 0;
	for (int i = 0; i < 3; ++i)
	{
		Sum += DP[N - 1][N - 1][i];
	}

	cout << Sum;
}