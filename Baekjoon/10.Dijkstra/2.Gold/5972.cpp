#include <iostream>
#include <list>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> p;

const int Inf = INT_MAX;

int N, M;
list<p> Neighbor[50001];
int LS[50001];

void Dijkstra()
{
	for (int i = 1; i <= N; ++i)
	{
		LS[i] = Inf;
	}

	priority_queue<p, vector<p>, greater<p>> PQ;
	LS[1] = 0;
	PQ.emplace(0, 1);
	while (!PQ.empty())
	{
		int Cur = PQ.top().second;
		int Cst = PQ.top().first;
		PQ.pop();
		if (Cst > LS[Cur])
		{
			continue;
		}

		for (const p& N : Neighbor[Cur])
		{
			int Nxt = N.second;
			int NC = Cst + N.first;
			if (NC < LS[Nxt])
			{
				LS[Nxt] = NC;
				PQ.emplace(NC, Nxt);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;

		Neighbor[A].emplace_back(C, B);
		Neighbor[B].emplace_back(C, A);
	}

	Dijkstra();

	cout << LS[N];
}