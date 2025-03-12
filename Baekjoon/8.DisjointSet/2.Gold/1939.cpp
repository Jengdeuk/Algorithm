#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge
{
	int a, b, w;
	bool operator<(const edge& r) const { return (w > r.w); }
};

int n, r[10001];
edge edges[100000];

int find(int n)
{
	if (r[n] != n)
		r[n] = find(r[n]);

	return r[n];
}

void uni(int a, int b)
{
	r[find(a)] = find(b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		r[i] = i;

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> edges[i].a >> edges[i].b >> edges[i].w;

	sort(edges, edges + m);

	int src, dst;
	cin >> src >> dst;
	for (const edge& e : edges)
	{
		uni(e.a, e.b);
		if (find(src) == find(dst))
		{
			cout << e.w;
			break;
		}
	}
}