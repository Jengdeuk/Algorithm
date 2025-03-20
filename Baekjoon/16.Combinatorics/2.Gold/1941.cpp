#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int > p;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

char sit[5][5];
bool cur[25];
int sp;

bool isMoreThan4()
{
	int cnt = 0;
	for (int i = 0; i < 25; ++i)
		if (cur[i] && sit[i / 5][i % 5] == 'S')
			cnt++;

	return cnt >= 4;
}

bool isValid(int r, int c)
{
	return r >= 0 && r < 5 && c >= 0 && c < 5;
}

bool isAdj()
{
	int sr = 0, sc = 0;

	bool s[5][5] = {};
	for (int i = 0; i < 25; ++i)
	{
		if (cur[i])
		{
			s[i / 5][i % 5] = true;
			sr = i / 5;
			sc = i % 5;
		}
	}

	int cnt = 0;
	bool v[5][5] = {};
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
			if (isValid(nr, nc) && s[nr][nc] && v[nr][nc] == false)
			{
				v[nr][nc] = true;
				q.emplace(nr, nc);
			}
		}
	}

	return cnt == 7;
}

void bf(int cnt, int idx)
{
	if (cnt == 7)
	{
		if (isMoreThan4() && isAdj())
			sp++;

		return;
	}

	if (idx == 25)
		return;

	cur[idx] = true;
	bf(cnt + 1, idx + 1);

	cur[idx] = false;
	bf(cnt, idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 5; ++i)
	{
		string s;
		cin >> s;

		for (int j = 0; j < 5; ++j)
			sit[i][j] = s[j];
	}

	bf(0, 0);
	cout << sp;
}