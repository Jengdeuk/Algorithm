#include <iostream>
#include <climits>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

const int Inf = INT_MAX;

int N, M, K, S, G, H;
int Goal[100];
list<p> Neighbor[2001];
int Dist[3][2001];

void Dijkstra(int DN, int Start)
{
	priority_queue<p, vector<p>, greater<p>> Q;
	Dist[DN][Start] = 0;
	Q.emplace(0, Start);
	while (!Q.empty())
	{
		int Cur = Q.top().second;
		int Dst = Q.top().first;
		Q.pop();

		if (Dst > Dist[DN][Cur])
		{
			continue;
		}

		for (const p& Ngb : Neighbor[Cur])
		{
			int Nxt = Ngb.first;
			int NDst = Dst + Ngb.second;
			if (NDst < Dist[DN][Nxt])
			{
				Dist[DN][Nxt] = NDst;
				Q.emplace(NDst, Nxt);
			}
		}
	}
}

bool IsPassed(int Cur)
{
	return (Dist[0][Cur] == Dist[0][G] + Dist[1][H] + Dist[2][Cur] || Dist[0][Cur] == Dist[0][H] + Dist[2][G] + Dist[1][Cur]);
}

void Test()
{
	cin >> N >> M >> K >> S >> G >> H;

	for (int i = 1; i <= N; ++i)
	{
		Neighbor[i].clear();
		Dist[0][i] = Inf;
		Dist[1][i] = Inf;
		Dist[2][i] = Inf;
	}

	for (int i = 0; i < M; ++i)
	{
		int A, B, D;
		cin >> A >> B >> D;
		Neighbor[A].emplace_back(B, D);
		Neighbor[B].emplace_back(A, D);
	}

	for (int i = 0; i < K; ++i)
	{
		cin >> Goal[i];
	}

	Dijkstra(0, S);
	Dijkstra(1, G);
	Dijkstra(2, H);

	sort(Goal, Goal + K);
	for (int i = 0; i < K; ++i)
	{
		int Cur = Goal[i];
		if (IsPassed(Cur))
		{
			cout << Cur << ' ';
		}
	}

	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}