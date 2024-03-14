#include <iostream>
#include <queue>
using namespace std;

int R, C, T;
int Dust[50][50];
int Air2;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

void Spread()
{
	queue<pair<pair<int, int>, int>> DQ;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (Dust[i][j] > 0)
			{
				DQ.emplace(pair<int, int>(i, j), Dust[i][j]);
			}
		}
	}

	while (!DQ.empty())
	{
		int Amount = DQ.front().second;
		int Row = DQ.front().first.first;
		int Col = DQ.front().first.second;
		DQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NR = Row + DY[i];
			int NC = Col + DX[i];
			if (NR < 0 || NR > R - 1
				|| NC < 0 || NC > C - 1
				|| Dust[NR][NC] == -1)
			{
				continue;
			}

			Dust[Row][Col] -= Amount / 5;
			Dust[NR][NC] += Amount / 5;
		}
	}
}

void Blow()
{
	int Air1 = Air2 - 1;

	// L
	for (int i = Air1 - 2; i >= 0; --i)
	{
		Dust[i + 1][0] = Dust[i][0];
	}
	for (int i = Air2 + 2; i < R; ++i)
	{
		Dust[i - 1][0] = Dust[i][0];
	}

	// T, B
	for (int i = 1; i < C; ++i)
	{
		Dust[0][i - 1] = Dust[0][i];
		Dust[R - 1][i - 1] = Dust[R - 1][i];
	}

	// R
	for (int i = 1; i <= Air1; ++i)
	{
		Dust[i - 1][C - 1] = Dust[i][C - 1];
	}
	for (int i = R - 2; i >= Air2; --i)
	{
		Dust[i + 1][C - 1] = Dust[i][C - 1];
	}

	// B, T
	for (int i = C - 2; i >= 1; --i)
	{
		Dust[Air1][i + 1] = Dust[Air1][i];
		Dust[Air2][i + 1] = Dust[Air2][i];
	}

	Dust[Air1][1] = 0;
	Dust[Air2][1] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> R >> C >> T;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> Dust[i][j];
			if (Dust[i][j] == -1)
			{
				Air2 = i;
			}
		}
	}

	for (int i = 1; i <= T; ++i)
	{
		Spread();
		Blow();
	}

	int Cnt = 0;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (Dust[i][j] > 0)
			{
				Cnt += Dust[i][j];
			}
		}
	}

	cout << Cnt;
}