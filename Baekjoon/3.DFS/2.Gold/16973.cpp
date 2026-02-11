#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m, h, w;
int map[1001][1001], sum[1001][1001];
bool vst[1001][1001];

const bool IsValid(int r, int c)
{
	return r >= 1 && r <= n && c >= 1 && c <= m
		&& r + h - 1 <= n && c + w - 1 <= m
		&& !vst[r][c];
}

const bool IsMovable(int r, int c)
{
	return sum[r + h - 1][c + w - 1] - sum[r - 1][c + w - 1] - sum[r + h - 1][c - 1] + sum[r - 1][c - 1] == 0;
}

int BFS(const int sr, const int sc, const int er, const int ec)
{
	queue<ip> q;
	vst[sr][sc] = true;
	q.emplace(0, p(sr, sc));
	while (!q.empty())
	{
		int step = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (r == er && c == ec)
		{
			return step;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (IsValid(nr, nc) && IsMovable(nr, nc))
			{
				vst[nr][nc] = true;
				q.emplace(step + 1, p(nr, nc));
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
			sum[i][j] = map[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}
	}

	int sr, sc, er, ec;
	cin >> h >> w >> sr >> sc >> er >> ec;
	cout << BFS(sr, sc, er, ec);
}