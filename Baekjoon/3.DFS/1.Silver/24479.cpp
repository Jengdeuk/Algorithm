#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, idx, o[100001];
bool v[100001];
vector<int> f[100001];

void DFS(int cur)
{
	for (const int nxt : f[cur])
	{
		if (v[nxt])
		{
			continue;
		}

		o[nxt] = ++idx;
		v[nxt] = true;
		DFS(nxt);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int m, r;
	cin >> n >> m >> r;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		f[a].emplace_back(b);
		f[b].emplace_back(a);
	}

	for (int i = 1; i <= n; ++i)
	{
		sort(f[i].begin(), f[i].end());
	}

	o[r] = ++idx;
	v[r] = true;
	DFS(r);

	for (int i = 1; i <= n; ++i)
	{
		cout << o[i] << '\n';
	}
}