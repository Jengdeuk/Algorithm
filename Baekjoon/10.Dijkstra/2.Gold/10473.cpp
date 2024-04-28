#include <iostream>
#include <list>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;

const double Inf = INT_MAX;

typedef pair<double, double> p;
typedef pair<double, int> n;

int S, E, N;
p Point[102];
list<n> Neighbor[102];

double LS[102];

double Time(bool bRun, p Src, p Dst)
{
	double DX = Dst.first - Src.first;
	double DY = Dst.second - Src.second;
	double D = sqrt(DX * DX + DY * DY);

	double T = 0;
	if (bRun)
	{
		T = D / 5.f;
	}
	else
	{
		T = min(D / 5.f, abs(D - 50.f) / 5.f + 2.f);
	}

	return T;
}

void Init()
{
	cin >> Point[0].first >> Point[0].second;
	cin >> Point[1].first >> Point[1].second;
	Neighbor[0].emplace_back(Time(true, Point[0], Point[1]), 1);

	cin >> N;
	for (int i = 2; i < N + 2; ++i)
	{
		cin >> Point[i].first >> Point[i].second;
		Neighbor[0].emplace_back(Time(true, Point[0], Point[i]), i);
		Neighbor[i].emplace_back(Time(false, Point[i], Point[1]), 1);
	}

	for (int i = 2; i < N + 1; ++i)
	{
		for (int j = i + 1; j < N + 2; ++j)
		{
			double T = Time(false, Point[i], Point[j]);
			Neighbor[i].emplace_back(T, j);
			Neighbor[j].emplace_back(T, i);
		}
	}
}

void Dijkstra()
{
	for (int i = 0; i < N + 2; ++i)
	{
		LS[i] = Inf;
	}
	LS[0] = 0;

	priority_queue<n, vector<n>, greater<n>> PQ;
	PQ.emplace(0, 0);
	while (!PQ.empty())
	{
		int Cur = PQ.top().second;
		double T = PQ.top().first;
		PQ.pop();

		if (T > LS[Cur])
		{
			continue;
		}

		for (const n& Ngb : Neighbor[Cur])
		{
			int Nxt = Ngb.second;
			double NT = T + Ngb.first;
			if (NT < LS[Nxt])
			{
				LS[Nxt] = NT;
				PQ.emplace(NT, Nxt);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Init();
	Dijkstra();
	cout << LS[1];
}