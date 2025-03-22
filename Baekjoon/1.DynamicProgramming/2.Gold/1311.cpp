#include <iostream>
#include <cstring>
using namespace std;

const int inf = 123456789;

int n, w[20][20], dp[21][1 << 20];

int minValue = inf;

int func(int idx, int bit)
{
	if (bit == (1 << n) - 1)
		return 0;

	if (dp[idx][bit] != -1)
		return dp[idx][bit];

	dp[idx][bit] = inf;
	for (int i = 0; i < n; ++i)
	{
		if (bit & (1 << i))
			continue;

		dp[idx][bit] = min(dp[idx][bit], func(idx + 1, bit | (1 << i)) + w[i][idx]);
	}

	return dp[idx][bit];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> w[i][j];

	cout << func(0, 0);
}