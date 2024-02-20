#include <iostream>
#include <list>
#include <queue>
using namespace std;

int N;
int Parent[100001];
bool Visited[100001];
list<int> Neighbors[100001];
queue<int> SearchQueue;

void BFS(int Root)
{
	SearchQueue.emplace(Root);
	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.front();
		SearchQueue.pop();

		if (Visited[Current])
		{
			continue;
		}

		Visited[Current] = true;
		for (const int& Neighbor : Neighbors[Current])
		{
			if (!Visited[Neighbor])
			{
				Parent[Neighbor] = Current;
				SearchQueue.emplace(Neighbor);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; ++i)
	{
		int A, B;
		cin >> A >> B;
		Neighbors[A].emplace_back(B);
		Neighbors[B].emplace_back(A);
	}

	BFS(1);
	for (int i = 2; i <= N; ++i)
	{
		cout << Parent[i] << '\n';
	}
}