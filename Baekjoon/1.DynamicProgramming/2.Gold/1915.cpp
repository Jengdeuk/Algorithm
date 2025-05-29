#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;

		for (int j = 1; j <= m; ++j)
		{
			dp[i][j] = s[j - 1] - '0';
		}
	}

	int ms = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (dp[i][j] == 0)
			{
				continue;
			}

			ms = max(ms, (dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1));
		}
	}

	cout << ms * ms;
}