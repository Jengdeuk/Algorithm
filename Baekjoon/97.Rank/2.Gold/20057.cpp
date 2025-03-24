#include <iostream>
using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

const int mdx[4][10] =
{
	{ -2, -1, -1, -1, 0, 0, 0, 0, 1, 1 },
	{ 0, -1, 0, 1, -2, -1, 1, 2, -1, 1 },
	{ 2, 1, 1, 1, 0, 0, 0, 0, -1, -1 },
	{ 0, 1, 0, -1, 2, 1, -1, -2, 1, -1 }
};

const int mdy[4][10] =
{
	{ 0, -1, 0, 1, -2, -1, 1, 2, -1, 1 },
	{ 2, 1, 1, 1, 0, 0, 0, 0, -1, -1 },
	{ 0, 1, 0, -1, 2, 1, -1, -2, 1, -1 },
	{ -2, -1, -1, -1, 0, 0, 0, 0, 1, 1 }
};

const float mp[10] = { 0.05f, 0.1f, 0.55f, 0.1f, 0.02f, 0.07f, 0.07f, 0.02f, 0.01f, 0.01f };

int n, m[503][503];

void blow(int dir, int r, int c)
{
	int origin = m[r][c];
	for (int i = 0; i < 10; ++i)
	{
		if (i == 2)
			continue;

		int nr = r + mdy[dir][i];
		int nc = c + mdx[dir][i];
		int np = origin * mp[i];
		m[nr][nc] += np;
		m[r][c] -= np;
	}

	int nr = r + mdy[dir][2];
	int nc = c + mdx[dir][2];
	m[nr][nc] += m[r][c];
	m[r][c] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> m[i + 2][j + 2];

	n += 4;

	bool isFinished = false;
	int r = n / 2, c = n / 2;
	int dst = 1, dir = 0;
	while (isFinished == false)
	{
		for (int i = 0; i < 2; ++i)
		{
			for (int k = 0; k < dst; ++k)
			{
				r += dy[dir];
				c += dx[dir];
				blow(dir, r, c);
				if (r == 2 && c == 2)
				{
					isFinished = true;
					i = 2;
					break;
				}
			}

			if (++dir == 4)
				dir = 0;
		}

		dst++;
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i < 2 || j < 2 || i > n - 3 || j > n - 3)
				cnt += m[i][j];

	cout << cnt;
}