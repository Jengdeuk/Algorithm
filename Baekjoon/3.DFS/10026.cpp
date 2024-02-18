#include <iostream>
using namespace std;

int N;
char Color[100][100];
bool Visited[100][100];
bool Visited2[100][100];

int DX[4] = { -1, 0, 1, 0 };
int DY[4] = { 0, -1, 0, 1 };

void DFS(int X, int Y)
{
	Visited[Y][X] = true;

	for (int i = 0; i < 4; ++i)
	{
		int NX = X + DX[i];
		int NY = Y + DY[i];

		if (NX < 0 || NX > N - 1
			|| NY < 0 || NY > N - 1
			|| Visited[NY][NX]
			|| Color[NY][NX] != Color[Y][X])
		{
			continue;
		}

		DFS(NX, NY);
	}
}

void DFS2(int X, int Y)
{
	Visited2[Y][X] = true;

	for (int i = 0; i < 4; ++i)
	{
		int NX = X + DX[i];
		int NY = Y + DY[i];

		if (NX < 0 || NX > N - 1
			|| NY < 0 || NY > N - 1
			|| Visited2[NY][NX]
			|| (Color[NY][NX] == 'R' && Color[Y][X] == 'B')
			|| (Color[NY][NX] == 'G' && Color[Y][X] == 'B')
			|| (Color[NY][NX] == 'B' && Color[Y][X] == 'R')
			|| (Color[NY][NX] == 'B' && Color[Y][X] == 'G'))
		{
			continue;
		}

		DFS2(NX, NY);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Color[i][j];
		}
	}

	int Count = 0, Count2 = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!Visited[i][j])
			{
				DFS(j, i);
				++Count;
			}
			if (!Visited2[i][j])
			{
				DFS2(j, i);
				++Count2;
			}
		}
	}

	cout << Count << ' ' << Count2;
}