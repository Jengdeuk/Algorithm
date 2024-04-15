#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const char Dir[4] = { 'L', 'R', 'U', 'D' };

int N, M;
p Hole, Red, Blue;
char Board[10][10];

queue<pair<int, pair<p, p>>> SQ;
bool Visited[10][10][10][10];

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

void Render(bool bDraw)
{
	if (bDraw)
	{
		Board[Red.first][Red.second] = 'R';
		Board[Blue.first][Blue.second] = 'B';
		Board[Hole.first][Hole.second] = 'O';
	}
	else
	{
		Board[Red.first][Red.second] = '.';
		Board[Blue.first][Blue.second] = '.';
		Board[Hole.first][Hole.second] = 'O';
	}
}

int BFS()
{
	Visited[Red.first][Red.second][Blue.first][Blue.second] = true;
	SQ.emplace(0, pair<p, p>(Red, Blue));
	while (!SQ.empty())
	{
		int N = SQ.front().first;
		Red = SQ.front().second.first;
		Blue = SQ.front().second.second;
		Render(true);
		SQ.pop();
		
		if (Fall(Red) && !Fall(Blue))
		{
			return N;
		}
		else if (Fall(Red) || Fall(Blue))
		{
			Render(false);
			continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			p TempRed = Red, TempBlue = Blue;
			MoveBoard(i);
			if (!Visited[Red.first][Red.second][Blue.first][Blue.second])
			{
				Visited[Red.first][Red.second][Blue.first][Blue.second] = true;
				SQ.emplace(N + 1, pair<p, p>(Red, Blue));
			}

			Render(false);
			Red = TempRed;
			Blue = TempBlue;
			Render(true);
		}

		Render(false);
	}

	return -1;
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
				Board[i][j] = '.';
				Red = p(i, j);
				break;

			case 'B':
				Board[i][j] = '.';
				Blue = p(i, j);
				break;
			}
		}
	}

	cout << BFS();
}