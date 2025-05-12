#include <iostream>
using namespace std;

bool vip[41];
int n, dp[41];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 40; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	cin >> n;

	int m;
	cin >> m;
	while (m--)
	{
		int num;
		cin >> num;
		vip[num] = true;
	}

	int idx = 0, sum = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (vip[i] == false)
		{
			idx++;
		}
		else
		{
			sum *= dp[idx];
			idx = 0;
		}
	}

	sum *= dp[idx];
	cout << sum;
}