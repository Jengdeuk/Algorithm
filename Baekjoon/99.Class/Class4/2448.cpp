#include <iostream>
using namespace std;

char Board[3072][6143];

void DrawTriangle(int N, int Row, int Col)
{
	if (N == 3)
	{
		for (int i = 0; i < N; ++i)
		{
			Board[Row + i][Col - i] = '*';
			Board[Row + i][Col + i] = '*';
		}

		for (int i = 0; i < 2; ++i)
		{
			Board[Row + N - 1][Col - i] = '*';
			Board[Row + N - 1][Col + i] = '*';
		}

		return;
	}

	DrawTriangle(N / 2, Row, Col);
	DrawTriangle(N / 2, Row + N / 2, Col - N / 2);
	DrawTriangle(N / 2, Row + N / 2, Col + N / 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 2 * N - 1; ++j)
		{
			Board[i][j] = ' ';
		}
	}

	DrawTriangle(N, 0, N - 1);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 2 * N - 1; ++j)
		{
			cout << Board[i][j];
		}
		cout << '\n';
	}
}