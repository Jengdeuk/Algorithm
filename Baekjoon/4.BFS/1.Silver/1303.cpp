#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m;
bool w[100][100], v[100][100];

bool isValid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m && v[r][c] == false;
}

int bfs(int sr, int sc)
{
	int cnt = 0;

	queue<p> q;
	v[sr][sc] = true;
	q.emplace(sr, sc);
	while (q.empty() == false)
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		cnt++;
		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc) && w[r][c] == w[nr][nc])
			{
				v[nr][nc] = true;
				q.emplace(nr, nc);
			}
		}
	}

	return cnt * cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> m >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char ch;
			cin >> ch;
			if (ch == 'W')
				w[i][j] = true;
		}
	}

	int ws = 0, bs = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == false)
			{
				int score = bfs(i, j);
				if (w[i][j])
					ws += score;
				else
					bs += score;
			}
		}
	}

	cout << ws << ' ' << bs;
}