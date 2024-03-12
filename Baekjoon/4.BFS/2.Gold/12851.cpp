#include <iostream>
#include <queue>
using namespace std;

int Time[100001];
int Count[100001];
bool Visited[100001];
queue<int> SQ;

void NeighborCheck(int Neighbor, int Current)
{
	if (Neighbor < 0 || Neighbor > 100000)
	{
		return;
	}

	int CurTime = Time[Neighbor];
	int NewTime = Time[Current] + 1;
	if (NewTime < CurTime)
	{
		Time[Neighbor] = NewTime;
		Count[Neighbor] = Count[Current];
	}
	else if (NewTime == CurTime)
	{
		Count[Neighbor] += Count[Current];
	}

	SQ.emplace(Neighbor);
}

void BFS(int Start, int End)
{
	Time[Start] = 0;
	Count[Start] = 1;
	SQ.emplace(Start);
	while (!SQ.empty())
	{
		int Current = SQ.front();
		SQ.pop();

		if (Visited[Current])
		{
			continue;
		}

		Visited[Current] = true;
		NeighborCheck(Current - 1, Current);
		NeighborCheck(Current + 1, Current);
		NeighborCheck(2 * Current, Current);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i <= 100000; ++i)
	{
		Time[i] = 1000000;
	}

	int N, K;
	cin >> N >> K;

	if (N != K)
	{
		BFS(N, K);
	}
	else
	{
		Time[K] = 0;
		Count[K] = 1;
	}

	cout << Time[K] << '\n';
	cout << Count[K];
}