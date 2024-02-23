#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MaxSize = 9;

bool bFound;
int Solution[MaxSize][MaxSize];

int Board[MaxSize][MaxSize];
bool CheckRow[MaxSize][MaxSize + 1];
bool CheckCol[MaxSize][MaxSize + 1];
bool CheckArea[MaxSize][MaxSize + 1];

void Init()
{
	for (int i = 0; i < MaxSize; ++i)
	{
		string Line;
		cin >> Line;
		for (int j = 0; j < MaxSize; ++j)
		{
			int Num = Line[j] - '0';
			Board[i][j] = Num;
			CheckRow[i][Num] = true;
			CheckCol[j][Num] = true;
			CheckArea[(i / 3) * 3 + (j / 3)][Num] = true;
		}
	}
}

void Print()
{
	for (int i = 0; i < MaxSize; ++i)
	{
		for (int j = 0; j < MaxSize; ++j)
		{
			cout << Solution[i][j];
		}
		cout << '\n';
	}
}

void DFS(int Count)
{
	int Row = Count / MaxSize;
	int Col = Count % MaxSize;

	if (bFound || Count == 81)
	{
		bFound = true;
		memcpy(Solution, Board, sizeof(Solution));
		return;
	}

	if (Board[Row][Col] == 0)
	{
		for (int Num = 1; Num <= MaxSize; ++Num)
		{
			if (CheckRow[Row][Num] == false
				&& CheckCol[Col][Num] == false
				&& CheckArea[(Row / 3) * 3 + (Col / 3)][Num] == false)
			{
				Board[Row][Col] = Num;
				CheckRow[Row][Num] = true;
				CheckCol[Col][Num] = true;
				CheckArea[(Row / 3) * 3 + (Col / 3)][Num] = true;
				DFS(Count + 1);

				if (bFound)
				{
					return;
				}

				Board[Row][Col] = 0;
				CheckRow[Row][Num] = false;
				CheckCol[Col][Num] = false;
				CheckArea[(Row / 3) * 3 + (Col / 3)][Num] = false;
			}
		}
	}
	else
	{
		DFS(Count + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Init();
	DFS(0);
	Print();
}