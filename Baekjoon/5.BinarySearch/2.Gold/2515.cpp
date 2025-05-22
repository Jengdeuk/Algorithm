#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int n, k, h[300000], dp[300000][2];
p s[300000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i].first >> s[i].second;
	}

	sort(s, s + n);

	for (int i = 0; i < n; ++i)
	{
		h[i] = s[i].first;
	}

	dp[0][1] = s[0].second;
	int sum = dp[0][1];
	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		int idx = upper_bound(h, h + n, s[i].first - k) - h;
		dp[i][1] = dp[idx][0] + s[i].second;

		sum = max(sum, dp[i][1]);
	}

	cout << sum;
}