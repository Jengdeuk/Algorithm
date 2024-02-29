#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

vector<list<int>> Neighbors;
vector<int> Entries;
vector<int> Sequence;
queue<int> SearchQueue;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	Neighbors.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		Neighbors.emplace_back(list<int>());
	}

	Entries.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		Entries.emplace_back(0);
	}

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;

		Neighbors[A - 1].emplace_back(B - 1);
		++Entries[B - 1];
	}

	int i = 0;
	for (int& Entry : Entries)
	{
		if (Entry == 0)
		{
			SearchQueue.push(i);
		}

		++i;
	}

	Sequence.reserve(N);
	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.front();
		SearchQueue.pop();

		Sequence.emplace_back(Current);
		for (const int& Neighbor : Neighbors[Current])
		{
			--Entries[Neighbor];
			if (Entries[Neighbor] == 0)
			{
				SearchQueue.push(Neighbor);
			}
		}
	}

	for(const int& Student : Sequence)
	{
		cout << Student + 1 << ' ';
	}
}