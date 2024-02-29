#include <iostream>
#include <climits>
using namespace std;

const int Infinite = INT_MAX;
const int MoveCost[5][5] =
{
	{ 0, 2, 2, 2, 2 },
	{ 0, 1, 3, 4, 3 },
	{ 0, 3, 1, 3, 4 },
	{ 0, 4, 3, 1, 3 },
	{ 0, 3, 4, 3, 1 }
};

int DP[100000][5][5];

void Init()
{
	for (int i = 0; i < 100000; ++i)
	{
		for (int Left = 0; Left < 5; ++Left)
		{
			for (int Right = 0; Right < 5; ++Right)
			{
				DP[i][Left][Right] = Infinite;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Init();
	int Cnt = 0;

	int NewLoc;
	cin >> NewLoc;
	DP[Cnt][0][NewLoc] = 2;
	++Cnt;
	while (true)
	{
		cin >> NewLoc;
		if (NewLoc == 0)
		{
			break;
		}

		for (int Left = 0; Left < 5; ++Left)
		{
			for (int Right = 0; Right < 5; ++Right)
			{
				int PrevCost = DP[Cnt - 1][Left][Right];
				if (PrevCost == Infinite)
				{
					continue;
				}

				int Cost = Infinite;

				// Right
				Cost = DP[Cnt][Left][NewLoc];
				Cost = min(Cost, PrevCost + MoveCost[Right][NewLoc]);
				DP[Cnt][Left][NewLoc] = Cost;

				// Left
				Cost = DP[Cnt][NewLoc][Right];
				Cost = min(Cost, PrevCost + MoveCost[Left][NewLoc]);
				DP[Cnt][NewLoc][Right] = Cost;
			}
		}

		++Cnt;
	}

	int Min = Infinite;
	for (int Left = 0; Left < 5; ++Left)
	{
		for (int Right = 0; Right < 5; ++Right)
		{
			Min = min(Min, DP[Cnt - 1][Left][Right]);
		}
	}

	cout << Min;
}