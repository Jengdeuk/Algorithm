#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;

const int dx[3] = { -1, 0, 1 };
const int dy[3] = { 0, -1, 0 };

int n, m, d, kill, maxKill;
bool origin[15][15], enemy[15][15], archer[15];
queue<p> kq;

bool isValid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < m);
}

void bfs(int sr, int sc)
{
	bool v[16][15] = {};

	queue<ip> q;
	v[sr][sr] = true;
	q.emplace(0, p(sr, sc));
	while (q.empty() == false)
	{
		int step = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (enemy[r][c])
		{
			kq.emplace(r, c);
			return;
		}

		if (step + 1 > d)
			continue;
		
		for (int i = 0; i < 3; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc) && v[nr][nc] == false)
			{
				v[nr][nc] = true;
				q.emplace(step + 1, p(nr, nc));
			}
		}
	}
}

void attack()
{
	for (int a = 0; a < m; ++a)
	{
		if (archer[a])
		{
			bfs(n, a);
		}
	}

	while (kq.empty() == false)
	{
		int r = kq.front().first;
		int c = kq.front().second;
		kq.pop();

		if (enemy[r][c])
		{
			enemy[r][c] = false;
			++kill;
		}
	}
}

void move()
{
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (enemy[i][j])
			{
				enemy[i][j] = false;
				if (i + 1 < n)
					enemy[i + 1][j] = true;
			}
		}
	}
}

bool isFinished()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (enemy[i][j])
				return false;

	return true;
}

void play()
{
	for (int i = 0; i < m - 2; ++i)
	{
		for (int j = i + 1; j < m - 1; ++j)
		{
			for (int k = j + 1; k < m; ++k)
			{
				memset(archer, false, sizeof(archer));
				archer[i] = true;
				archer[j] = true;
				archer[k] = true;

				kill = 0;
				memcpy(enemy, origin, sizeof(enemy));
				while (isFinished() == false)
				{
					attack();
					move();
				}

				maxKill = max(maxKill, kill);
			}
		}
	}

	cout << maxKill;
}

void initialize()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> origin[i][j];
}

int main()
{
	initialize();
	play();
}