#include <iostream>
#include <list>
#include <queue>
using namespace std;

int n, t[501], p[501], s[501];
list<int> c[501];

void initialize()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> t[i];
		while (true)
		{
			int parent;
			cin >> parent;
			if (parent == -1)
				break;

			++p[i];
			c[parent].emplace_back(i);
		}
	}
}

int main()
{
	initialize();

	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (p[i] == 0)
			q.emplace(i);

	while (q.empty() == false)
	{
		int cur = q.front();
		q.pop();

		s[cur] += t[cur];
		for (const int child : c[cur])
		{
			s[child] = max(s[child], s[cur]);
			if (--p[child] == 0)
				q.emplace(child);
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << s[i] << '\n';
}