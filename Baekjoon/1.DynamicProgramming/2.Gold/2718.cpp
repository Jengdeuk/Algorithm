#include <iostream>
using namespace std;

int dp[22];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 5;
	for (int i = 3; i < 22; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2] * 4;
		for (int j = i - 3; j >= 0; --j)
		{
			if ((i - j) % 2 == 0)
				dp[i] += 3 * dp[j];
			else
				dp[i] += 2 * dp[j];
		}
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}