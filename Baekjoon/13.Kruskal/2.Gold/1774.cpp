#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef pair<int, int> p;
typedef pair<double, p> e;

int n, m;
p pos[1000];
vector<e> edges;
int r[1000];

int fnd(int a)
{
	if (r[a] != a)
		r[a] = fnd(r[a]);

	return r[a];
}

void uni(int a, int b)
{
	r[fnd(b)] = fnd(a);
}

double dst(p a, p b)
{
	return sqrt(ll(a.first - b.first) * ll(a.first - b.first) + ll(a.second - b.second) * ll(a.second - b.second));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		r[i] = i;
		cin >> pos[i].first >> pos[i].second;
	}

	int cnt = n - 1;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		if (fnd(--a) == fnd(--b))
			continue;

		uni(a, b);
		cnt--;
	}

	edges.reserve(n * n);
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (fnd(i) != fnd(j))
				edges.emplace_back(dst(pos[i], pos[j]), p(i, j));

	sort(edges.begin(), edges.end());

	double sum = 0;
	while (cnt > 0)
	{
		for (const e& edge : edges)
		{
			int a = edge.second.first;
			int b = edge.second.second;
			if (fnd(a) == fnd(b))
				continue;

			uni(a, b);
			sum += edge.first;
			cnt--;
			break;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << sum;
}