#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int Map[1000][1000];
bool Visited[1000][1000];
const int DX1[6] = { -1, -1, -1, 0, 1, 0 };
const int DX2[6] = { 0, -1, 0, 1, 1, 1 };
const int DY[6] = { -1, 0, 1, -1, 0, 1 };
queue<pair<int, int>> SQ;

void CheckNeighbor(int Row, int Col, int NRow, int NCol)
{
	if (NRow < 0 || NCol < 0 || NRow >= N || NCol >= M
		|| Map[NRow][NCol] == -1 || Visited[NRow][NCol])
	{
		return;
	}

	int CurDistance = Map[NRow][NCol];

	if (CurDistance == 0)
	{
		Map[NRow][NCol] = Map[Row][Col] + 1;
	}
	else
	{
		Map[NRow][NCol] = min(CurDistance, Map[Row][Col] + 1);
	}

	SQ.emplace(NRow, NCol);
}

void BFS(int SRow, int SCol)
{
	SQ.emplace(SRow, SCol);

	while (!SQ.empty())
	{
		int Row = SQ.front().first;
		int Col = SQ.front().second;
		SQ.pop();

		if (Visited[Row][Col])
		{
			continue;
		}

		Visited[Row][Col] = true;
		for (int i = 0; i < 6; ++i)
		{
			int NRow = Row + DY[i];
			int NCol;
			if (Row % 2 == 0)
			{
				NCol = Col + DX1[i];
			}
			else
			{
				NCol = Col + DX2[i];
			}

			CheckNeighbor(Row, Col, NRow, NCol);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		int Row, Col;
		cin >> Row >> Col;
		Map[Row][Col] = -1;
	}

	BFS(0, 0);

	if (Map[N - 1][M - 1] != 0)
	{
		cout << Map[N - 1][M - 1];
	}
	else
	{
		cout << -1;
	}
}