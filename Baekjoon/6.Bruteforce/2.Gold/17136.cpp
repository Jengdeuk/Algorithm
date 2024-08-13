#include <iostream>
#include <cstring>
using namespace std;

bool Board[10][10];
int Used[6];
int Min = 26;

bool CanPaste(int Size, int R, int C)
{
	if (R > 10 - Size || C > 10 - Size)
	{
		return false;
	}

	for (int i = R; i < R + Size; ++i)
	{
		for (int j = C; j < C + Size; ++j)
		{
			if (!Board[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

void Paste(bool bChangeValue, int Size, int R, int C)
{
	for (int i = R; i < R + Size; ++i)
	{
		for (int j = C; j < C + Size; ++j)
		{
			Board[i][j] = bChangeValue;
		}
	}
}

void Btk(int Idx)
{
	if (Idx == 100)
	{
		int Cnt = 0;
		for (int i = 1; i <= 5; ++i)
		{
			Cnt += Used[i];
		}

		Min = min(Min, Cnt);
		return;
	}

	int R = Idx / 10;
	int C = Idx % 10;
	if (Board[R][C] == false)
	{
		Btk(Idx + 1);
		return;
	}

	for (int i = 5; i >= 1; --i)
	{
		if (Used[i] >= 5 || !CanPaste(i, R, C))
		{
			continue;
		}

		Paste(false, i, R, C);
		++Used[i];

		Btk(Idx + 1);

		Paste(true, i, R, C);
		--Used[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cin >> Board[i][j];
		}
	}

	Btk(0);

	if (Min < 26)
	{
		cout << Min;
	}
	else
	{
		cout << -1;
	}
}