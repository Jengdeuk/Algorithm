#include <iostream>
using namespace std;

int N, M;
int DP[1000][27];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= 26; ++i)
	{
		DP[0][i] = 1;
	}

	for (int i = 1; i < M; ++i)
	{
		for (int j = 1; j <= 26; ++j)
		{
			for (int k = 1; k <= 26; ++k)
			{
				if (abs(j - k) >= N)
				{
					DP[i][j] += DP[i - 1][k];
					DP[i][j] %= 1000000007;
				}
			}
		}
	}

	int Sum = 0;
	for (int i = 1; i <= 26; ++i)
	{
		Sum += DP[M - 1][i];
		Sum %= 1000000007;
	}

	cout << Sum;
}