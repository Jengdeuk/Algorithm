#include <iostream>
#include <queue>
using namespace std;

char Map[600][600];
queue<pair<int, int>> SearchQueue;

int N, M;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int BFS(int StartX, int StartY)
{
	int Count = 0;

	SearchQueue.emplace(StartX, StartY);

	while (!SearchQueue.empty())
	{
		int CurrentX = SearchQueue.front().first;
		int CurrentY = SearchQueue.front().second;
		SearchQueue.pop();

		if (Map[CurrentY][CurrentX] == 'X')
		{
			continue;
		}

		if (Map[CurrentY][CurrentX] == 'P')
		{
			++Count;
		}

		Map[CurrentY][CurrentX] = 'X';
		for (int i = 0; i < 4; ++i)
		{
			int X = CurrentX + DX[i];
			int Y = CurrentY + DY[i];

			if (X < 0 || X > M - 1
				|| Y < 0 || Y > N - 1
				|| Map[Y][X] == 'X')
			{
				continue;
			}

			SearchQueue.emplace(X, Y);
		}
	}

	return Count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int StartX = 0, StartY = 0;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 'I')
			{
				StartX = j;
				StartY = i;
			}
		}
	}

	int Answer = BFS(StartX, StartY);
	if (Answer == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << Answer;
	}
}