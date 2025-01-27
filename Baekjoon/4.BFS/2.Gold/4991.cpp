#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, p> pp;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m, k, sr, sc;
bool v[(1 << 9) + 1][20][20], w[20][20], t[20][20];
int ti[20][20];

bool isValid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < m);
}

int getStartBit()
{
	int bit = 0;
	for (int i = 0; i < k; ++i)
	{
		bit |= (1 << i);
	}

	return bit;
}

int BFS()
{
	queue<pp> q;
	int sbit = getStartBit();
	v[sbit][sr][sc] = true;
	q.emplace(p(sbit, 0), p(sr, sc));
	while (q.empty() == false)
	{
		int bit = q.front().first.first;
		int step = q.front().first.second;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (bit == 0)
			return step;

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (isValid(nr, nc) == false)
				continue;

			int nbit = bit;
			if (t[nr][nc])
				nbit &= ~(1 << ti[nr][nc]);

			if (w[nr][nc] || v[nbit][nr][nc])
				continue;

			v[nbit][nr][nc] = true;
			q.emplace(p(nbit, step + 1), p(nr, nc));
		}
	}

	return -1;
}

bool initialize()
{
	cin >> m >> n;
	if (n == 0 && m == 0)
		return false;

	memset(v, false, sizeof(v));
	memset(w, false, sizeof(w));
	memset(t, false, sizeof(t));

	k = 0, sr = 0, sc = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char ch;
			cin >> ch;
			switch (ch)
			{
			case 'o':
				sr = i;
				sc = j;
				break;
			case 'x':
				w[i][j] = true;
				break;
			case '*':
				t[i][j] = true;
				ti[i][j] = k++;
				break;
			}
		}
	}

	return true;
}

bool simulation()
{
	if (initialize() == false)
		return false;

	cout << BFS() << '\n';
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (simulation()) {}
}