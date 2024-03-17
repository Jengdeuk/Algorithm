#include <iostream>
#include <cstring>
using namespace std;

int N;
int Height[100][100];
int MinH = 101;
int MaxH = 0;
int MaxArea = 1;

bool Visited[100][100];
const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

void DFS(int H, int Row, int Col)
{
	Visited[Row][Col] = true;

	for (int i = 0; i < 4; ++i)
	{
		int NR = Row + DY[i];
		int NC = Col + DX[i];
		if (NR < 0 || NR > N - 1 || NC < 0 || NC > N - 1
			|| Height[NR][NC] <= H || Visited[NR][NC])
		{
			continue;
		}

		DFS(H, NR, NC);
	}
}

void Solve(int H)
{
	memset(Visited, false, sizeof(Visited));

	int Area = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Height[i][j] > H && !Visited[i][j])
			{
				DFS(H, i, j);
				++Area;
			}
		}
	}

	MaxArea = max(MaxArea, Area);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Height[i][j];
			MinH = min(MinH, Height[i][j]);
			MaxH = max(MaxH, Height[i][j]);
		}
	}

	for (int h = MinH; h < MaxH; ++h)
	{
		Solve(h);
	}

	cout << MaxArea;
}