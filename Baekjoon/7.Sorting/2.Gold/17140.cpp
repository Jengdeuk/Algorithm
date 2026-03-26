#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using p = pair<int, int>;
const int maxSize = 100;

int n, m;
int mat[maxSize][maxSize];

bool HasFinished(const int r, const int c, const int k);
void ProcessCalcRow();
void ProcessCalcCol();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int r, c, k;
	cin >> r >> c >> k;
	--r;
	--c;

	n = 3;
	m = 3;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
		}
	}

	int time = 0;
	while (!HasFinished(r, c, k))
	{
		if (n >= m)
		{
			ProcessCalcRow();
		}
		else
		{
			ProcessCalcCol();
		}

		if (++time > 100)
		{
			time = -1;
			break;
		}
	}

	cout << time;
}

bool HasFinished(const int r, const int c, const int k)
{
	return mat[r][c] == k;
}

void ProcessCalcRow()
{
	int newM = m;
	for (int i = 0; i < n; ++i)
	{
		int cnt[maxSize + 1]{};
		for (int j = 0; j < m; ++j)
		{
			++cnt[mat[i][j]];
		}

		vector<p> sorted;
		for (int num = 1; num <= maxSize; ++num)
		{
			if (cnt[num])
			{
				sorted.emplace_back(cnt[num], num);
			}
		}

		sort(sorted.begin(), sorted.end());

		int idx = 0;
		for (const p& item : sorted)
		{
			mat[i][idx] = item.second;
			mat[i][idx + 1] = item.first;
			idx += 2;
		}

		for (int j = idx; j < m; ++j)
		{
			mat[i][j] = 0;
		}

		newM = max(newM, static_cast<int>(sorted.size()) * 2);
	}

	m = newM;
}

void ProcessCalcCol()
{
	int newN = n;
	for (int j = 0; j < m; ++j)
	{
		int cnt[maxSize + 1]{};
		for (int i = 0; i < n; ++i)
		{
			++cnt[mat[i][j]];
		}

		vector<p> sorted;
		for (int num = 1; num <= maxSize; ++num)
		{
			if (cnt[num])
			{
				sorted.emplace_back(cnt[num], num);
			}
		}

		sort(sorted.begin(), sorted.end());

		int idx = 0;
		for (const p& item : sorted)
		{
			mat[idx][j] = item.second;
			mat[idx + 1][j] = item.first;
			idx += 2;
		}

		for (int i = idx; i < n; ++i)
		{
			mat[i][j] = 0;
		}

		newN = max(newN, static_cast<int>(sorted.size()) * 2);
	}

	n = newN;
}