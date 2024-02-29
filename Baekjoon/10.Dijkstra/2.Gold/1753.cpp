#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> Neighbors;
vector<int> LinkState;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> NonVisited; // 오름차순 PQ

const int& Infinite = INT_MAX;

void Init(int InV, int InE, int InK)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Neighbors.reserve(InV);
	for (int i = 0; i < InV; ++i)
	{
		Neighbors.emplace_back(vector<pair<int, int>>());
	}

	for (int i = 0; i < InE; ++i)
	{
		int Src, Dest, Weight;
		cin >> Src >> Dest >> Weight;

		Neighbors[Src - 1].emplace_back(Dest - 1, Weight);
	}

	LinkState.reserve(InV);
	for (int i = 0; i < InV; ++i)
	{
		LinkState.emplace_back(Infinite);
	}
	LinkState[InK - 1] = 0;
}

void Dijkstra(int InK)
{
	NonVisited.emplace(0, InK - 1);

	while (!NonVisited.empty())
	{
		// Choose Short Distance Node
		int Current = NonVisited.top().second;
		NonVisited.pop();

		// Update Neighbors LinkState
		for (const pair<int, int>& Neighbor : Neighbors[Current])
		{
			if (LinkState[Current] + Neighbor.second < LinkState[Neighbor.first])
			{
				LinkState[Neighbor.first] = LinkState[Current] + Neighbor.second;
				NonVisited.emplace(LinkState[Neighbor.first], Neighbor.first);
			}
		}
	}
}

int main()
{
	int V, E, K;
	cin >> V >> E >> K;

	Init(V, E, K);

	Dijkstra(K);

	for (const int& Distance : LinkState)
	{
		if (Distance == Infinite)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << Distance << '\n';
		}
	}
}