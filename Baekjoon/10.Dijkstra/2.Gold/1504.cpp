#include <iostream>
#include <climits>
#include <list>
#include <queue>
using namespace std;

const int Infinite = INT_MAX;

typedef pair<int, int> node;

int N, E;
list<pair<int, int>> Neighbors[801];

int Distance[801];
priority_queue<node, vector<node>, greater<node>> SQ;

int Dijkstra(int Start, int End)
{
	for (int i = 1; i <= N; ++i)
	{
		Distance[i] = Infinite;
	}

	Distance[Start] = 0;
	SQ.emplace(0, Start);
	while (!SQ.empty())
	{
		int CurIdx = SQ.top().second;
		int CurCst = SQ.top().first;
		SQ.pop();

		if (CurCst > Distance[CurIdx])
		{
			continue;
		}

		for (const pair<int, int>& N : Neighbors[CurIdx])
		{
			int NewCst = Distance[CurIdx] + N.second;
			if (NewCst < Distance[N.first])
			{
				Distance[N.first] = NewCst;
				SQ.emplace(NewCst, N.first);
			}
		}
	}

	return Distance[End];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> E;
	for (int i = 0; i < E; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;

		Neighbors[A].emplace_back(B, C);
		Neighbors[B].emplace_back(A, C);
	}

	int X, Y;
	cin >> X >> Y;

	int SolA = Infinite, SolB = Infinite;

	int Dst1, Dst2, Dst3;

	Dst1 = Dijkstra(1, X);
	Dst2 = Dijkstra(X, Y);
	Dst3 = Dijkstra(Y, N);

	if (Dst1 != Infinite && Dst2 != Infinite && Dst3 != Infinite)
	{
		SolA = Dst1 + Dst2 + Dst3;
	}

	Dst1 = Dijkstra(1, Y);
	Dst2 = Dijkstra(Y, X);
	Dst3 = Dijkstra(X, N);

	if (Dst1 != Infinite && Dst2 != Infinite && Dst3 != Infinite)
	{
		SolB = Dst1 + Dst2 + Dst3;
	}

	if (SolA == Infinite && SolB == Infinite)
	{
		cout << -1;
		return 0;
	}

	cout << min(SolA, SolB);
}