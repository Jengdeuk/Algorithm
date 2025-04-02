#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m, h[50][50];
bool never[50][50], vst[50][50];

int cnt;

bool isValid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}

void nbfs(int sr, int sc)
{
	queue<p> q;
	never[sr][sc] = true;
	q.emplace(sr, sc);
	while (q.empty() == false)
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc) && h[nr][nc] == h[r][c] && never[nr][nc] == false)
			{
				never[nr][nc] = true;
				q.emplace(nr, nc);
			}
		}
	}
}

void initialize()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j)
			h[i][j] = s[j] - '0';
	}

	for (int i = 0; i < n; ++i)
		if (never[i][0] == false)
			nbfs(i, 0);

	for (int i = 0; i < n; ++i)
		if (never[i][m - 1] == false)
			nbfs(i, m - 1);

	for (int j = 0; j < m; ++j)
		if (never[0][j] == false)
			nbfs(0, j);

	for (int j = 0; j < m; ++j)
		if (never[n - 1][j] == false)
			nbfs(n - 1, j);
}

bool bfs(int sr, int sc)
{
	bool isHigher = false;
	int curHeight = h[sr][sc];
	int nxtHeight = 10;

	queue<p> q, nq;
	vst[sr][sc] = true;
	q.emplace(sr, sc);
	nq.emplace(sr, sc);
	while (q.empty() == false)
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc))
			{
				if (never[nr][nc] == false && h[nr][nc] == curHeight && vst[nr][nc] == false)
				{
					vst[nr][nc] = true;
					q.emplace(nr, nc);
					nq.emplace(nr, nc);
				}
				else if (h[nr][nc] > curHeight)
				{
					nxtHeight = min(nxtHeight, h[nr][nc]);
				}
				else if (h[nr][nc] < curHeight || never[nr][nc])
				{
					isHigher = true;
				}
			}
		}
	}

	if (nxtHeight == 10)
		isHigher = true;

	if (isHigher == false)
	{
		int filled = nxtHeight - curHeight;
		while (nq.empty() == false)
		{
			h[nq.front().first][nq.front().second] = nxtHeight;
			nq.pop();
			cnt += filled;
		}
	}
	
	return isHigher == false;
}

bool fillWater()
{
	bool isFilled = false;

	memset(vst, false, sizeof(vst));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (never[i][j] || vst[i][j])
				continue;

			if (bfs(i, j))
			{
				isFilled = true;
				i = n;
				break;
			}
		}
	}

	return isFilled;
}

int main()
{
	initialize();
	while (fillWater());
	cout << cnt;
}