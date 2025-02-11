#include <iostream>
using namespace std;

int n, m;
int candy[1000][1000], dp[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> candy[i][j];
	
	dp[0][0] = candy[0][0];
	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = dp[i - 1][0] + candy[i][0];
	}

	for (int i = 1; i < m; ++i)
	{
		dp[0][i] = dp[0][i - 1] + candy[0][i];
	}

	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j)
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + candy[i][j];

	cout << dp[n - 1][m - 1];
}