#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> p;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m;
bool c[100][100], g[100][100], v[100][100];
vector<p> clust;

void throwStick(int tdx, int height)
{
	int y = height, x = (tdx == 1 ? 0 : m - 1);

	while (x >= 0 && x < m && !c[y][x])
	{
		x += tdx;
	}

	if (x >= 0 && x < m)
	{
		c[y][x] = false;
	}
}

bool isValid(int x, int y)
{
	return (x >= 0 && x < m && y >= 0 && y < n);
}

void BFS(bool bMove, int sx, int sy)
{
	queue<p> q;
	v[sy][sx] = true;
	q.emplace(sx, sy);
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (bMove)
		{
			c[y][x] = false;
			clust.emplace_back(x, y);
		}
		else
		{
			g[y][x] = true;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isValid(nx, ny) && !v[ny][nx] && c[ny][nx])
			{
				v[ny][nx] = true;
				q.emplace(nx, ny);
			}
		}
	}
}

void fallClust()
{
	int minH = 100000;
	for (const p point : clust)
	{
		int x = point.first;
		int y = point.second;

		int h = y;
		while (h > 0 && !g[h - 1][x])
		{
			--h;
		}

		minH = min(minH, abs(h - y));
	}

	for (const p point : clust)
	{
		int x = point.first;
		int y = point.second;
		c[y - minH][x] = true;
	}

	clust.clear();
}

void checkAttachedGround()
{
	memset(g, false, sizeof(g));
	memset(v, false, sizeof(v));
	for (int x = 0; x < m; ++x)
	{
		if (c[0][x] && !v[0][x])
		{
			BFS(false, x, 0);
		}
	}
}

p isFloating()
{
	checkAttachedGround();

	for (int y = 1; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (c[y][x] && !v[y][x])
			{
				return p(x, y);
			}
		}
	}

	return p(-1, -1);
}

void updateMineral()
{
	p pos;
	if ((pos = isFloating()).second >= 1)
	{
		BFS(true, pos.first, pos.second);
		fallClust();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char ch;
			cin >> ch;
			if (ch == 'x')
			{
				c[n - 1 - i][j] = true;
			}
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int h;
		cin >> h;
		throwStick((i % 2 == 0 ? 1 : -1), (h - 1));
		updateMineral();
	}

	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << (c[i][j] ? 'x' : '.');
		}
		cout << '\n';
	}
}