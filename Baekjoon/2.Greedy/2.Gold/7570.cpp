#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		dp[num] = dp[num - 1] + 1;
	}

	cout << n - *max_element(dp + 1, dp + n + 1);
}