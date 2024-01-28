#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> Maze;
vector<vector<int>> Neighbors;
vector<bool> Visited;
queue<int> SearchQueue;
vector<int> Predecessor;

void BFS(int InRow, int InCol)
{
	int StartPoint = 0;
	int FinishPoint = InRow * InCol - 1;

	Visited[StartPoint] = true;
	for (const int& Neighbor : Neighbors[StartPoint])
	{
		if (!Visited[Neighbor])
		{
			SearchQueue.push(Neighbor);
			Predecessor[Neighbor] = StartPoint;
		}
	}

	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.front();
		SearchQueue.pop();

		if (Visited[Current])
		{
			continue;
		}

		Visited[Current] = true;

		for (const int& Neighbor : Neighbors[Current])
		{
			if (!Visited[Neighbor])
			{
				SearchQueue.push(Neighbor);
				Predecessor[Neighbor] = Current;
			}

			if (Neighbor == FinishPoint)
			{
				return;
			}
		}
	}
}

int BackTracking(int InRow, int InCol)
{
	int Count = 1;
	int FinishPoint = InRow * InCol - 1;

	int BackPoint = Predecessor[FinishPoint];
	while (BackPoint != -1)
	{
		int Current = BackPoint;
		++Count;
		BackPoint = Predecessor[Current];
	}

	return Count;
}

int main()
{
	int N, M;
	cin >> N >> M;

	// Visited Initialize
	Visited.reserve(N * M);
	for (int i = 0; i < N * M; ++i)
	{
		Visited.emplace_back(false);
	}

	// Maze Initialize
	Maze.reserve(N * M);
	for (int i = 0; i < N * M; ++i)
	{
		Maze.emplace_back(0);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char Character = cin.get();
			if (Character == '\n') Character = cin.get();
			Maze[i * M + j] = Character - '0';
		}
	}

	// Neighbors Initialize
	Neighbors.reserve(N * M);
	for (int i = 0; i < N * M; ++i)
	{
		Neighbors.emplace_back(vector<int>());
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int Current = i * M + j;

			int Top = Current - M;
			int Bottom = Current + M;
			int Left = Current - 1;
			int Right = Current + 1;

			// right
			if (Current % M < M - 1
				&& Maze[Right] == 1)
			{
				Neighbors[Current].emplace_back(Right);
			}

			// bottom
			if (Bottom < N * M
				&& Maze[Bottom] == 1)
			{
				Neighbors[Current].emplace_back(Bottom);
			}

			// top
			if (Top >= 0
				&& Maze[Top] == 1)
			{
				Neighbors[Current].emplace_back(Top);
			}

			// left
			if (Current % M > 0
				&& Maze[Left] == 1)
			{
				Neighbors[Current].emplace_back(Left);
			}
		}
	}

	// Predecessor Initialize
	Predecessor.reserve(N * M);
	for (int i = 0; i < N * M; ++i)
	{
		Predecessor.emplace_back(-1);
	}

	BFS(N, M);

	cout << BackTracking(N, M);
}