#include <iostream>
#include <algorithm>
using namespace std;

const int DX[4] = { -1, 1, 1, -1 };
const int DY[4] = { 1, 1, 1, 1 };

int N, P[20][20];
int Sol[4];
int MinGap = 1234567890;

void CalcMinGap()
{
	int SR = Sol[2];
	int SC = Sol[3];
	int D1 = Sol[0];
	int D2 = Sol[1];

	int Z[20][20] = {};
	for (int i = 0; i < 4; ++i)
	{
		int R, C, ER, EC;
		switch (i)
		{
		case 0:
			R = SR;
			C = SC;
			ER = R + D1;
			EC = C - D1;
			break;
		case 1:
			R = SR;
			C = SC;
			ER = R + D2;
			EC = C + D2;
			break;
		case 2:
			R = SR + D1;
			C = SC - D1;
			ER = R + D2;
			EC = C + D2;
			break;
		case 3:
			R = SR + D2;
			C = SC + D2;
			ER = R + D1;
			EC = C - D1;
			break;
		}

		while (R != ER && C != EC)
		{
			Z[R][C] = 5;
			R += DY[i];
			C += DX[i];
		}
		Z[R][C] = 5;
	}

	for (int i = 0; i < SR + D1; ++i)
	{
		for (int j = 0; j <= SC; ++j)
		{
			if (Z[i][j] == 5)
			{
				break;
			}

			Z[i][j] = 1;
		}
	}

	for (int i = 0; i <= SR + D2; ++i)
	{
		for (int j = N - 1; j > SC; --j)
		{
			if (Z[i][j] == 5)
			{
				break;
			}

			Z[i][j] = 2;
		}
	}

	for (int i = SR + D1; i < N; ++i)
	{
		for (int j = 0; j < SC - D1 + D2; ++j)
		{
			if (Z[i][j] == 5)
			{
				break;
			}

			Z[i][j] = 3;
		}
	}

	for (int i = SR + D2 + 1; i < N; ++i)
	{
		for (int j = N - 1; j >= SC + D2 - D1; --j)
		{
			if (Z[i][j] == 5)
			{
				break;
			}

			Z[i][j] = 4;
		}
	}

	int Gap[5] = {};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Z[i][j] > 0)
			{
				Gap[Z[i][j] - 1] += P[i][j];
			}
			else
			{
				Gap[4] += P[i][j];
			}
		}
	}

	sort(Gap, Gap + 5);

	MinGap = min(MinGap, Gap[4] - Gap[0]);
}

void Bruteforce(int Idx)
{
	if (Idx == 4)
	{
		CalcMinGap();
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		switch (Idx)
		{
		case 0:
		case 1:
			if (i == 0)
			{
				continue;
			}
			break;
		case 2:
			if (i + Sol[0] + Sol[1] >= N)
			{
				continue;
			}
			break;
		case 3:
			if (i - Sol[0] < 0 || i + Sol[1] >= N)
			{
				continue;
			}
			break;
		}

		Sol[Idx] = i;
		Bruteforce(Idx + 1);
	}
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
			cin >> P[i][j];
		}
	}

	Bruteforce(0);

	cout << MinGap;
}