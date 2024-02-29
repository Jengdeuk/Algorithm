#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

const int& MaxSize = 100001;
const int& Infinite = INT_MAX;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> SearchQueue;
int Times[MaxSize];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < MaxSize; ++i)
	{
		Times[i] = Infinite;
	}
	Times[N] = 0;

	SearchQueue.emplace(0, N);
	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.top().second;
		int CurrentTime = SearchQueue.top().first;
		SearchQueue.pop();

		if (CurrentTime > Times[Current])
		{
			continue;
		}

		pair<int, int> Neighbors[3];

		Neighbors[0].second = Current - 1;
		Neighbors[1].second = Current + 1;
		Neighbors[2].second = 2 * Current;

		Neighbors[0].first = 1;
		Neighbors[1].first = 1;
		Neighbors[2].first = 0;

		for (int i = 0; i < 3; ++i)
		{
			int Neighbor = Neighbors[i].second;
			if (Neighbor >= MaxSize
				|| Neighbor < 0)
			{
				continue;
			}

			int NewTime = CurrentTime + Neighbors[i].first;
			if (NewTime < Times[Neighbor])
			{
				Times[Neighbor] = NewTime;
				SearchQueue.emplace(NewTime, Neighbor);
			}
		}
	}

	cout << Times[K];
}