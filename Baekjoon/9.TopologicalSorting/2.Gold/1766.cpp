#include <iostream>
#include <list>
#include <queue>
using namespace std;

list<int> Neighbor[32001];
int Entry[32001];

priority_queue<int, vector<int>, greater<int>> PQ;
list<int> Sorted;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int S, E;
		cin >> S >> E;
		Neighbor[S].emplace_back(E);
		++Entry[E];
	}

	for (int i = 1; i <= N; ++i)
	{
		if (Entry[i] == 0)
		{
			PQ.emplace(i);
		}
	}

	while (!PQ.empty())
	{
		int Current = PQ.top();
		PQ.pop();

		Sorted.emplace_back(Current);

		for (const int& N : Neighbor[Current])
		{
			--Entry[N];
			if (Entry[N] == 0)
			{
				PQ.emplace(N);
			}
		}
	}

	for (const int& Num : Sorted)
	{
		cout << Num << ' ';
	}
}