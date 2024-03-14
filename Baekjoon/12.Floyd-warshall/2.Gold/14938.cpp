#include <iostream>
#include <climits>
using namespace std;

const int Infinite = INT_MAX;

int N, M, R;
int Item[101];
int Distance[101][101];

void FloydWarshall()
{
	for (int k = 1; k <= N; ++k)
	{
		for (int s = 1; s <= N; ++s)
		{
			for (int e = 1; e <= N; ++e)
			{
				if (s == e || s == k || k == e
					|| Distance[s][k] == Infinite
					|| Distance[k][e] == Infinite)
				{
					continue;
				}

				Distance[s][e] = min(Distance[s][e], Distance[s][k] + Distance[k][e]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Item[i];
	}
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
			{
				continue;
			}

			Distance[i][j] = Infinite;
		}
	}

	for (int i = 0; i < R; ++i)
	{
		int S, E, W;
		cin >> S >> E >> W;
		Distance[S][E] = W;
		Distance[E][S] = W;
	}

	FloydWarshall();

	int MaxItem = 0;
	for (int s = 1; s <= N; ++s)
	{
		int Sum = 0;
		for (int e = 1; e <= N; ++e)
		{
			if (Distance[s][e] > M)
			{
				continue;
			}

			Sum += Item[e];
		}

		if (Sum > MaxItem)
		{
			MaxItem = Sum;
		}
	}

	cout << MaxItem;
}