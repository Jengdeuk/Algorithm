#include <iostream>
using namespace std;

int s[1000], dp[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
		for (int j = 0; j < i; ++j)
			if (s[j] < s[i] && dp[j] > dp[i])
				dp[i] = dp[j];

		dp[i]++;
		answer = max(answer, dp[i]);
	}

	cout << answer;
}