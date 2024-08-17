#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const char SRP[3] = { 'S', 'R', 'P' };

int N, M, K;
int F[50][50];

bool D[50];
int S[50];
int Min = 51, Ans[50];

int SurvNum()
{
	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		if (!D[i])
		{
			++Cnt;
		}
	}

	return Cnt;
}

bool IsAllSame(int R)
{
	int Cnt[3] = {};
	for (int i = 0; i < N; ++i)
	{
		if (D[i])
		{
			continue;
		}

		++Cnt[F[i][R]];
	}

	return ((Cnt[0] == 0 && Cnt[1] == 0) || (Cnt[1] == 0 && Cnt[2] == 0) || (Cnt[2] == 0 && Cnt[0] == 0));
}

void Kill(int R, int W)
{
	for (int i = 0; i < N; ++i)
	{
		if (D[i] || (W < 2 && F[i][R] == W + 1) || (W == 2 && F[i][R] == 0))
		{
			continue;
		}

		D[i] = true;
	}
}

void Round(int R)
{
	int Surv = SurvNum();
	if (Surv == 0)
	{
		return;
	}

	if (Surv <= K)
	{
		if (R < Min)
		{
			Min = R;
			memcpy(Ans, S, sizeof(Ans));
		}

		return;
	}

	if (IsAllSame(R))
	{
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		bool Temp[50] = {};
		memcpy(Temp, D, sizeof(Temp));

		S[R] = i;
		Kill(R, i);
		Round(R + 1);

		memcpy(D, Temp, sizeof(D));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char Ch;
			cin >> Ch;
			switch (Ch)
			{
			case 'S':
				F[i][j] = 0;
				break;

			case 'R':
				F[i][j] = 1;
				break;

			case 'P':
				F[i][j] = 2;
				break;
			}
		}
	}

	Round(0);

	if (Min < 51)
	{
		cout << Min << '\n';
		for (int i = 0; i < Min; ++i)
		{
			cout << SRP[Ans[i]];
		}
	}
	else
	{
		cout << -1;
	}
}