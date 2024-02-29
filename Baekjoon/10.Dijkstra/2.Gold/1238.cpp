#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

const int& Infinite = INT_MAX;

vector<list<pair<int, int>>> Neighbors;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> SearchQueue;
vector<int> Solution;

vector<int> Dijkstra(int N, int Start)
{
	vector<int> Times;
	Times.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		Times.emplace_back(Infinite);
	}
	Times[Start] = 0;

	SearchQueue.emplace(0, Start);
	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.top().second;
		int CurrentTime = SearchQueue.top().first;
		SearchQueue.pop();

		if (CurrentTime > Times[Current])
		{
			continue;
		}

		for (const pair<int, int>& Neighbor : Neighbors[Current])
		{
			int NewTime = Times[Current] + Neighbor.first;
			if (NewTime < Times[Neighbor.second])
			{
				Times[Neighbor.second] = NewTime;
				SearchQueue.emplace(NewTime, Neighbor.second);
			}
		}
	}

	return Times;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, X;
	cin >> N >> M >> X;

	Neighbors.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		Neighbors.emplace_back(list<pair<int, int>>());
	}

	for (int i = 0; i < M; ++i)
	{
		int Start, End, Weight;
		cin >> Start >> End >> Weight;

		Neighbors[Start - 1].emplace_back(Weight, End - 1);
	}

	vector<int> ReturnTimes = Dijkstra(N, X - 1);

	Solution.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		vector<int> GoingTimes = Dijkstra(N, i);
		int TotalTime = GoingTimes[X - 1] + ReturnTimes[i];
		Solution.emplace_back(TotalTime);
	}

	cout << *max_element(Solution.begin(), Solution.end());
}