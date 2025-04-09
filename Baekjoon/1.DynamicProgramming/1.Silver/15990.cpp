#include <iostream>
using namespace std;

typedef long long ll;

const int mod = 1000000009;
const int n = 100000;

int dp[n + 1][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for (int i = 4; i <= n; ++i)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
	}

	int t;
	cin >> t;
	while (t--)
	{
		int num;
		cin >> num;
		cout << (ll(dp[num][1]) + dp[num][2] + dp[num][3]) % mod << '\n';
	}
}