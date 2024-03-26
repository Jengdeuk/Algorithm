#include <iostream>
using namespace std;

bool Paper[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int X, Y;
		cin >> X >> Y;
		for (int y = Y; y < Y + 10; ++y)
		{
			for (int x = X; x < X + 10; ++x)
			{
				Paper[y][x] = true;
			}
		}
	}

	int Cnt = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (Paper[i][j])
			{
				++Cnt;
			}
		}
	}

	cout << Cnt;
}