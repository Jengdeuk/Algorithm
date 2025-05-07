#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, p> pp;
typedef pair<int, p> ip;
typedef ip edge;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, k, root[251];
bool w[50][50];
vector<p> nodes;
vector<edge> edges;

int fnd(int a)
{
	if (root[a] == a)
		return a;
	return root[a] = fnd(root[a]);
}

void uni(int a, int b)
{
	root[fnd(a)] = fnd(b);
}

bool isValid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < n && w[r][c] == false;
}

void initialize()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char ch;
			cin >> ch;
			switch (ch)
			{
			case 'S':
			case 'K':
			{
				int node = nodes.size();
				root[node] = node;
				nodes.emplace_back(i, j);
			}
			break;
			case '1':
				w[i][j] = true;
				break;
			}
		}
	}
}

int bfs(p src, p dst)
{
	queue<ip> q;
	bool v[50][50] = {};
	v[src.first][src.second] = true;
	q.emplace(0, src);
	while (q.empty() == false)
	{
		int t = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (r == dst.first && c == dst.second)
			return t;

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc) && v[nr][nc] == false)
			{
				v[nr][nc] = true;
				q.emplace(t + 1, p(nr, nc));
			}
		}
	}

	return -1;
}

void makeEdges()
{
	int ns = nodes.size();
	for (int i = 0; i < ns - 1; ++i)
	{
		for (int j = i + 1; j < ns; ++j)
		{
			int dst = bfs(nodes[i], nodes[j]);
			if (dst > 0)
				edges.emplace_back(dst, p(i, j));
		}
	}
}

int kruskal()
{
	sort(edges.begin(), edges.end());

	int cnt = 0, sum = 0;
	bool isRepeat = true;
	while (cnt < k && isRepeat)
	{
		isRepeat = false;
		for (const edge& e : edges)
		{
			int cst = e.first;
			int src = e.second.first;
			int dst = e.second.second;
			if (fnd(src) == fnd(dst))
				continue;

			isRepeat = true;
			uni(src, dst);
			cnt++;
			sum += cst;
			break;
		}
	}

	if (cnt != k)
		return -1;

	return sum;
}

int main()
{
	initialize();
	makeEdges();
	cout << kruskal();
}