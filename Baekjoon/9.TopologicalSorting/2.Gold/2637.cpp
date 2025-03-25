#include <iostream>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int n;
int ent[101], dp[101][101];
list<p> f[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	int m;
	cin >> m;
	while (m--)
	{
		int dst, src, num;
		cin >> dst >> src >> num;
		ent[dst]++;
		f[src].emplace_back(dst, num);
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (ent[i] == 0)
		{
			dp[i][i] = 1;
			q.emplace(i);
		}
	}

	int fidx = 0;
	while (q.empty() == false)
	{
		int cur = q.front();
		q.pop();

		if (f[cur].empty())
			fidx = cur;

		for (const p e : f[cur])
		{
			int nxt = e.first;

			for (int i = 1; i <= n; ++i)
				dp[nxt][i] += dp[cur][i] * e.second;

			if (--ent[nxt] == 0)
				q.emplace(nxt);
		}
	}

	for (int i = 1; i <= n; ++i)
		if (dp[fidx][i] > 0)
			cout << i << ' ' << dp[fidx][i] << '\n';
}