#include <iostream>
#include <list>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> info;

const int DX[4] = { 0, 0, 1, -1 };
const int DY[4] = { -1, 1, 0, 0 };

int N, M, K;
int Map[100][100];
list<int> Comp[100][100];
p Loc[10001];
info Shark[10001];

void Init()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			Map[i][j] = -1;
		}
	}

	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		int R, C, S, D, Z;
		cin >> R >> C >> S >> D >> Z;

		Loc[i] = p(R - 1, C - 1);
		Shark[i] = info(Z, p(S, D - 1));
		Comp[R - 1][C - 1].emplace_back(i);
	}
}

void Move()
{
	list<int> Temp[100][100];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Comp[i][j].empty())
			{
				continue;
			}

			for (const int& Index : Comp[i][j])
			{
				int R = Loc[Index].first;
				int C = Loc[Index].second;
				int S = Shark[Index].second.first;
				int D = Shark[Index].second.second;

				if (D == 0 || D == 1)
				{
					S %= (N - 1) * 2;
					for (int i = 0; i < S; ++i)
					{
						R += DY[D];
						if (R < 0)
						{
							R = 1;
							D = 1;
						}
						else if (R > N - 1)
						{
							R = N - 2;
							D = 0;
						}
					}
				}
				else
				{
					S %= (M - 1) * 2;
					for (int i = 0; i < S; ++i)
					{
						C += DX[D];
						if (C < 0)
						{
							C = 1;
							D = 2;
						}
						else if (C > M - 1)
						{
							C = M - 2;
							D = 3;
						}
					}
				}

				Loc[Index] = p(R, C);
				Shark[Index].second.second = D;
				Temp[R][C].emplace_back(Index);
			}

			Comp[i][j].clear();
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			Comp[i][j] = Temp[i][j];
		}
	}
}

void Eat()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Comp[i][j].empty())
			{
				Map[i][j] = -1;
				continue;
			}

			int Max = -1;
			int MaxIndex = -1;
			for (const int& S : Comp[i][j])
			{
				if (Shark[S].first > Max)
				{
					Max = Shark[S].first;
					MaxIndex = S;
				}
			}

			Comp[i][j].clear();
			Comp[i][j].emplace_back(MaxIndex);
			Map[i][j] = MaxIndex;
		}
	}
}

int Solve()
{
	int Size = 0;
	for (int C = 0; C < M; ++C)
	{
		for (int R = 0; R < N; ++R)
		{
			int i = Map[R][C];
			if (i != -1)
			{
				Size += Shark[i].first;
				Comp[R][C].clear();
				break;
			}
		}

		Move();
		Eat();
	}

	return Size;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Init();
	Eat();
	cout << Solve();
}