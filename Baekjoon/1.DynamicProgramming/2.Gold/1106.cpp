#include <iostream>
#include <climits>
using namespace std;

const int inf = INT_MAX;

int c, n;
int dp[21][1100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 21; ++i)
	{
		for (int j = 1; j < 1100; ++j)
		{
			dp[i][j] = inf;
		}
	}

	cin >> c >> n;
	for (int i = 1; i <= n; ++i)
	{
		int cst, num;
		cin >> cst >> num;

		for (int j = 1; j < 1100; ++j)
		{
			for (int k = 1; num * k <= j; ++k)
			{
				int pn = num * k;
				int ps = dp[i - 1][j - pn];
				if (ps != inf)
				{
					dp[i][j] = min(dp[i][j], min(dp[i - 1][j], ps + cst * k));
				}
			}

			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
		}
	}
	
	int m = inf;
	for (int i = c; i < 1100; ++i)
	{
		m = min(m, dp[n][i]);
	}

	cout << m;
}