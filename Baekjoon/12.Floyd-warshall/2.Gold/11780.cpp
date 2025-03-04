#include <iostream>
#include <list>
using namespace std;

int n, w[101][101];
list<int> nav[101][101];

void fw()
{
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i == j || k == i || k == j || w[i][k] == 0 || w[k][j] == 0)
					continue;

				int nw = w[i][k] + w[k][j];
				if (w[i][j] == 0 || nw < w[i][j])
				{
					w[i][j] = nw;
					nav[i][j] = nav[i][k];
					nav[i][j].pop_back();
					for (const int node : nav[k][j])
						nav[i][j].emplace_back(node);
				}
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

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (w[a][b] == 0)
			w[a][b] = c;
		else
			w[a][b] = min(w[a][b], c);

		if (nav[a][b].empty())
		{
			nav[a][b].emplace_back(a);
			nav[a][b].emplace_back(b);
		}
	}

	fw();

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cout << w[i][j] << ' ';
		cout << '\n';
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (w[i][j] == 0)
			{
				cout << 0 << '\n';
				continue;
			}

			cout << nav[i][j].size() << ' ';
			for (const int node : nav[i][j])
				cout << node << ' ';
			cout << '\n';
		}
	}
}