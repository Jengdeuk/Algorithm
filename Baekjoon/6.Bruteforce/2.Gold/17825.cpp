#include <iostream>
#include <vector>
using namespace std;

const int maxTurn = 10;

const int score[33] =
{
	0, 2, 4, 6, 8,
	10, 12, 14, 16, 18,
	20, 22, 24, 26, 28,
	30, 32, 34, 36, 38,
	13, 16, 19, 22, 24,
	25, 28, 27, 26, 30,
	35, 40, 0,
};

const int dst[33] =
{
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	11, 12, 13, 14, 15, 16, 17, 18, 19, 31,
	21, 22, 25, 24, 25, 29, 27, 28, 25, 30,
	31, 32, 32
};

const int udst[33] =
{
	0, 0, 0, 0, 0, 20, 0, 0, 0, 0,
	23, 0, 0, 0, 0, 26, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0
};

int turn[maxTurn];
int maxScore;

void backtracking(int curTurn, int curScore, vector<int> pawn, vector<int> board)
{
	if (curTurn == maxTurn)
	{
		maxScore = max(maxScore, curScore);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (pawn[i] == 32)
			continue;

		int srcPos = pawn[i];
		int dstPos = (udst[srcPos] > 0 ? udst[srcPos] : dst[srcPos]);
		for (int j = 1; j < turn[curTurn]; ++j)
			dstPos = dst[dstPos];

		if (dstPos < 32 && board[dstPos] > 0)
			continue;

		pawn[i] = dstPos;
		--board[srcPos];
		++board[dstPos];

		int nxtScore = curScore + score[dstPos];
		backtracking(curTurn + 1, nxtScore, pawn, board);

		pawn[i] = srcPos;
		++board[srcPos];
		--board[dstPos];
	}
}

void initialize()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < maxTurn; ++i)
		cin >> turn[i];
}

void play()
{
	vector<int> startBoard(33, 0);
	startBoard[0] = 4;
	startBoard[32] = 0;
	backtracking(0, 0, vector<int>(4, 0), startBoard);
	cout << maxScore;
}

int main()
{
	initialize();
	play();
}