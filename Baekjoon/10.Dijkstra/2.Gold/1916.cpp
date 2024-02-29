#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

const int& Infinite = INT_MAX;

vector<vector<pair<int, int>>> Neighbors;
vector<int> LinkState;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> SearchQueue;

void Init(int InN, int InM)
{
	Neighbors.reserve(InN);
	for (int i = 0; i < InN; ++i)
	{
		Neighbors.emplace_back(vector<pair<int, int>>());
	}

	for (int i = 0; i < InM; ++i)
	{
		int Src, Dst, Cst;
		cin >> Src >> Dst >> Cst;
		Neighbors[Src - 1].emplace_back(Dst - 1, Cst);
	}

	LinkState.reserve(InN);
	for (int i = 0; i < InN; ++i)
	{
		LinkState.emplace_back(Infinite);
	}
}

void Dijkstra(int InStart)
{
	SearchQueue.emplace(0, InStart - 1);

	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.top().second;
		int CurrentCst = SearchQueue.top().first;
		SearchQueue.pop();

		if (CurrentCst > LinkState[Current])
		{
			continue;
		}

		for (const pair<int, int>& Neighbor : Neighbors[Current])
		{
			int NewCost = LinkState[Current] + Neighbor.second;
			if (NewCost < LinkState[Neighbor.first])
			{
				LinkState[Neighbor.first] = NewCost;
				SearchQueue.emplace(NewCost, Neighbor.first);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	Init(N, M);

	int Start, End;
	cin >> Start >> End;
	LinkState[Start - 1] = 0;

	Dijkstra(Start);

	cout << LinkState[End - 1];
}