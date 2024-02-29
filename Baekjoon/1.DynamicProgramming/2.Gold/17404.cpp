#include <iostream>
using namespace std;

int Weight[1001][3];
int DP[1001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int R, G, B;
		cin >> R >> G >> B;

		Weight[i][0] = R;
		Weight[i][1] = G;
		Weight[i][2] = B;
	}

	int Max = 1000 * N;
	int Min = Max;
	for (int Start = 0; Start <= 2; ++Start)
	{
		for (int i = 0; i <= 2; ++i)
		{
			if (i == Start)
			{
				DP[1][i] = Weight[1][Start];
			}
			else
			{
				DP[1][i] = Max;
			}
		}

		for (int i = 2; i <= N; ++i)
		{
			DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + Weight[i][0];
			DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + Weight[i][1];
			DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + Weight[i][2];
		}

		for (int i = 0; i <= 2; ++i)
		{
			if (i != Start)
			{
				Min = min(Min, DP[N][i]);
			}
		}
	}

	cout << Min;
}