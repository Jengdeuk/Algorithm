#include <iostream>
#include <list>
#include <queue>
#include <climits>
using namespace std;

const int Infinite = INT_MAX;

int W, H, N, D;
typedef pair<int, int> location;
typedef pair<int, location> node;

int Lane[101];
int Density[101];

list<location> Neighbors[101][101];
int Distance[101][101];
priority_queue<node, vector<node>, greater<node>> SQ;

void Dijkstra(int StartX, int StartY)
{
	for (int Y = 0; Y <= H; ++Y)
	{
		for (int X = 0; X <= W; ++X)
		{
			Distance[Y][X] = Infinite;
		}
	}

	Distance[StartY][StartX] = 0;
	SQ.emplace(0, location(StartX, StartY));
	while (!SQ.empty())
	{
		int X = SQ.top().second.first;
		int Y = SQ.top().second.second;
		int C = SQ.top().first;
		SQ.pop();

		if (C > Distance[Y][X])
		{
			continue;
		}

		for (const location& Neighbor : Neighbors[Y][X])
		{
			int NX = Neighbor.first;
			int NY = Neighbor.second;

			int NC;
			if (NY >= Y)
			{
				NC = Density[Y];
			}
			else
			{
				NC = Density[NY];
			}

			int NewC = Distance[Y][X] + NC;
			if (NewC < Distance[NY][NX])
			{
				Distance[NY][NX] = NewC;
				SQ.emplace(NewC, location(NX, NY));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> W >> H >> N >> D;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Lane[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		int P;
		cin >> P;
		for (int j = Lane[i - 1]; j < Lane[i]; ++j)
		{
			Density[j] = P;
		}
	}
	Density[Lane[N]] = Density[Lane[N] - 1];

	for (int Y = 0; Y <= H; ++Y)
	{
		for (int X = 0; X <= W; ++X)
		{
			if (X > 0)
			{
				Neighbors[Y][X].emplace_back(X - 1, Y);
			}

			if (X < W)
			{
				Neighbors[Y][X].emplace_back(X + 1, Y);
			}

			if (Y > 0)
			{
				Neighbors[Y][X].emplace_back(X, Y - 1);
			}

			if (Y < H)
			{
				Neighbors[Y][X].emplace_back(X, Y + 1);
			}
		}
	}

	Dijkstra(0, 0);

	cout << Distance[D][W];
}