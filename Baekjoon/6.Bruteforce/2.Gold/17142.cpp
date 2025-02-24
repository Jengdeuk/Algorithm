#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;

const int wrongTime = 100000;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m, v;
p virus[10];
bool wall[50][50], vpos[50][50], active[10];
int minTime = wrongTime;

bool isValid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < n);
}

int dfs()
{
	int time = 0;

	queue<ip> q;
	bool visit[50][50] = {};
	for (int i = 0; i < v; ++i)
	{
		if (active[i])
		{
			int r = virus[i].first;
			int c = virus[i].second;
			visit[r][c] = true;
			q.emplace(0, p(r, c));
		}
	}

	while (q.empty() == false)
	{
		int t = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (vpos[r][c] == false)
			time = max(time, t);

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc) && wall[nr][nc] == false && visit[nr][nc] == false)
			{
				visit[nr][nc] = true;
				q.emplace(t + 1, p(nr, nc));
			}
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (wall[i][j] == false && vpos[i][j] == false && visit[i][j] == false)
				return wrongTime;

	return time;
}

void bruteForce(int take, int cur)
{
	if (take == m || cur == v)
	{
		minTime = min(minTime, dfs());
		return;
	}

	active[cur] = true;
	bruteForce(take + 1, cur + 1);
	active[cur] = false;
	bruteForce(take, cur + 1);
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
			switch (num)
			{
			case 1:
				wall[i][j] = true;
				break;
			case 2:
				vpos[i][j] = true;
				virus[v++] = p(i, j);
				break;
			}
		}
	}

	bruteForce(0, 0);
	if (minTime == wrongTime)
		minTime = -1;
	
	cout << minTime;
}