#include <iostream>
using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;
bool v[100][100];

bool isValid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < m && v[r][c] == false);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;

	int r = 0, c = 0, d = 0, cnt = 0;
	v[r][c] = true;
	while (isValid(r + dy[d], c + dx[d]))
	{
		while (isValid(r + dy[d], c + dx[d]))
		{
			r += dy[d];
			c += dx[d];
			v[r][c] = true;
		}
		++d;
		if (d > 3)
			d = 0;
		if (isValid(r + dy[d], c + dx[d]))
			++cnt;
	}

	cout << cnt;
}