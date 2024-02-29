#include <iostream>
#include <vector>
#include <list>
using namespace std;

int Map[50][50];
list<pair<int, int>> Neighbors[50][50];

void DFS(int Row, int Col)
{
	Map[Row][Col] = 0;

	for (const pair<int, int>& Neighbor : Neighbors[Row][Col])
	{
		if (Map[Neighbor.first][Neighbor.second] == 0)
		{
			continue;
		}

		DFS(Neighbor.first, Neighbor.second);
	}
}

void TestCase()
{
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			Map[i][j] = 0;
			Neighbors[i][j] = list<pair<int, int>>();
		}
	}

	int M, N, K;
	cin >> M >> N >> K;
	for (int i = 0; i < K; ++i)
	{
		int X, Y;
		cin >> X >> Y;
		Map[Y][X] = 1;
	}

	// Init Neighbors
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] == 0)
			{
				continue;
			}

			// left
			if (j > 0
				&& Map[i][j - 1] == 1)
			{
				Neighbors[i][j].emplace_back(i, j - 1);
			}

			// top
			if (i > 0
				&& Map[i - 1][j] == 1)
			{
				Neighbors[i][j].emplace_back(i - 1, j);
			}

			// right
			if (j < M - 1
				&& Map[i][j + 1] == 1)
			{
				Neighbors[i][j].emplace_back(i, j + 1);
			}

			// bottom
			if (i < N - 1
				&& Map[i + 1][j] == 1)
			{
				Neighbors[i][j].emplace_back(i + 1, j);
			}
		}
	}

	// DFS
	int Count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] == 0)
			{
				continue;
			}

			DFS(i, j);
			++Count;
		}
	}

	cout << Count << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		TestCase();
	}
}