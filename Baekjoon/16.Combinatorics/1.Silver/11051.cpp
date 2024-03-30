#include <iostream>
using namespace std;

int DP[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		DP[i][0] = 1;
	}

	DP[1][1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1] % 10007;
		}
	}

	cout << DP[N][K] % 10007;
}