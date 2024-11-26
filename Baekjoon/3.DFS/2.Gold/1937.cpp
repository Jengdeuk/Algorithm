#include <iostream>
using namespace std;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N;
int M[500][500], DP[500][500];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < N);
}

int DFS(int R, int C)
{
	if (DP[R][C] != -1)
	{
		return DP[R][C];
	}

	DP[R][C] = 0;
	for (int i = 0; i < 4; ++i)
	{
		int NR = R + DY[i];
		int NC = C + DX[i];
		if (IsValid(NR, NC) && M[NR][NC] > M[R][C])
		{
			DP[R][C] = max(DP[R][C], DFS(NR, NC) + 1);
		}
	}

	return DP[R][C];
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
			cin >> M[i][j];
			DP[i][j] = -1;
		}
	}

	int Answer = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (DP[i][j] == -1)
			{
				DFS(i, j);
			}

			Answer = max(Answer, DP[i][j]);
		}
	}

	cout << Answer + 1;
}