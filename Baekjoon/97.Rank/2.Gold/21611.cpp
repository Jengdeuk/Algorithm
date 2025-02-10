#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int sdx[4] = { 0, 0, -1, 1 };
const int sdy[4] = { -1, 1, 0, 0 };

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, nn, t, sr, sc;

int index1D[49][49];
p index2D[2401];

int bead2D[49][49];
int bead1D[2401];

int destroyed[4];

void convert1DTo2D()
{
	for (int i = 1; i < nn; ++i)
		bead2D[index2D[i].first][index2D[i].second] = bead1D[i];
}

void convert2DTo1D()
{
	int idx = 0, step = 1, dir = 0;
	int r = sr, c = sc;

	queue<int> q;
	bool isFinished = false;
	while (isFinished == false)
	{
		for (int k = 0; k < 2; ++k)
		{
			for (int i = 0; i < step; ++i)
			{
				r += dy[dir];
				c += dx[dir];

				if (bead2D[r][c])
					q.emplace(bead2D[r][c]);

				if (r == 0 && c == 0)
				{
					isFinished = true;
					k = 2;
					i = step;
					break;
				}
			}

			++dir;
			if (dir > 3)
				dir = 0;
		}

		++step;
	}

	idx = 1;
	while (q.empty() == false && idx < nn)
	{
		bead1D[idx++] = q.front();
		q.pop();
	}

	while (idx < nn)
		bead1D[idx++] = 0;
}

void blizzard(int direction, int distance)
{
	convert1DTo2D();

	for (int i = 1; i <= distance; ++i)
	{
		int r = sr + sdy[direction] * i;
		int c = sc + sdx[direction] * i;
		bead2D[r][c] = 0;
	}

	convert2DTo1D();
}

bool isExplosionable()
{
	for (int i = 1; i < nn; ++i)
	{
		if (bead1D[i] == 0)
			return false;

		int cnt = 1;
		for (int j = i + 1; j < nn; ++j)
		{
			if (bead1D[i] != bead1D[j])
				break;

			++cnt;
		}

		if (cnt >= 4)
			return true;

		i += cnt - 1;
	}

	return false;
}

void explosion()
{
	queue<int> q;
	for (int i = 1; i < nn; ++i)
	{
		if (bead1D[i] == 0)
			break;

		int cnt = 1;
		for (int j = i + 1; j < nn; ++j)
		{
			if (bead1D[i] != bead1D[j])
				break;

			++cnt;
		}

		if (cnt >= 4)
		{
			destroyed[bead1D[i]] += cnt;
		}
		else
		{
			for (int k = 0; k < cnt; ++k)
				q.emplace(bead1D[i]);
		}

		i += cnt - 1;
	}

	int idx = 1;
	while (q.empty() == false && idx < nn)
	{
		bead1D[idx++] = q.front();
		q.pop();
	}

	while (idx < nn)
		bead1D[idx++] = 0;
}

void change()
{
	queue<int> q;
	for (int i = 1; i < nn; ++i)
	{
		if (bead1D[i] == 0)
			break;

		int cnt = 1;
		for (int j = i + 1; j < nn; ++j)
		{
			if (bead1D[i] != bead1D[j])
				break;

			++cnt;
		}

		q.emplace(cnt);
		q.emplace(bead1D[i]);

		i += cnt - 1;
	}

	int idx = 1;
	while (q.empty() == false && idx < nn)
	{
		bead1D[idx++] = q.front();
		q.pop();
	}

	while (idx < nn)
		bead1D[idx++] = 0;
}

void play()
{
	for (int i = 0; i < t; ++i)
	{
		int d, s;
		cin >> d >> s;
		blizzard(d - 1, s);
		while (isExplosionable())
			explosion();
		change();
	}

	int answer = 0;
	for (int i = 1; i <= 3; ++i)
		answer += i * destroyed[i];

	cout << answer;
}

void initialize()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> t;
	nn = n * n;
	sr = n / 2;
	sc = n / 2;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> bead2D[i][j];

	int idx = 0, step = 1, dir = 0;
	int r = sr, c = sc;

	bool isFinished = false;
	while (isFinished == false)
	{
		for (int k = 0; k < 2; ++k)
		{
			for (int i = 0; i < step; ++i)
			{
				r += dy[dir];
				c += dx[dir];
				index1D[r][c] = ++idx;
				index2D[idx] = p(r, c);
				bead1D[idx] = bead2D[r][c];
				if (r == 0 && c == 0)
				{
					isFinished = true;
					k = 2;
					i = step;
					break;
				}
			}

			++dir;
			if (dir > 3)
				dir = 0;
		}

		++step;
	}
}

int main()
{
	initialize();
	play();
}