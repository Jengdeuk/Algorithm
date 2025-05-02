#include <iostream>
using namespace std;

const int mod = 10'0000'0003;

int n, k, dp[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i < n; ++i)
		for (int j = 2; j <= k; ++j)
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;

	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % mod;
}