#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> Neighbors;
vector<bool> CheckList;
queue<int> SearchQueue;

vector<int> DFS;
vector<int> BFS;

void DFSFunc(int Node)
{
	CheckList[Node] = true;
	DFS.emplace_back(Node);

	for (const int& Neighbor : Neighbors[Node])
	{
		if (!CheckList[Neighbor])
		{
			DFSFunc(Neighbor);
		}
	}
}

void BFSFunc(int Node)
{
	// First Node
	CheckList[Node] = true;
	BFS.emplace_back(Node);
	for (const int& Neighbor : Neighbors[Node])
	{
		if (!CheckList[Neighbor])
		{
			SearchQueue.push(Neighbor);
		}
	}

	while (!SearchQueue.empty())
	{
		int SearchNode = SearchQueue.front();
		SearchQueue.pop();

		if (CheckList[SearchNode])
		{
			continue;
		}

		CheckList[SearchNode] = true;
		BFS.emplace_back(SearchNode);
		for (const int& Neighbor : Neighbors[SearchNode])
		{
			if (!CheckList[Neighbor])
			{
				SearchQueue.push(Neighbor);
			}
		}
	}
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	// 0. Allocation
	Neighbors.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		Neighbors.emplace_back(vector<int>());
	}

	for (int i = 0; i < M; ++i)
	{
		int Source, Destination;
		cin >> Source >> Destination;
		Neighbors[Source - 1].emplace_back(Destination - 1);
		Neighbors[Destination - 1].emplace_back(Source - 1);
	}

	for (vector<int>& CurrentNodeNeighbors : Neighbors)
	{
		sort(CurrentNodeNeighbors.begin(), CurrentNodeNeighbors.end());
	}

	// 1. DFS Algorithm
	DFS.reserve(N);
	CheckList.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		CheckList.emplace_back(false);
	}

	DFSFunc(V - 1);
	
	for (const int& node : DFS)
	{
		cout << node + 1 << ' ';
	}
	cout << '\n';

	// 2. BFS Algorithm
	BFS.reserve(N);
	CheckList.clear();
	for (int i = 0; i < N; ++i)
	{
		CheckList.emplace_back(false);
	}

	BFSFunc(V - 1);

	for (const int& node : BFS)
	{
		cout << node + 1 << ' ';
	}
}