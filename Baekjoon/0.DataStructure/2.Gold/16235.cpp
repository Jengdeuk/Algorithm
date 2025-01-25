#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> tree;

const int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int n, m, k;
int add[10][10], current[10][10];
deque<int> trees[10][10];
queue<tree> deads, bigTrees;

bool isValid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < n);
}

void spring()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			deque<int> temp;
			while (trees[i][j].empty() == false)
			{
				int y = trees[i][j].front();
				trees[i][j].pop_front();

				if (current[i][j] >= y)
				{
					current[i][j] -= y;
					temp.emplace_back(y + 1);
					if ((y + 1) % 5 == 0)
						bigTrees.emplace(y + 1, p(i, j));
				}
				else
				{
					deads.emplace(y, p(i, j));
				}
			}

			trees[i][j] = temp;
		}
	}
}

void summer()
{
	while (deads.empty() == false)
	{
		int y = deads.front().first;
		int r = deads.front().second.first;
		int c = deads.front().second.second;
		deads.pop();

		current[r][c] += y / 2;
	}
}

void fall()
{
	while (bigTrees.empty() == false)
	{
		int y = bigTrees.front().first;
		int r = bigTrees.front().second.first;
		int c = bigTrees.front().second.second;
		bigTrees.pop();

		for (int i = 0; i < 8; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc))
				trees[nr][nc].emplace_front(1);
		}
	}
}

void winter()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			current[i][j] += add[i][j];
}

void initialize()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			current[i][j] = 5;
			cin >> add[i][j];
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int r, c, y;
		cin >> r >> c >> y;
		trees[r - 1][c - 1].emplace_back(y);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			sort(trees[i][j].begin(), trees[i][j].end());
		}
	}
}

int countTrees()
{
	int countNum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			countNum += trees[i][j].size();
		}
	}

	return countNum;
}

int main()
{
	initialize();

	int t = 0;
	while (t < k)
	{
		spring();
		summer();
		fall();
		winter();

		++t;
	}

	cout << countTrees();
}