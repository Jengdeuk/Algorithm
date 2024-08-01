#include <iostream>
using namespace std;

int N, L;
int H[100][100];

bool CheckRow(int R)
{
	bool S[100] = {};
	for (int j = 0; j < N - 1; ++j)
	{
		if (abs(H[R][j] - H[R][j + 1]) > 1)
		{
			return false;
		}

		if (H[R][j] < H[R][j + 1])
		{
			int NL = 0, NJ = j;
			while (NL < L && NJ >= 0 && S[NJ] == false && H[R][NJ] == H[R][j])
			{
				S[NJ] = true;
				++NL;
				--NJ;
			}

			if (NL < L)
			{
				return false;
			}
		}
		else if (H[R][j] > H[R][j + 1])
		{
			int NL = 0, NJ = j + 1;
			while (NL < L && NJ < N && S[NJ] == false && H[R][NJ] == H[R][j + 1])
			{
				S[NJ] = true;
				++NL;
				++NJ;
			}

			if (NL < L)
			{
				return false;
			}
		}
	}

	return true;
}

bool CheckCol(int C)
{
	bool S[100] = {};
	for (int i = 0; i < N - 1; ++i)
	{
		if (abs(H[i][C] - H[i + 1][C]) > 1)
		{
			return false;
		}

		if (H[i][C] < H[i + 1][C])
		{
			int NL = 0, NI = i;
			while (NL < L && NI >= 0 && S[NI] == false && H[NI][C] == H[i][C])
			{
				S[NI] = true;
				++NL;
				--NI;
			}

			if (NL < L)
			{
				return false;
			}
		}
		else if (H[i][C] > H[i + 1][C])
		{
			int NL = 0, NI = i + 1;
			while (NL < L && NI < N && S[NI] == false && H[NI][C] == H[i + 1][C])
			{
				S[NI] = true;
				++NL;
				++NI;
			}

			if (NL < L)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> L;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> H[i][j];
		}
	}

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		if (CheckRow(i))
		{
			++Cnt;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if (CheckCol(i))
		{
			++Cnt;
		}
	}

	cout << Cnt;
}