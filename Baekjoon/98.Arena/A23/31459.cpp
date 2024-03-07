#include <iostream>
#include <cstring>
using namespace std;

bool Board[50][50];

void Test()
{
	int X, Y, x, y;
	cin >> X >> Y >> x >> y;

	memset(Board, false, sizeof(Board));

	int Cnt = 0;
	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			if (j - x >= 0 && i - y >= 0
				&& Board[i - y][j - x])
			{
				continue;
			}

			Board[i][j] = true;
			++Cnt;
		}
	}

	cout << Cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}