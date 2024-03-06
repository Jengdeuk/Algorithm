#include <iostream>
using namespace std;

int R, C;
char Map[20][20];

char Alphabet[26];
bool Check[26];
int Max = 0;

void DFS(int Step, int Row, int Col)
{
	char Alpha = Map[Row][Col];
	if (Check[int(Alpha - 'A')])
	{
		return;
	}

	Alphabet[Step] = Alpha;
	Check[int(Alpha - 'A')] = true;
	++Step;
	if (Step > Max)
	{
		Max = Step;
	}

	// Left
	if (Col > 0)
	{
		DFS(Step, Row, Col - 1);
	}
	
	// Top
	if (Row > 0)
	{
		DFS(Step, Row - 1, Col);
	}

	// Right
	if (Col < C - 1)
	{
		DFS(Step, Row, Col + 1);
	}

	// Bottom
	if (Row < R - 1)
	{
		DFS(Step, Row + 1, Col);
	}

	Check[int(Alpha - 'A')] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> Map[i][j];
		}
	}

	DFS(0, 0, 0);

	cout << Max;
}