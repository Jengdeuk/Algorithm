#include <iostream>
#include <string>
using namespace std;

int n;
char m[50][50];

void swapHor(int r, int c)
{
	int temp = m[r][c];
	m[r][c] = m[r][c + 1];
	m[r][c + 1] = temp;
}

void swapVer(int r, int c)
{
	int temp = m[r][c];
	m[r][c] = m[r + 1][c];
	m[r + 1][c] = temp;
}

int countCandy()
{
	int cnt = 0;

	char ch;
	int cur;
	for (int i = 0; i < n; ++i)
	{
		ch = '.';
		cur = 0;

		for (int j = 0; j < n; ++j)
		{
			if (m[i][j] != ch)
			{
				ch = m[i][j];
				cur = 0;
			}

			cnt = max(cnt, ++cur);
		}
	}

	for (int j = 0; j < n; ++j)
	{
		ch = '.';
		cur = 0;

		for (int i = 0; i < n; ++i)
		{
			if (m[i][j] != ch)
			{
				ch = m[i][j];
				cur = 0;
			}

			cnt = max(cnt, ++cur);
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		for (int j = 0; j < n; ++j)
			m[i][j] = s[j];
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j < n - 1)
			{
				swapHor(i, j);
				cnt = max(cnt, countCandy());
				swapHor(i, j);
			}

			if (i < n - 1)
			{
				swapVer(i, j);
				cnt = max(cnt, countCandy());
				swapVer(i, j);
			}
		}
	}

	cout << cnt;
}