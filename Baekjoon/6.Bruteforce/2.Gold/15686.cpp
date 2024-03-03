#include <iostream>
using namespace std;

typedef pair<int, int> location;

int N, M, H, C;
location House[100];
location Chicken[13];
bool Check[13];

int Min = 1000000000;

int GetChickenDistance()
{
	int Sum = 0;
	for (int h = 0; h < H; ++h)
	{
		int Distance = 1000000000;
		for (int c = 0; c < C; ++c)
		{
			if (!Check[c])
			{
				continue;
			}

			int X = abs(Chicken[c].second - House[h].second);
			int Y = abs(Chicken[c].first - House[h].first);
			Distance = min(Distance, X + Y);
		}

		Sum += Distance;
	}

	return Sum;
}

void DFS(int CurNum, int CurIdx)
{
	if (CurNum == M)
	{
		Min = min(Min, GetChickenDistance());
		return;
	}

	if (CurIdx == C)
	{
		return;
	}

	Check[CurIdx] = true;
	DFS(CurNum + 1, CurIdx + 1);
	Check[CurIdx] = false;
	DFS(CurNum, CurIdx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int Num;
			cin >> Num;

			if (Num == 1)
			{
				House[H] = location(i, j);
				++H;
			}
			else if (Num == 2)
			{
				Chicken[C] = location(i, j);
				++C;
			}
		}
	}

	DFS(0, 0);

	cout << Min;
}