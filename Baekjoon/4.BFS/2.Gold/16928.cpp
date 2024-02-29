#include <iostream>
#include <queue>
using namespace std;

int Depth[101];
bool Visited[101];
int Event[101];
queue<int> SearchQueue;

int BFS(int Start, int End)
{
	SearchQueue.emplace(Start);
	Depth[Start] = 0;

	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.front();
		SearchQueue.pop();

		if (Visited[Current])
		{
			continue;
		}

		Visited[Current] = true;

		// Snakes or Ladders
		int Neighbor = Event[Current];
		if (Neighbor != 0)
		{
			if (!Visited[Neighbor])
			{
				Depth[Neighbor] = min(Depth[Neighbor], Depth[Current]);
				SearchQueue.emplace(Neighbor);
			}

			continue;
		}

		// Dice
		for (int i = 1; i <= 6; ++i)
		{
			Neighbor = Current + i;
			if (Neighbor <= 100 && !Visited[Neighbor])
			{
				Depth[Neighbor] = min(Depth[Neighbor], Depth[Current] + 1);
				SearchQueue.emplace(Neighbor);
			}
		}
	}

	return Depth[End];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N + M; ++i)
	{
		int Src, Dst;
		cin >> Src >> Dst;
		Event[Src] = Dst;
	}

	for (int i = 1; i <= 100; ++i)
	{
		Depth[i] = 100;
	}

	cout << BFS(1, 100);
}