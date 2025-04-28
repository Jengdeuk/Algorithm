#include <iostream>
#include <climits>
using namespace std;

const int inf = INT_MAX;

int n, d[401][401];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);


	int k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j)
				d[i][j] = inf;

	while (k--)
	{
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i == k || j == k || i == j || d[i][k] == inf || d[k][j] == inf)
					continue;

				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int s;
	cin >> s;
	while (s--)
	{
		int a, b;
		cin >> a >> b;

		if (d[a][b] == inf && d[b][a] == inf)
			cout << 0;
		else if (d[a][b] != inf)
			cout << -1;
		else
			cout << 1;
		cout << '\n';
	}
}