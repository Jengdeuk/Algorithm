#include <iostream>
#include <string>
using namespace std;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
int B[50][50], D[50][50];
bool bInf;
bool V[50][50][50][50];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && B[R][C] > 0);
}

void DFS(int R, int C)
{
	if (R == 2 && C == 3)
	{
		int a = 0;
	}

	for (int i = 0; i < 4; ++i)
	{
		int NR = R + DY[i] * B[R][C];
		int NC = C + DX[i] * B[R][C];
		if (!IsValid(NR, NC))
		{
			continue;
		}

		if (V[R][C][NR][NC] || B[NR][NC] == B[R][C])
		{
			bInf = true;
			return;
		}

		int ND = D[R][C] + 1;
		if (ND <= D[NR][NC])
		{
			continue;
		}

		D[NR][NC] = ND;
		V[R][C][NR][NC] = true;
		DFS(NR, NC);
		V[R][C][NR][NC] = false;
		if (bInf)
		{
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < M; ++j)
		{
			if (S[j] == 'H')
			{
				B[i][j] = 0;
			}
			else
			{
				B[i][j] = S[j] - '0';
			}
		}
	}

	D[0][0] = 0;
	DFS(0, 0);

	if (!bInf)
	{
		int Max = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				Max = max(Max, D[i][j]);
			}
		}

		cout << Max + 1;
	}
	else
	{
		cout << -1;
	}
}