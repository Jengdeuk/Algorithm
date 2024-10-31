#include <iostream>
using namespace std;

typedef long long ll;

ll DP[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	DP[0][0] = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int Num;
			cin >> Num;
			if (i == N - 1 && j == N - 1)
			{
				continue;
			}

			if (j + Num < N)
			{
				DP[i][j + Num] += DP[i][j];
			}

			if (i + Num < N)
			{
				DP[i + Num][j] += DP[i][j];
			}
		}
	}

	cout << DP[N - 1][N - 1];
}