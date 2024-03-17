#include <iostream>
#include <climits>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> p;
const int Infinite = INT_MAX;

int N, M;
list<p> Neighbor[1001];

int D[1001];
int P[1001];
deque<int> Way;

void Dijkstra(int Start, int End)
{
	for (int i = 1; i <= N; ++i)
	{
		D[i] = Infinite;
	}

	D[Start] = 0;
	P[Start] = Start;

	priority_queue<p, vector<p>, greater<p>> PQ;
	PQ.emplace(0, Start);
	while (!PQ.empty())
	{
		int Idx = PQ.top().second;
		int Cst = PQ.top().first;
		PQ.pop();

		if (Cst > D[Idx])
		{
			continue;
		}

		for (const p& N : Neighbor[Idx])
		{
			int NI = N.second;
			int NC = N.first;
			int NewCst = D[Idx] + NC;
			if (NewCst < D[NI])
			{
				D[NI] = NewCst;
				P[NI] = Idx;
				PQ.emplace(NewCst, NI);
			}
		}
	}
}

void MakeWay(int Start, int End)
{
	int Cur = End;
	Way.push_front(Cur);

	while (Cur != Start)
	{
		Cur = P[Cur];
		Way.push_front(Cur);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B, W;
		cin >> A >> B >> W;
		Neighbor[A].emplace_back(W, B);
	}

	int S, E;
	cin >> S >> E;

	Dijkstra(S, E);
	MakeWay(S, E);

	cout << D[E] << '\n';
	cout << Way.size() << '\n';
	while (!Way.empty())
	{
		cout << Way.front() << ' ';
		Way.pop_front();
	}
}