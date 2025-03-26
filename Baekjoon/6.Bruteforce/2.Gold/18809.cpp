#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, p> pp;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m, gn, rn;
p org[50][50], map[50][50];

vector<p> eg;
int egn, curEg[10];

int maxFlower;

bool isValid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}

int dfs()
{
	memcpy(map, org, sizeof(map));

	queue<pp> q;
	for (int i = 0; i < egn; ++i)
	{
		if (curEg[i] > 0)
		{
			map[eg[i].first][eg[i].second] = p(0, 2 + curEg[i]);
			q.emplace(p(0, 2 + curEg[i]), eg[i]);
		}
	}

	while (q.empty() == false)
	{
		int time = q.front().first.first;
		int color = q.front().first.second;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (map[r][c].second == 5)
			continue;

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc))
			{
				switch (map[nr][nc].second)
				{
				case 1:
				case 2:
					map[nr][nc] = p(time + 1, color);
					q.emplace(p(time + 1, color), p(nr, nc));
					break;

				case 3:
				case 4:
					if (map[nr][nc].second != color && map[nr][nc].first == time + 1)
						map[nr][nc] = p(time + 1, 5);
					break;
				}
			}
		}
	}

	int flower = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (map[i][j].second == 5)
				flower++;

	return flower;
}

bool isCorrectCase()
{
	int g = 0, r = 0;
	for (int i = 0; i < egn; ++i)
	{
		switch (curEg[i])
		{
		case 1:
			g++;
			break;
		case 2:
			r++;
			break;
		}
	}

	return g == gn && r == rn;
}

void func(int idx)
{
	if (idx == egn)
	{
		if (isCorrectCase())
			maxFlower = max(maxFlower, dfs());

		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		curEg[idx] = i;
		func(idx + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> gn >> rn;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int num;
			cin >> num;
			org[i][j] = p(0, num);
			if (num == 2)
				eg.emplace_back(i, j);
		}
	}

	egn = eg.size();

	func(0);

	cout << maxFlower;
}