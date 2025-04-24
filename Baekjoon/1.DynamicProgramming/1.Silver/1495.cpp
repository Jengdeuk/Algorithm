#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n;
set<int> dp[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int s, m;
	cin >> n >> s >> m;

	dp[0].emplace(s);
	for (int i = 1; i <= n; ++i)
	{
		int v;
		cin >> v;

		int idx = i % 2;
		set<int> newSet;
		dp[idx].swap(newSet);
		for (const int pv : dp[idx == 1 ? 0 : 1])
		{
			if (pv + v <= m)
				dp[idx].emplace(pv + v);

			if (pv - v >= 0)
				dp[idx].emplace(pv - v);
		}
	}

	int idx = n % 2;
	if (dp[idx].empty() == false)
		cout << *max_element(dp[idx].begin(), dp[idx].end());
	else
		cout << -1;
}