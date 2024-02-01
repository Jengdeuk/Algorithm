#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

void Play()
{
	int N, K;
	cin >> N >> K;

	vector<int> Times;
	Times.reserve(N);

	vector<int> EndTimes;
	Times.reserve(N);

	vector<list<int>> Neighbors;
	Neighbors.reserve(N);

	vector<int> Entries;
	Entries.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		int Time;
		cin >> Time;
		Times.emplace_back(Time);
		EndTimes.emplace_back(0);
		Neighbors.emplace_back(list<int>());
		Entries.emplace_back(0);
	}

	for (int i = 0; i < K; ++i)
	{
		int X, Y;
		cin >> X >> Y;
		Neighbors[X - 1].emplace_back(Y - 1);
		++Entries[Y - 1];
	}

	int W;
	cin >> W;

	queue<int> SearchQueue;
	for (int i = 0; i < N; ++i)
	{
		if (Entries[i] == 0)
		{
			SearchQueue.push(i);
			EndTimes[i] += Times[i];
		}
	}

	vector<int> CompleteTimes;
	CompleteTimes.reserve(N);

	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.front();
		SearchQueue.pop();

		if (Current == W - 1)
		{
			cout << EndTimes[Current] << '\n';
			return;
		}

		for (const int& Neighbor : Neighbors[Current])
		{
			--Entries[Neighbor];
			EndTimes[Neighbor] = max(EndTimes[Neighbor], EndTimes[Current] + Times[Neighbor]);

			if (Entries[Neighbor] == 0)
			{
				SearchQueue.emplace(Neighbor);
			}
		}
	}
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
		Play();
	}
}