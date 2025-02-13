#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m, k;
bool t[100][100], v[100][100];

bool isValid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < m);
}

int dfs(int sr, int sc)
{
	int trash = 0;

	queue<p> q;
	v[sr][sc] = true;
	q.emplace(sr, sc);
	while (q.empty() == false)
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		++trash;

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc) && t[nr][nc] && v[nr][nc] == false)
			{
				v[nr][nc] = true;
				q.emplace(nr, nc);
			}
		}
	}

	return trash;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i)
	{
		int r, c;
		cin >> r >> c;
		t[r - 1][c - 1] = true;
	}

	int maxTrash = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (t[i][j] && v[i][j] == false)
				maxTrash = max(maxTrash, dfs(i, j));

	cout << maxTrash;
}