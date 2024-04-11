#include <iostream>
using namespace std;

const int Infinite = 20000000;

int N;
int W[16][16];
int DP[16][1 << 16];

int DFS(int Num, int Bit)
{
	if (Bit == (1 << N) - 1)
	{
		if (W[Num][0] == 0)
		{
			return Infinite;
		}

		return W[Num][0];
	}

	if (DP[Num][Bit] != -1)
	{
		return DP[Num][Bit];
	}

	DP[Num][Bit] = Infinite;
	for (int i = 0; i < N; ++i)
	{
		if (W[Num][i] == 0 || (Bit & 1 << i) == (1 << i))
		{
			continue;
		}

		DP[Num][Bit] = min(DP[Num][Bit], W[Num][i] + DFS(i, Bit | 1 << i));
	}

	return DP[Num][Bit];
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
			cin >> W[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < (1 << N); ++j)
		{
			DP[i][j] = -1;
		}
	}

	cout << DFS(0, 1 << 0);
}