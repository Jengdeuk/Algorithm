#include <iostream>
#include <list>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int inf = INT_MAX;

int n, d[300001];
list<int> f[300001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int m, k, x;
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		f[a].emplace_back(b);
	}

	for (int i = 1; i <= n; ++i)
		d[i] = inf;

	priority_queue<p, vector<p>, greater<p>> q;
	d[x] = 0;
	q.emplace(0, x);
	while (q.empty() == false)
	{
		int dst = q.top().first;
		int cur = q.top().second;
		q.pop();
		if (dst > d[cur])
			continue;

		for (const int nxt : f[cur])
		{
			int ndst = d[cur] + 1;
			if (ndst < d[nxt])
			{
				d[nxt] = ndst;
				q.emplace(ndst, nxt);
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (d[i] == k && ++cnt)
			cout << i << '\n';

	if (cnt == 0)
		cout << -1;
}