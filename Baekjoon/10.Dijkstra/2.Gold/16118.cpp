#include <iostream>
#include <climits>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, bool> ib;
typedef pair<int, ib> iib;

const int inf = INT_MAX;

int n, fox[4001], wolf[4001][2];
list<p> f[4001];

void dijkstra()
{
	for (int i = 1; i <= n; ++i)
		fox[i] = inf;

	priority_queue<p, vector<p>, greater<p>> q;
	fox[1] = 0;
	q.emplace(0, 1);
	while (q.empty() == false)
	{
		int cur = q.top().second;
		int dst = q.top().first;
		q.pop();

		if (dst > fox[cur])
			continue;

		for (const p frd : f[cur])
		{
			int nxt = frd.second;
			int ndst = fox[cur] + frd.first;
			if (ndst < fox[nxt])
			{
				fox[nxt] = ndst;
				q.emplace(ndst, nxt);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 2; ++j)
			wolf[i][j] = inf;

	priority_queue<iib, vector<iib>, greater<iib>> pq;
	wolf[1][1] = 0;
	pq.emplace(0, ib(1, true));
	while (pq.empty() == false)
	{
		int cur = pq.top().second.first;
		int dst = pq.top().first;
		bool isFast = pq.top().second.second;
		pq.pop();

		if (dst > wolf[cur][isFast])
			continue;

		for (const p frd : f[cur])
		{
			int nxt = frd.second;
			int ndst = wolf[cur][isFast] + (isFast ? frd.first / 2 : frd.first * 2);
			if (ndst < wolf[nxt][isFast == false])
			{
				wolf[nxt][isFast == false] = ndst;
				pq.emplace(ndst, ib(nxt, isFast == false));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int m;
	cin >> n >> m;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		f[a].emplace_back(2 * c, b);
		f[b].emplace_back(2 * c, a);
	}

	dijkstra();

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (fox[i] < min(wolf[i][0], wolf[i][1]))
			cnt++;

	cout << cnt;
}