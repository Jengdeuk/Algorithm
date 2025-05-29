#include <iostream>
#include <climits>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int inf = INT_MAX;

int n;
list<p> f[1001];

int Dijkstra(int m)
{
	int dst[1001];
	for (int i = 0; i <= n; ++i)
	{
		dst[i] = inf;
	}

	priority_queue<p, vector<p>, greater<p>> q;
	dst[1] = 0;
	q.emplace(0, 1);
	while (q.empty() == false)
	{
		int cst = q.top().first;
		int cur = q.top().second;
		q.pop();

		if (cst > dst[cur])
		{
			continue;
		}

		for (const p frd : f[cur])
		{
			int ncst = dst[cur] + (frd.first > m);
			int nxt = frd.second;
			if (ncst < dst[nxt])
			{
				dst[nxt] = ncst;
				q.emplace(ncst, nxt);
			}
		}
	}

	return dst[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int q, k;
	cin >> n >> q >> k;
	for (int i = 0; i < q; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		f[a].emplace_back(c, b);
		f[b].emplace_back(c, a);
	}

	int answer = -1;
	int l = 0, r = 1000000;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		int cnt = Dijkstra(m);
		if (cnt <= k)
		{
			r = m - 1;
			answer = m;
		}
		else
		{
			l = m + 1;
		}
	}

	cout << answer;
}