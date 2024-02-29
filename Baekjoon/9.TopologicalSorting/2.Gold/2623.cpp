#include <iostream>
#include <list>
#include <queue>
using namespace std;

list<int> Neighbors[1001];
int Entries[1001];
bool Visited[1001];
queue<int> SQ;
int Solution[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int Size;
		cin >> Size;
		
		int Previous;
		cin >> Previous;
		for (int j = 1; j < Size; ++j)
		{
			int Current;
			cin >> Current;
			Neighbors[Previous].emplace_back(Current);
			++Entries[Current];
			Previous = Current;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (Entries[i] == 0)
		{
			SQ.emplace(i);
		}
	}

	int Cnt = 0;
	while (!SQ.empty())
	{
		int Current = SQ.front();
		SQ.pop();

		if (Visited[Current])
		{
			continue;
		}

		Visited[Current] = true;
		Solution[Cnt] = Current;
		++Cnt;

		for (const int& Neighbor : Neighbors[Current])
		{
			--Entries[Neighbor];
			if (Entries[Neighbor] == 0
				&& !Visited[Neighbor])
			{
				SQ.emplace(Neighbor);
			}
		}
	}

	if (Cnt != N)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << Solution[i] << '\n';
	}
}