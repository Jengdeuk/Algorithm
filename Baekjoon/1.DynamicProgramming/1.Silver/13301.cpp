#include <iostream>
using namespace std;

typedef long long ll;

ll dp[81];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n] * 4 + 2 * dp[n - 1];
}