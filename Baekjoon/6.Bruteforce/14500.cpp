#include <iostream>
using namespace std;

int N, M;
int Paper[500][500];

const int Tetromino[19][3][2] =
{
	{ { 1, 0 }, { 2, 0 }, { 3, 0 } },		// 1-1
	{ { 0, 1 }, { 0, 2 }, { 0, 3 } },		// 1-2
	{ { 1, 0 }, { 0, 1 }, { 1, 1 } },		// 2
	{ { 1, 0 }, { 2, 0 }, { 2, -1 } },		// 3-1
	{ { 1, 0 }, { 2, 0 }, { 2, 1 } },		// 3-2
	{ { 0, 1 }, { 0, 2 }, { -1, 2 } },		// 3-3
	{ { 0, 1 }, { 0, 2 }, { 1, 2 } },		// 3-4
	{ { 0, -1 }, { 1, -1 }, { 2, -1 } },	// 3-5
	{ { 0, 1 }, { 1, 1 }, { 2, 1 } },		// 3-6
	{ { -1, 0 }, { -1, 1 }, { -1, 2 } },	// 3-7
	{ { 1, 0 }, { 1, 1 }, { 1, 2 } },		// 3-8
	{ { 1, 0 }, { 1, -1 }, { 2, -1 } },		// 4-1
	{ { 1, 0 }, { 1, 1 }, { 2, 1 } },		// 4-2
	{ { 0, 1 }, { -1, 1 }, { -1, 2 } },		// 4-3
	{ { 0, 1 }, { 1, 1 }, { 1, 2 } },		// 4-4
	{ { 0, 1 }, { -1, 0 }, { 0, -1 } },		// 5-1
	{ { -1, 0 }, { 0, -1 }, { 1, 0 } },		// 5-2
	{ { 0, -1 }, { 1, 0 }, { 0, 1 } },		// 5-3
	{ { 1, 0 }, { 0, 1 }, { -1, 0 } },		// 5-4
};

int SearchTetromino(int X, int Y)
{
	int Max = 0;

	for (int i = 0; i < 19; ++i)
	{
		int X1 = X + Tetromino[i][0][0];
		int Y1 = Y + Tetromino[i][0][1];

		int X2 = X + Tetromino[i][1][0];
		int Y2 = Y + Tetromino[i][1][1];

		int X3 = X + Tetromino[i][2][0];
		int Y3 = Y + Tetromino[i][2][1];

		if (X1 < 0 || X1 > M - 1
			|| X2 < 0 || X2 > M - 1
			|| X3 < 0 || X3 > M - 1
			|| Y1 < 0 || Y1 > N - 1
			|| Y2 < 0 || Y2 > N - 1
			|| Y3 < 0 || Y3 > N - 1)
		{
			continue;
		}

		int Sum = Paper[Y][X] + Paper[Y1][X1] + Paper[Y2][X2] + Paper[Y3][X3];
		Max = max(Max, Sum);
	}

	return Max;
}

int Bruteforce()
{
	int Max = 0;

	for (int Y = 0; Y < N; ++Y)
	{
		for (int X = 0; X < M; ++X)
		{
			Max = max(Max, SearchTetromino(X, Y));
		}
	}

	return Max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Paper[i][j];
		}
	}

	cout << Bruteforce();
}