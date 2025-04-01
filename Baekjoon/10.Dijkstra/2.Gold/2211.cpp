#include <iostream>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int inf = 123456790;

int n, dt[1001], ent[1001];
list<p> f[1001];

void dijkstra()
{
	for (int i = 0; i <= n; ++i)
		dt[i] = inf;

	priority_queue<p, vector<p>, greater<p>> q;
	dt[1] = 0;
	q.emplace(0, 1);
	while (q.empty() == false)
	{
		int cur = q.top().second;
		int tim = q.top().first;
		q.pop();

		if (tim > dt[cur])
			continue;

		for (const p e : f[cur])
		{
			int nxt = e.second;
			int ntm = e.first + dt[cur];
			if (ntm < dt[nxt])
			{
				ent[nxt] = cur;
				dt[nxt] = ntm;
				q.emplace(ntm, nxt);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n;

	int m;
	cin >> m;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		f[a].emplace_back(c, b);
		f[b].emplace_back(c, a);
	}

	dijkstra();

	cout << n - 1 << '\n';
	for (int i = 1; i <= n; ++i)
		if (ent[i] > 0)
			cout << i << ' ' << ent[i] << '\n';
}