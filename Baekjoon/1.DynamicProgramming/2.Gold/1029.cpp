#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N;
int M[15][15];
int DP[1 << 15][15][10];

int Func(int Vst, int Cur, int Cst)
{
	if (DP[Vst][Cur][Cst] != -1)
	{
		return DP[Vst][Cur][Cst];
	}

	int Max = 0;
	for (int i = 1; i < N; ++i)
	{
		if (!(Vst & (1 << i)) && M[Cur][i] >= Cst)
		{
			int NVst = Vst | (1 << i);
			Max = max(Max, Func(NVst, i, M[Cur][i]) + 1);
		}
	}

	return DP[Vst][Cur][Cst] = Max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;

		for (int j = 0; j < N; ++j)
		{
			M[i][j] = S[j] - '0';
		}
	}

	memset(DP, -1, sizeof(DP));
	Func(1, 0, 0);
	cout << DP[1][0][0] + 1;
}