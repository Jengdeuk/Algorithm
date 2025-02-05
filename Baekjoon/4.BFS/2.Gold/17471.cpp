#include <iostream>
#include <list>
#include <queue>
using namespace std;

int n, p[11];
list<int> f[11];
int minGap = 100000;
bool cur[11];

bool bfs(bool isATeam)
{
	bool v[11] = {};

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (cur[i] == isATeam)
		{
			v[i] = true;
			q.emplace(i);
			break;
		}
	}

	while (q.empty() == false)
	{
		int node = q.front();
		q.pop();

		for (const int fnode : f[node])
		{
			if (isATeam == cur[fnode] && v[fnode] == false)
			{
				v[fnode] = true;
				q.emplace(fnode);
			}
		}
	}

	if (isATeam)
	{
		for (int i = 1; i <= n; ++i)
			if (v[i] != cur[i])
				return false;
	}
	else
	{
		for (int i = 1; i <= n; ++i)
			if (v[i] == cur[i])
				return false;
	}

	return true;
}

bool isAllSameTeam()
{
	bool isFirstSameTeam = cur[1];
	for (int i = 2; i <= n; ++i)
		if (isFirstSameTeam != cur[i])
			return false;

	return true;
}

void comb(int idx)
{
	if (idx == n + 1)
	{
		if (isAllSameTeam())
			return;

		if (bfs(true) && bfs(false))
		{
			int ap = 0, bp = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (cur[i])
					ap += p[i];
				else
					bp += p[i];
			}

			if (cur[1] && cur[3] && cur[4])
			{
				int a = 0;
			}
			minGap = min(minGap, abs(ap - bp));
		}

		return;
	}

	cur[idx] = true;
	comb(idx + 1);
	cur[idx] = false;
	comb(idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	for (int i = 1; i <= n; ++i)
	{
		int fn;
		cin >> fn;
		for (int j = 0; j < fn; ++j)
		{
			int frd;
			cin >> frd;
			f[i].emplace_back(frd);
		}
	}

	comb(1);
	if (minGap != 100000)
		cout << minGap;
	else
		cout << -1;
}