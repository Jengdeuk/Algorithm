#include <iostream>
using namespace std;

int dp[2][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	dp[0][0] = 1;
	dp[0][1] = 0;

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int idx = i % 2;
		int pre = idx ? 0 : 1;
		dp[idx][0] = dp[pre][1];
		dp[idx][1] = dp[pre][0] + dp[pre][1];
	}

	cout << dp[n % 2][0] << ' ' << dp[n % 2][1];
}