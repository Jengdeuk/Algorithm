#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, bool> ib;
typedef pair<ib, p> pp;

const int dx[8] = { -1, 0, 1, 0, -1, 1, -1, 1 };
const int dy[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };

int n;
char m[50][50];
bool v[2][50][50];

p pos, gPos;
bool ver, gVer;

bool isValid(bool iv, int r, int c)
{
	return ((iv && (r <= 0 || r >= n - 1 || c < 0 || c > n - 1))
		|| (iv == false && (r < 0 || r > n - 1 || c <= 0 || c >= n - 1))
		|| v[iv][r][c]
		|| m[r][c] == '1'
		|| m[r - (iv)][c - (iv == false)] == '1'
		|| m[r + (iv)][c + (iv == false)] == '1')
		== false;
}

int bfs()
{
	queue<pp> q;
	v[ver][pos.first][pos.second] = true;
	q.emplace(ib(0, ver), pos);
	while (q.empty() == false)
	{
		int t = q.front().first.first;
		bool iv = q.front().first.second;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (r == gPos.first && c == gPos.second && iv == gVer)
		{
			return t;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(iv, nr, nc))
			{
				v[iv][nr][nc] = true;
				q.emplace(ib(t + 1, iv), p(nr, nc));
			}
		}

		bool isTurnable = true;
		for (int i = 0; i < 8; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (nr < 0 || nr > n - 1 || nc < 0 || nc > n - 1 || m[nr][nc] == '1')
			{
				isTurnable = false;
				break;
			}
		}

		if (isTurnable && v[!iv][r][c] == false)
		{
			v[!iv][r][c] = true;
			q.emplace(ib(t + 1, !iv), p(r, c));
		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j)
		{
			m[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			switch (m[i][j])
			{
			case 'B':
				if (i > 0 && i < n - 1 && m[i - 1][j] == 'B' && m[i + 1][j] == 'B')
				{
					pos = p(i, j);
					ver = true;
				}
				else if (j > 0 && j < n - 1 && m[i][j - 1] == 'B' && m[i][j + 1] == 'B')
				{
					pos = p(i, j);
					ver = false;
				}
				break;
			case 'E':
				if (i > 0 && i < n - 1 && m[i - 1][j] == 'E' && m[i + 1][j] == 'E')
				{
					gPos = p(i, j);
					gVer = true;
				}
				else if (j > 0 && j < n - 1 && m[i][j - 1] == 'E' && m[i][j + 1] == 'E')
				{
					gPos = p(i, j);
					gVer = false;
				}
				break;
			}
		}
	}

	cout << bfs();
}