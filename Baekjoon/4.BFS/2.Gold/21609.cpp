#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> p;

const int rainbow = -2;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m, score, b[20][20];
bool v[20][20];

bool isValid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < n && v[r][c] == false);
}

p fbfs(int sr, int sc)
{
	int color = b[sr][sc];

	p rv = p(0, 0);
	queue<p> q, rbq;
	v[sr][sc] = true;
	q.emplace(sr, sc);
	if (b[sr][sc] == rainbow)
		rbq.emplace(sr, sc);

	while (q.empty() == false)
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		rv.first++;
		if (b[r][c] == rainbow)
			rv.second++;

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc) == false)
				continue;

			int ncolor = b[nr][nc];
			if (ncolor == color || ncolor == rainbow)
			{
				v[nr][nc] = true;
				q.emplace(nr, nc);
				if (ncolor == rainbow)
					rbq.emplace(nr, nc);
			}
		}
	}

	while (rbq.empty() == false)
	{
		int r = rbq.front().first;
		int c = rbq.front().second;
		rbq.pop();
		v[r][c] = false;
	}

	return rv;
}

p findGroupKey()
{
	memset(v, false, sizeof(v));

	int bn = 0, rbn = 0, kr = 0, kc = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (b[i][j] <= 0 || v[i][j])
				continue;

			p rv = fbfs(i, j);
			if (rv.first > bn || (rv.first == bn && rv.second >= rbn))
			{
				bn = rv.first;
				rbn = rv.second;
				kr = i;
				kc = j;
			}
		}
	}

	if (bn < 2)
		return p(-1, -1);

	return p(kr, kc);
}

bool popBlocks(p groupKey)
{
	int sr = groupKey.first;
	int sc = groupKey.second;
	if (sr == -1 && sc == -1)
		return false;

	memset(v, false, sizeof(v));

	int color = b[sr][sc];
	int cnt = 0;

	queue<p> q;
	v[sr][sc] = true;
	q.emplace(sr, sc);
	while (q.empty() == false)
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		b[r][c] = 0;
		cnt++;

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc) == false)
				continue;

			int ncolor = b[nr][nc];
			if (ncolor == color || ncolor == rainbow)
			{
				v[nr][nc] = true;
				q.emplace(nr, nc);
			}
		}
	}

	score += cnt * cnt;

	return true;
}

void applyGravity()
{
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (b[i][j] == 0 || b[i][j] == -1)
				continue;

			int h = i;
			while (h + 1 < n && b[h + 1][j] == 0)
				h++;

			if (i != h)
			{
				b[h][j] = b[i][j];
				b[i][j] = 0;
			}
		}
	}
}

void turnCCW()
{
	int temp[20][20] = {};
	memcpy(temp, b, sizeof(temp));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			b[n - 1 - j][i] = temp[i][j];
}

bool autoPlay()
{
	if (popBlocks(findGroupKey()) == false)
		return false;

	applyGravity();
	turnCCW();
	applyGravity();
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int num;
			cin >> num;
			if (num == 0)
				b[i][j] = rainbow;
			else
				b[i][j] = num;
		}
	}

	while (autoPlay());

	cout << score;
}