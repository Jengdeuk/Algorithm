#include <iostream>
#include <list>
#include <cstring>
using namespace std;

int N;
list<pair<int, int>> Neighbor[100000];
bool Visited[100000];

int Max;
int A, B;
void DFS(bool bFindA, int Idx, int Length)
{
	Visited[Idx] = true;

	int Cnt = 0;
	for (const pair<int, int>& N : Neighbor[Idx])
	{
		if (!Visited[N.first])
		{
			DFS(bFindA, N.first, Length + N.second);
			++Cnt;
		}
	}

	if (Cnt == 0)
	{
		if (Length > Max)
		{
			Max = Length;

			if (bFindA)
			{
				A = Idx;
			}
			else
			{
				B = Idx;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Src;
		cin >> Src;
		while (true)
		{
			int Dst;
			cin >> Dst;
			if (Dst == -1)
			{
				break;
			}

			int Cst;
			cin >> Cst;
			Neighbor[Src - 1].emplace_back(Dst - 1, Cst);
		}
	}

	DFS(true, 0, 0);
	memset(Visited, false, sizeof(Visited));
	DFS(false, A, 0);

	cout << Max;
}