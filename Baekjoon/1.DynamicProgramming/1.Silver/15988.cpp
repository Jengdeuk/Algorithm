#include <iostream>
using namespace std;

const int mod = 1000000009;

int dp[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; ++i)
		dp[i] = ((dp[i - 3] + dp[i - 2]) % mod + dp[i - 1]) % mod;

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}