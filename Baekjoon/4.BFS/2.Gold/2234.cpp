#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m, w[50][50], rn[50][50];
vector<int> rs;

int adj[2500][2500] = {};
bool v[50][50] = {};

void bfs(int sr, int sc)
{
	int rnum = rs.size() + 1;
	int rsize = 0;

	queue<p> q;
	rn[sr][sc] = rnum;
	q.emplace(sr, sc);
	while (q.empty() == false)
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		rsize++;
		for (int i = 0; i < 4; ++i)
		{
			if ((w[r][c] & (1 << i)) == 0)
			{
				int nr = r + dy[i];
				int nc = c + dx[i];
				if (rn[nr][nc] == 0)
				{
					rn[nr][nc] = rnum;
					q.emplace(nr, nc);
				}
			}
		}
	}

	rs.emplace_back(rsize);
}

bool isValid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}

int q3()
{
	queue<p> q;
	v[0][0] = true;
	q.emplace(0, 0);
	while (q.empty() == false)
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc) && v[nr][nc] == false)
			{
				v[nr][nc] = true;
				q.emplace(nr, nc);

				int ra = rn[r][c];
				int rb = rn[nr][nc];
				if (ra-- != rb--)
					adj[ra][rb] = adj[rb][ra] = max(adj[ra][rb], rs[ra] + rs[rb]);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < rs.size(); ++i)
		for (int j = i + 1; j < rs.size(); ++j)
			answer = max(answer, adj[i][j]);
	
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> m >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> w[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (rn[i][j] == 0)
				bfs(i, j);

	cout << rs.size() << '\n';
	cout << *max_element(rs.begin(), rs.end()) << '\n';
	cout << q3();
}