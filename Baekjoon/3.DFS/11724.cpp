#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<list<int>> Neighbors;
vector<bool> Visited;

void DFS(int Node)
{
	Visited[Node] = true;

	for (const int& Neighbor : Neighbors[Node])
	{
		if (Visited[Neighbor])
		{
			continue;
		}

		DFS(Neighbor);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	Neighbors.reserve(N);
	Visited.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		Neighbors.emplace_back(list<int>());
		Visited.emplace_back(false);
	}

	for (int i = 0; i < M; ++i)
	{
		int Src, Dst;
		cin >> Src >> Dst;

		Neighbors[Src - 1].emplace_back(Dst - 1);
		Neighbors[Dst - 1].emplace_back(Src - 1);
	}

	int Count = 0;
	for (int i = 0; i < N; ++i)
	{
		if (Visited[i])
		{
			continue;
		}

		DFS(i);
		++Count;
	}
	cout << Count;
}