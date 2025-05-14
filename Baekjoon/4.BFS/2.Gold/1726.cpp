#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, p> pp;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;
bool w[100][100], v[100][100][4];

bool isValid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}

int bfs(int sr, int sc, int sd, int er, int ec, int ed)
{
	queue<pp> q;
	v[sr][sc][sd] = true;
	q.emplace(p(0, sd), p(sr, sc));
	while (q.empty() == false)
	{
		int t = q.front().first.first;
		int d = q.front().first.second;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (r == er && c == ec && d == ed)
			return t;

		for (int i = 1; i <= 3; ++i)
		{
			int nr = r + i * dy[d];
			int nc = c + i * dx[d];
			if (isValid(nr, nc) && v[nr][nc][d] == false)
			{
				if (w[nr][nc])
					break;

				v[nr][nc][d] = true;
				q.emplace(p(t + 1, d), p(nr, nc));
			}
		}

		int nd = (d == 0 ? 3 : d - 1);
		if (v[r][c][nd] == false)
		{
			v[r][c][nd] = true;
			q.emplace(p(t + 1, nd), p(r, c));
		}

		nd = (d == 3 ? 0 : d + 1);
		if (v[r][c][nd] == false)
		{
			v[r][c][nd] = true;
			q.emplace(p(t + 1, nd), p(r, c));
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> w[i][j];

	int sr, sc, sd;
	cin >> sr >> sc >> sd;
	sr--;
	sc--;
	switch (sd)
	{
	case 1:
		sd = 0;
		break;
	case 2:
		sd = 2;
		break;
	case 3:
		sd = 1;
		break;
	case 4:
		sd = 3;
		break;
	}

	int er, ec, ed;
	cin >> er >> ec >> ed;
	er--;
	ec--;
	switch (ed)
	{
	case 1:
		ed = 0;
		break;
	case 2:
		ed = 2;
		break;
	case 3:
		ed = 1;
		break;
	case 4:
		ed = 3;
		break;
	}

	cout << bfs(sr, sc, sd, er, ec, ed);
}