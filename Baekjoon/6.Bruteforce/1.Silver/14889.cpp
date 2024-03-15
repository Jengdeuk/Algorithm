#include <iostream>
using namespace std;

int N;
int Synergy[20][20];
bool Start[10];

int Min = 100000000;

void CalculateGap()
{
	int S = 0;
	int L = 0;
	for (int i = 0; i < N; ++i)
	{
		if (Start[i])
		{
			for (int j = 0; j < N; ++j)
			{
				if (!Start[j] || i == j)
				{
					continue;
				}

				S += Synergy[i][j];
			}
		}
		else
		{
			for (int j = 0; j < N; ++j)
			{
				if (Start[j] || i == j)
				{
					continue;
				}

				L += Synergy[i][j];
			}
		}
	}

	Min = min(Min, abs(S - L));
}

void Backtracking(int Index, int StartNum)
{
	if (StartNum == N / 2)
	{
		CalculateGap();
		return;
	}

	if (Index == N)
	{
		return;
	}

	Start[Index] = true;
	Backtracking(Index + 1, StartNum + 1);
	Start[Index] = false;
	Backtracking(Index + 1, StartNum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Synergy[i][j];
		}
	}

	Backtracking(0, 0);
	cout << Min;
}