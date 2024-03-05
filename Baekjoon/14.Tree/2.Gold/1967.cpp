#include <iostream>
#include <list>
using namespace std;

int Max = 0, A = 1, B = 1;
list<pair<int, int>> Neighbors[10001];
bool Visited[10001];

void DFS(bool bACheck, int Current, int Length)
{
	Visited[Current] = true;

	int Cnt = 0;
	for (const pair<int, int>& N : Neighbors[Current])
	{
		int Neighbor = N.first;
		int Weight = N.second;

		if (!Visited[Neighbor])
		{
			DFS(bACheck, Neighbor, Length + Weight);
			++Cnt;
		}
	}

	if (Cnt == 0 && Length > Max)
	{
		Max = Length;
		if (bACheck)
		{
			A = Current;
		}
		else
		{
			B = Current;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; ++i)
	{
		int P, C, W;
		cin >> P >> C >> W;
		Neighbors[P].emplace_back(C, W);
		Neighbors[C].emplace_back(P, W);
	}

	DFS(true, 1, 0);

	Max = 0;
	for (int i = 1; i <= N; ++i)
	{
		Visited[i] = false;
	}

	DFS(false, A, 0);

	cout << Max;
}