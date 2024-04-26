#include <iostream>
#include <cstring>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> info;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
int Map[8][8];

int C;
info Cam[8];
int Dir[8];

int Min;
int Sol[8][8];

void Scanning(int Idx, int D, int MulInverse = 1)
{
	int R = Cam[Idx].second.first, C = Cam[Idx].second.second;

	int i = 1;
	while (true)
	{
		int NR = R + DY[D] * i * MulInverse;
		int NC = C + DX[D] * i * MulInverse;
		if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1
			|| Sol[NR][NC] == 6)
		{
			break;
		}

		if (Sol[NR][NC] == 0)
		{
			Sol[NR][NC] = -1;
		}

		++i;
	}
}

int CountBlank()
{
	memcpy(Sol, Map, sizeof(Sol));

	for (int i = 0; i < C; ++i)
	{
		int D = Dir[i];
		int D2 = (D + 1 > 3) ? 0 : D + 1;

		switch (Cam[i].first)
		{
		case 1:
			Scanning(i, D);
			break;
		case 2:
			Scanning(i, D);
			Scanning(i, D, -1);
			break;
		case 3:
			Scanning(i, D);
			Scanning(i, D2);
			break;
		case 4:
			Scanning(i, D);
			Scanning(i, D, -1);
			Scanning(i, D2);
			break;
		case 5:
			Scanning(i, D);
			Scanning(i, D, -1);
			Scanning(i, D2);
			Scanning(i, D2, -1);
			break;
		}
	}

	int Cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Sol[i][j] == 0)
			{
				++Cnt;
			}
		}
	}

	return Cnt;
}

void Backtracking(int Idx)
{
	if (Idx == C)
	{
		Min = min(Min, CountBlank());
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		Dir[Idx] = i;
		Backtracking(Idx + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	Min = N * M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int Num;
			cin >> Num;
			Map[i][j] = Num;

			if (Num >= 1 && Num <= 5)
			{
				Cam[C] = info(Num, p(i, j));
				++C;
				--Min;
			}
			else if (Num == 6)
			{
				--Min;
			}
		}
	}

	Backtracking(0);

	cout << Min;
}