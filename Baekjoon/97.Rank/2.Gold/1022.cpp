#include <iostream>
#include <string>
using namespace std;

const int n = 5000;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int m[50][5];
int r1, c1, r2, c2;

bool IsValid(int r, int c)
{
	return (r >= r1 && r <= r2 && c >= c1 && c <= c2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> r1 >> c1 >> r2 >> c2;

	int num = 1, step = 1, dir = 0;
	int r = 0, c = 0;
	int big = 0;
	if (IsValid(r, c))
	{
		m[r - r1][c - c1] = num;
		big = max(big, num);
	}
	
	while ((r == n && c == n) == false)
	{
		for (int k = 0; k < 2; ++k)
		{
			for (int i = 0; i < step; ++i)
			{
				if (r == n && c == n)
				{
					break;
				}

				num++;
				r += dy[dir];
				c += dx[dir];
				if (IsValid(r, c))
				{
					m[r - r1][c - c1] = num;
					big = max(big, num);
				}
			}

			dir = (dir + 1 > 3 ? 0 : dir + 1);
		}

		step++;
	}

	string sb = to_string(big);
	int l = sb.size();
	for (int i = 0; i <= r2 - r1; ++i)
	{
		for (int j = 0; j <= c2 - c1; ++j)
		{
			cout.width(l);
			cout << std::right << m[i][j] << ' ';
		}
		cout << '\n';
	}
}