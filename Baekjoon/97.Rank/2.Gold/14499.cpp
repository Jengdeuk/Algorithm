#include <iostream>
using namespace std;

const int DX[4] = { 1, -1, 0, 0 };
const int DY[4] = { 0, 0, -1, 1 };
const int DUp[7][7][2] =
{
	{ { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, },
	{ { 0, 0 }, { 0, 0 }, { 3, 4 }, { 5, 2 }, { 2, 5 }, { 4, 3 }, { 0, 0 }, },
	{ { 0, 0 }, { 4, 3 }, { 0, 0 }, { 1, 6 }, { 6, 1 }, { 0, 0 }, { 3, 4 }, },
	{ { 0, 0 }, { 2, 5 }, { 6, 1 }, { 0, 0 }, { 0, 0 }, { 1, 6 }, { 5, 2 }, },
	{ { 0, 0 }, { 5, 2 }, { 1, 6 }, { 0, 0 }, { 0, 0 }, { 6, 1 }, { 2, 5 }, },
	{ { 0, 0 }, { 3, 4 }, { 0, 0 }, { 6, 1 }, { 1, 6 }, { 0, 0 }, { 4, 3 }, },
	{ { 0, 0 }, { 0, 0 }, { 4, 3 }, { 2, 5 }, { 5, 2 }, { 3, 4 }, { 0, 0 }, }
};

int N, M;
int Map[20][20];

int Up, Right;
int Dice[7];

bool IsInvalid(int R, int C)
{
	return (R < 0 || R > N - 1 || C < 0 || C > M - 1);
}

void RollDice(int Dir)
{
	int SavedUp = Up, SavedRight = Right;

	switch (Dir)
	{
	case 0:
		Up = 7 - SavedRight;
		Right = SavedUp;
		break;

	case 1:
		Up = SavedRight;
		Right = 7 - SavedUp;
		break;

	case 2:
	case 3:
		Up = DUp[SavedUp][SavedRight][Dir - 2];
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	int R, C, K;
	cin >> R >> C >> K;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Map[i][j];
		}
	}

	Up = 1, Right = 3;
	for (int i = 0; i < K; ++i)
	{
		int Dir;
		cin >> Dir;
		--Dir;

		int NR = R + DY[Dir];
		int NC = C + DX[Dir];
		if (IsInvalid(NR, NC))
		{
			continue;
		}

		RollDice(Dir);

		R = NR, C = NC;
		if (Map[R][C] == 0)
		{
			Map[R][C] = Dice[7 - Up];
		}
		else
		{
			Dice[7 - Up] = Map[R][C];
			Map[R][C] = 0;
		}

		cout << Dice[Up] << '\n';
	}
}