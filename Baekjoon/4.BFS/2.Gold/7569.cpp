#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> Coord;

int Box[100][100][100];
int Day[100][100][100];

int M, N, H;
int DX[6] = { -1, 1, 0, 0, 0, 0 }; // Left, Right
int DY[6] = { 0, 0, -1, 1, 0, 0 }; // Top, Bottom
int DZ[6] = { 0, 0, 0, 0, -1, 1 }; // Down, Up

queue<Coord> SearchQueue;

int CountDays()
{
	int MaxDay = 0;
	
	// Binary First Search
	while (!SearchQueue.empty())
	{
		int X = get<0>(SearchQueue.front());
		int Y = get<1>(SearchQueue.front());
		int Z = get<2>(SearchQueue.front());
		SearchQueue.pop();

		if (Box[Z][Y][X] == -1)
		{
			continue;
		}

		Box[Z][Y][X] = -1;
		for (int i = 0; i < 6; ++i)
		{
			int NX = X + DX[i];
			int NY = Y + DY[i];
			int NZ = Z + DZ[i];

			if (NX < 0 || NX > M - 1
				|| NY < 0 || NY > N - 1
				|| NZ < 0 || NZ > H - 1
				|| Box[NZ][NY][NX] == -1)
			{
				continue;
			}

			if (Box[NZ][NY][NX] == 0)
			{
				Box[NZ][NY][NX] = 1;

				int NewDay = Day[Z][Y][X] + 1;
				Day[NZ][NY][NX] = NewDay;
				if (NewDay > MaxDay)
				{
					MaxDay = NewDay;
				}
			}

			SearchQueue.emplace(NX, NY, NZ);
		}
	}

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (Box[i][j][k] == 0)
				{
					return -1;
				}
			}
		}
	}

	return MaxDay;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N >> H;

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				cin >> Box[i][j][k];
				if (Box[i][j][k] == 1)
				{
					SearchQueue.emplace(k, j, i);
				}
			}
		}
	}

	cout << CountDays();
}