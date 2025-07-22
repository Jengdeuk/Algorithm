#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int DX[4] = { 1, 0, -1, 0 };
const int DY[4] = { 0, 1, 0, -1 };

int N, M, B[20][20], S[20][20];
bool V[20][20];

int Dir, Dice[4][3] =
{
	{ 0, 2, 0 },
	{ 4, 1, 3 },
	{ 0, 5, 0 },
	{ 0, 6, 0 }
};

void ChangeDirection()
{
	switch (Dir)
	{
	case 0:
		Dir = 2;
		break;
	case 1:
		Dir = 3;
		break;
	case 2:
		Dir = 0;
		break;
	case 3:
		Dir = 1;
		break;
	}
}

int GetBottomNumber()
{
	return Dice[3][1];
}

void RollDice(int Dir)
{
	switch (Dir)
	{
	case 0:
	{
		int Temp = Dice[3][1];
		Dice[3][1] = Dice[1][2];
		Dice[1][2] = Dice[1][1];
		Dice[1][1] = Dice[1][0];
		Dice[1][0] = Temp;
	}
	break;
	case 1:
	{
		int Temp = Dice[3][1];
		Dice[3][1] = Dice[2][1];
		Dice[2][1] = Dice[1][1];
		Dice[1][1] = Dice[0][1];
		Dice[0][1] = Temp;
	}
	break;
	case 2:
	{
		int Temp = Dice[3][1];
		Dice[3][1] = Dice[1][0];
		Dice[1][0] = Dice[1][1];
		Dice[1][1] = Dice[1][2];
		Dice[1][2] = Temp;
	}
	break;
	case 3:
	{
		int Temp = Dice[3][1];
		Dice[3][1] = Dice[0][1];
		Dice[0][1] = Dice[1][1];
		Dice[1][1] = Dice[2][1];
		Dice[2][1] = Temp;
	}
	break;
	}
}

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M);
}

void BFS(int SR, int SC)
{
	int Cnt = 0;

	queue<p> Q, SQ;
	V[SR][SC] = true;
	Q.emplace(SR, SC);
	SQ.emplace(SR, SC);
	while (Q.empty() == false)
	{
		int R = Q.front().first;
		int C = Q.front().second;
		Q.pop();

		Cnt++;

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NR, NC) && B[NR][NC] == B[R][C] && V[NR][NC] == false)
			{
				V[NR][NC] = true;
				Q.emplace(NR, NC);
				SQ.emplace(NR, NC);
			}
		}
	}

	Cnt = B[SR][SC] * Cnt;

	while (SQ.empty() == false)
	{
		int R = SQ.front().first;
		int C = SQ.front().second;
		SQ.pop();

		S[R][C] = Cnt;
	}
}

void InitScoreMatrix()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (V[i][j] == false)
			{
				BFS(i, j);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	int K;
	cin >> K;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> B[i][j];
		}
	}

	InitScoreMatrix();

	int Score = 0;
	int R = 0, C = 0;
	while (K--)
	{
		if (IsValid(R + DY[Dir], C + DX[Dir]) == false)
		{
			ChangeDirection();
		}

		R += DY[Dir];
		C += DX[Dir];
		RollDice(Dir);

		Score += S[R][C];

		int DiceNum = GetBottomNumber();
		if (DiceNum > B[R][C])
		{
			Dir = (Dir == 3 ? 0 : Dir + 1);
		}
		else if (DiceNum < B[R][C])
		{
			Dir = (Dir == 0 ? 3 : Dir - 1);
		}
	}

	cout << Score;
}