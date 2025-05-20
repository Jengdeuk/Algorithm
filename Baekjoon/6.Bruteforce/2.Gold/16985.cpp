#include <iostream>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> p;

struct node
{
	node(int _step, int _h, int _r, int _c) : step(_step), h(_h), r(_r), c(_c) {}

	int step;
	int h;
	int r;
	int c;
};

const int n = 5;
const int inf = INT_MAX;

const int dx[6] = { -1, 0, 1, 0, 0, 0 };
const int dy[6] = { 0, -1, 0, 1, 0, 0 };
const int dz[6] = { 0, 0, 0, 0, -1, 1 };

bool fm[n][4][n][n], sk[n][4], wall[n][n][n];

p curBoard[n];
bool vstBoard[n];

int minStep;

bool IsValid(int h, int r, int c)
{
	return (h >= 0 && h < n && r >= 0 && r < n && c >= 0 && c < n && wall[h][r][c] == false);
}

int BFS()
{
	queue<node> q;
	bool v[n][n][n] = {};
	v[0][0][0] = true;
	q.emplace(0, 0, 0, 0);
	while (q.empty() == false)
	{
		int step = q.front().step;
		int h = q.front().h;
		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		if (h == n - 1 && r == n - 1 && c == n - 1)
		{
			return step;
		}

		for (int i = 0; i < 6; ++i)
		{
			int nh = h + dz[i];
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (IsValid(nh, nr, nc) && v[nh][nr][nc] == false)
			{
				v[nh][nr][nc] = true;
				q.emplace(step + 1, nh, nr, nc);
			}
		}
	}

	return -1;
}

void BruteForce(int idx)
{
	if (idx == n)
	{
		for (int h = 0; h < n; ++h)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					wall[h][i][j] = fm[curBoard[h].first][curBoard[h].second][i][j];

		if (wall[0][0][0])
		{
			return;
		}

		int step = BFS();
		if (step > -1)
		{
			minStep = min(minStep, step);
		}

		return;
	}

	for (int h = 0; h < n; ++h)
	{
		if (vstBoard[h])
		{
			continue;
		}

		vstBoard[h] = true;
		for (int i = 0; i < 4; ++i)
		{
			if (sk[h][i])
			{
				continue;
			}

			curBoard[idx] = pair(h, i);
			BruteForce(idx + 1);
		}
		vstBoard[h] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int h = 0; h < n; ++h)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				bool blank;
				cin >> blank;
				fm[h][0][i][j] = (blank == false);
			}
		}
	}

	for (int h = 0; h < n; ++h)
	{
		for (int d = 1; d < 4; ++d)
		{
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					fm[h][d][j][n - 1 - i] = fm[h][d - 1][i][j];

			bool isDiff = false;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (fm[h][d][i][j] != fm[h][0][i][j])
					{
						isDiff = true;
						i = n;
						break;
					}
				}
			}

			sk[h][d] = (isDiff == false);
		}
	}

	minStep = inf;
	BruteForce(0);
	if (minStep < inf)
		cout << minStep;
	else
		cout << -1;
}