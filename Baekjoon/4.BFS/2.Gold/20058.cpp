#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, a[1 << 6][1 << 6], b[1 << 6][1 << 6];
bool v[1 << 6][1 << 6];

void storm(int l)
{
	memcpy(b, a, sizeof(b));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[(i / l) * l + j % l][(j / l) * l + l - 1 - i % l] = b[i][j];
}

bool isValid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < n;
}

void melt()
{
	queue<p> q;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int cnt = 0;
			for (int k = 0; k < 4; ++k)
			{
				int nr = i + dy[k];
				int nc = j + dx[k];
				if (isValid(nr, nc) == false || a[nr][nc] == 0)
					cnt++;
			}

			if (cnt >= 2 && a[i][j] > 0)
				q.emplace(i, j);
		}
	}

	while (q.empty() == false)
	{
		a[q.front().first][q.front().second]--;
		q.pop();
	}
}

int dfs(int sr, int sc)
{
	int cnt = 0;

	queue<p> q;
	v[sr][sc] = true;
	q.emplace(sr, sc);
	while (q.empty() == false)
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		cnt++;
		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc) && v[nr][nc] == false && a[nr][nc] > 0)
			{
				v[nr][nc] = true;
				q.emplace(nr, nc);
			}
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	n = (1 << n);

	int q;
	cin >> q;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	while (q--)
	{
		int l;
		cin >> l;
		storm(1 << l);
		melt();
	}
	
	int sum = 0, mcnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			sum += a[i][j];
			if (v[i][j] == false && a[i][j] > 0)
				mcnt = max(mcnt, dfs(i, j));
		}
	}

	cout << sum << '\n' << mcnt;
}