#include <iostream>
#include <list>
using namespace std;

int n, p[10001], dp[10001][2];
list<int> f[10001];
bool v[10001];

void dfs(int cur)
{
	dp[cur][1] = p[cur];

	for (const int nxt : f[cur])
	{
		if (v[nxt])
			continue;

		v[nxt] = true;
		dfs(nxt);
		dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
		dp[cur][1] += dp[nxt][0];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		f[a].emplace_back(b);
		f[b].emplace_back(a);
	}

	v[1] = true;
	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
}