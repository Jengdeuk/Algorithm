#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef pair<int, int> p;

int N, M;
p Hole, Red, Blue;
char Board[10][10];

const char Dir[4] = { 'L', 'R', 'U', 'D' };
bool bClear;

bool Fall(p Ball)
{
	return (Hole.first != Ball.first || Hole.second != Ball.second) ? false : true;
}

void Horizontal(bool bLeft, bool bRed)
{
	int R, C;
	if (bRed) { R = Red.first; C = Red.second; }
	else { R = Blue.first; C = Blue.second; }
	Board[R][C] = '.';
	
	int Next = (bLeft) ? -1 : 1;
	while (((bLeft) ? (C > 1) : (C < M - 2))
			&& Board[R][C] != 'O')
	{
		if (Board[R][C + Next] == '#'
			|| Board[R][C + Next] == 'R'
			|| Board[R][C + Next] == 'B')
		{
			break;
		}

		C += Next;
	}

	if (bRed) { Board[R][C] = 'R'; Red = p(R, C); }
	else { Board[R][C] = 'B'; Blue = p(R, C); }
	Board[Hole.first][Hole.second] = 'O';
}

void Vertical(bool bUp, bool bRed)
{
	int R, C;
	if (bRed) { R = Red.first; C = Red.second; }
	else { R = Blue.first; C = Blue.second; }
	Board[R][C] = '.';

	int Next = (bUp) ? -1 : 1;
	while (((bUp) ? (R > 1) : (R < N - 2))
		&& Board[R][C] != 'O')
	{
		if (Board[R + Next][C] == '#'
			|| Board[R + Next][C] == 'R'
			|| Board[R + Next][C] == 'B')
		{
			break;
		}

		R += Next;
	}

	if (bRed) { Board[R][C] = 'R'; Red = p(R, C); }
	else { Board[R][C] = 'B'; Blue = p(R, C); }
	Board[Hole.first][Hole.second] = 'O';
}

void MoveBoard(int Direction)
{
	switch (Direction)
	{
	case 0:
		if (Red.second <= Blue.second)
		{
			Horizontal(true, true);
			Horizontal(true, false);
		}
		else
		{
			Horizontal(true, false);
			Horizontal(true, true);
		}
		break;
	case 1:
		if (Red.second >= Blue.second)
		{
			Horizontal(false, true);
			Horizontal(false, false);
		}
		else
		{
			Horizontal(false, false);
			Horizontal(false, true);
		}
		break;
	case 2:
		if (Red.first <= Blue.first)
		{
			Vertical(true, true);
			Vertical(true, false);
		}
		else
		{
			Vertical(true, false);
			Vertical(true, true);
		}
		break;
	case 3:
		if (Red.first >= Blue.first)
		{
			Vertical(false, true);
			Vertical(false, false);
		}
		else
		{
			Vertical(false, false);
			Vertical(false, true);
		}
		break;
	}
}

bool Same(p TempRed, p TempBlue)
{
	if (TempRed.first != Red.first
		|| TempRed.second != Red.second
		|| TempBlue.first != Blue.first
		|| TempBlue.second != Blue.second)
	{
		return false;
	}

	return true;
}

void Backtracking(int Idx)
{
	if (Idx == 11)
	{
		return;
	}
	else if (Fall(Red) && !Fall(Blue))
	{
		bClear = true;
		return;
	}
	else if (Fall(Red) || Fall(Blue))
	{
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		p TempRed = Red, TempBlue = Blue;
		char Temp[10][10];
		memcpy(Temp, Board, sizeof(Temp));
		MoveBoard(i);
		if (Same(TempRed, TempBlue))
		{
			continue;
		}

		Backtracking(Idx + 1);
		if (bClear)
		{
			return;
		}

		Red = TempRed;
		Blue = TempBlue;
		memcpy(Board, Temp, sizeof(Board));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string Str;
		cin >> Str;
		
		for (int j = 0; j < M; ++j)
		{
			Board[i][j] = Str[j];
			switch (Str[j])
			{
			case 'O':
				Hole = p(i, j);
				break;

			case 'R':
				Red = p(i, j);
				break;

			case 'B':
				Blue = p(i, j);
				break;
			}
		}
	}

	Backtracking(0);

	cout << bClear;
}