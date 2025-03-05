#include <iostream>
using namespace std;

const int maxK = 18;

int m;
int f[200001][maxK + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> m;
	for (int i = 1; i <= m; ++i)
		cin >> f[i][1];

	for (int k = 2; k <= maxK; ++k)
		for (int i = 1; i <= m; ++i)
			f[i][k] = f[f[i][k - 1]][k - 1];

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int n, x;
		cin >> n >> x;
		while (n > 0)
		{
			int step = 1, sk = 1;
			for (int k = maxK; k >= 1; --k)
			{
				step = 1 << (k - 1);
				sk = k;
				if (step <= n)
					break;
			}

			x = f[x][sk];
			n -= step;
		}
		cout << x << '\n';
	}
}