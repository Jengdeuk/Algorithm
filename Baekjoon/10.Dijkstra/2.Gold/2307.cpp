#include <iostream>
#include <list>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> p;

const int inf = INT_MAX;

int n, org, dst[1001], pre[1001];
list<p> f[1001];

int dijkstra(int nsrc, int ndst)
{
	for (int i = 2; i <= n; ++i)
		dst[i] = inf;

	priority_queue<p, vector<p>, greater<p>> q;
	q.emplace(0, 1);
	while (q.empty() == false)
	{
		int cst = q.top().first;
		int cur = q.top().second;
		q.pop();

		if (cst > dst[cur])
			continue;

		for (const p np : f[cur])
		{
			int nxt = np.second;
			if ((cur == nsrc && nxt == ndst) || (cur == ndst && nxt == nsrc))
				continue;

			int ncst = dst[cur] + np.first;
			if (ncst < dst[nxt])
			{
				pre[nxt] = cur;
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

	cin >> n;

	int m;
	cin >> m;
	while (m--)
	{
		int a, b, t;
		cin >> a >> b >> t;
		f[a].emplace_back(t, b);
		f[b].emplace_back(t, a);
	}

	org = dijkstra(0, 0);

	queue<p> q;
	int cur = n;
	int nxt = pre[cur];
	while (nxt >= 1)
	{
		q.emplace(cur, nxt);
		cur = nxt;
		nxt = pre[cur];
	}

	int answer = 0;
	while (q.empty() == false)
	{
		int cur = q.front().first;
		int nxt = q.front().second;
		q.pop();

		int newCst = dijkstra(cur, nxt);
		if (newCst == inf)
		{
			answer = -1;
			break;
		}

		answer = max(answer, newCst - org);
	}

	cout << answer;
}