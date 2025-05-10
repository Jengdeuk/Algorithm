#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int n, k, m;
int ab[1000][1000];
unordered_set<int> f[100001];

queue<p> q;
bool v[100001], vab[1000];

int bfs()
{
	v[1] = true;
	q.emplace(1, 1);
	while (q.empty() == false)
	{
		int step = q.front().first;
		int cur = q.front().second;
		q.pop();

		if (cur == n)
			return step;

		for (const int addrBook : f[cur])
		{
			if (vab[addrBook])
				continue;

			vab[addrBook] = true;
			for (int i = 0; i < k; ++i)
			{
				int nxt = ab[addrBook][i];
				if (v[nxt])
					continue;

				v[nxt] = true;
				q.emplace(step + 1, nxt);
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k >> m;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			cin >> ab[i][j];
			f[ab[i][j]].emplace(i);
		}
	}

	cout << bfs();
}