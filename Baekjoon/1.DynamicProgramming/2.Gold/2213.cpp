#include <iostream>
#include <list>
#include <cstring>
using namespace std;

int n;
int w[10001];
list<int> f[10001];
int dp[10001][2];
bool v[10001], c[10001];

void storeDp(int node)
{
	v[node] = true;
	dp[node][1] = w[node];

	for (const int frd : f[node])
	{
		if (v[frd])
		{
			continue;
		}

		storeDp(frd);
		dp[node][0] += max(dp[frd][1], dp[frd][0]);
		dp[node][1] += dp[frd][0];
	}
}

void makeRoad(int parent, int node)
{
	v[node] = true;
	if (c[parent] == false && dp[node][1] > dp[node][0])
	{
		c[node] = true;
	}

	for (const int frd : f[node])
	{
		if (v[frd])
		{
			continue;
		}

		makeRoad(node, frd);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> w[i];
	}

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		f[a].emplace_back(b);
		f[b].emplace_back(a);
	}

	storeDp(1);

	memset(v, false, sizeof(v));
	makeRoad(0, 1);

	cout << max(dp[1][0], dp[1][1]) << '\n';
	for (int i = 1; i <= n; ++i)
	{
		if (c[i])
		{
			cout << i << ' ';
		}
	}
}