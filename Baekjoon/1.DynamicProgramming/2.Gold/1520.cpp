#include <iostream>
using namespace std;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
int H[500][500];
int DP[500][500];

bool IsValid(int R, int C, int PH)
{
	return !(R < 0 || R > N - 1 || C < 0 || C > M - 1 || H[R][C] >= PH);
}

int DFS(int R, int C)
{
	if (R == N - 1 && C == M - 1)
	{
		return 1;
	}
	
	if (DP[R][C] != -1)
	{
		return DP[R][C];
	}

	DP[R][C] = 0;
	for (int i = 0; i < 4; ++i)
	{
		int NR = R + DY[i];
		int NC = C + DX[i];
		if (IsValid(NR, NC, H[R][C]))
		{
			DP[R][C] += DFS(NR, NC);
		}
	}

	return DP[R][C];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> H[i][j];
			DP[i][j] = -1;
		}
	}

	cout << DFS(0, 0);
}