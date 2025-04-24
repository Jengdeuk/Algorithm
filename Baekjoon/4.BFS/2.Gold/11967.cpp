#include <iostream>
#include <cstring>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n;
list<p> sw[100][100];
bool on[100][100], v[100][100];

bool isValid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < n && v[r][c] == false && on[r][c];
}

void bfs()
{
	on[0][0] = true;

	queue<p> q;
	v[0][0] = true;
	q.emplace(0, 0);
	while (q.empty() == false)
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		int cnt = 0;
		for (const p light : sw[r][c])
		{
			if (on[light.first][light.second] == false)
			{
				on[light.first][light.second] = true;
				cnt++;
			}
		}

		if (cnt > 0)
		{
			memset(v, false, sizeof(v));
			v[r][c] = true;
		}

		if (sw[r][c].empty() == false)
		{
			list<p> blank;
			sw[r][c].swap(blank);
		}

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc))
			{
				v[nr][nc] = true;
				q.emplace(nr, nc);
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
	while (m--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		sw[a - 1][b - 1].emplace_back(c - 1, d - 1);
	}

	bfs();

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cnt += on[i][j];

	cout << cnt;
}