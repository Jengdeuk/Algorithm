#include <iostream>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int n, m[999][999];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int k;
	cin >> n >> k;

	int num = 1;
	int r = n / 2, c = n / 2;
	m[r][c] = num;

	int dir = 0, step = 1;
	bool isFinished = false;
	while (isFinished == false)
	{
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < step; ++j)
			{
				r += dy[dir];
				c += dx[dir];
				m[r][c] = ++num;

				if (r == 0 && c == 0)
				{
					isFinished = true;
					i = 3;
					break;
				}
			}

			dir = (dir + 1 > 3 ? 0 : dir + 1);
		}

		step++;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << m[i][j] << ' ';
			if (m[i][j] == k)
			{
				r = i;
				c = j;
			}
		}

		cout << '\n';
	}

	cout << r + 1 << ' ' << c + 1;
}