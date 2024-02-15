#include <iostream>
#include <queue>
using namespace std;

int N, M;
int Map[1000][1000];
int Distance[1000][1000];
queue<pair<int, int>> SearchQueue;

void BFS(int StartRow, int StartCol)
{
	SearchQueue.emplace(StartRow, StartCol);

	while (!SearchQueue.empty())
	{
		int CurRow = SearchQueue.front().first;
		int CurCol = SearchQueue.front().second;
		SearchQueue.pop();

		if (Map[CurRow][CurCol] == 0)
		{
			continue;
		}

		int CurDistance = Distance[CurRow][CurCol];
		Map[CurRow][CurCol] = 0;

		// Left
		if (CurCol > 0
			&& Map[CurRow][CurCol - 1] != 0)
		{
			Distance[CurRow][CurCol - 1] = CurDistance + 1;
			SearchQueue.emplace(CurRow, CurCol - 1);
		}

		// Top
		if (CurRow > 0
			&& Map[CurRow - 1][CurCol] != 0)
		{
			Distance[CurRow - 1][CurCol] = CurDistance + 1;
			SearchQueue.emplace(CurRow - 1, CurCol);
		}

		// Right
		if (CurCol < M - 1
			&& Map[CurRow][CurCol + 1] != 0)
		{
			Distance[CurRow][CurCol + 1] = CurDistance + 1;
			SearchQueue.emplace(CurRow, CurCol + 1);
		}

		// Bottom
		if (CurRow < N - 1
			&& Map[CurRow + 1][CurCol] != 0)
		{
			Distance[CurRow + 1][CurCol] = CurDistance + 1;
			SearchQueue.emplace(CurRow + 1, CurCol);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int StartRow = 0, StartCol = 0;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Map[i][j];

			if (Map[i][j] == 2)
			{
				StartRow = i;
				StartCol = j;
			}
		}
	}

	BFS(StartRow, StartCol);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] == 1)
			{
				cout << -1 << ' ';
			}
			else
			{
				cout << Distance[i][j] << ' ';
			}
		}
		cout << '\n';
	}
}