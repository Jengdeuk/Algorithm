#include <iostream>
#include <queue>
using namespace std;

using p = pair<int, int>;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

const int ms = 1000;

int n, m;
bool w[ms][ms];
int d[ms][ms];

bool IsValid(const int r, const int c)
{
	return r >= 0 && r < n && c >= 0 && c < m && d[r][c] == -1;
}

void BFS(const int sr, const int sc)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!w[i][j])
			{
				d[i][j] = -1;
			}
		}
	}

	queue<p> q;
	q.emplace(sr, sc);
	d[sr][sc] = 0;
	while (!q.empty())
	{
		const int r = q.front().first;
		const int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			const int nr = r + dy[i];
			const int nc = c + dx[i];
			if (IsValid(nr, nc))
			{
				q.emplace(nr, nc);
				d[nr][nc] = d[r][c] + 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;

	int sr = 0, sc = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int num;
			cin >> num;
			switch (num)
			{
			case 2:
				sr = i;
				sc = j;
				break;
			case 0:
				w[i][j] = true;
				break;
			default:
				break;
			}
		}
	}

	BFS(sr, sc);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
}