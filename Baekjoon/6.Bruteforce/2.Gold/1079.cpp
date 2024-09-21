#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int T[16], R[16][16];
int Max;

bool IsWin()
{
	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		if (T[i] == 0 || i == M)
		{
			continue;
		}

		++Cnt;
	}

	return (Cnt == 0);
}

void BF(int Idx, int Night)
{
	int Temp[16] = {};
	memcpy(Temp, T, sizeof(Temp));

	int L = N - Idx;
	if (L % 2 == 1)
	{
		int KI = max_element(T, T + N) - T;
		T[KI] = 0;
		if (KI == M)
		{
			Max = max(Max, Night);
			return;
		}

		BF(Idx + 1, Night);
		memcpy(T, Temp, sizeof(T));
	}
	else
	{
		++Night;

		for (int i = 0; i < N; ++i)
		{
			if (i == M || T[i] == 0)
			{
				continue;
			}

			T[i] = 0;
			for (int j = 0; j < N; ++j)
			{
				if (T[j] == 0)
				{
					continue;
				}

				T[j] += R[i][j];
			}

			if (IsWin())
			{
				Max = max(Max, Night);
				return;
			}

			BF(Idx + 1, Night);
			memcpy(T, Temp, sizeof(T));
		}
	}
}

void Init()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> T[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> R[i][j];
		}
	}

	cin >> M;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Init();
	BF(0, 0);

	cout << Max;
}