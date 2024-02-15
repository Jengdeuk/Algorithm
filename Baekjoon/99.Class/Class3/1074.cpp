#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, R, C;
int SearchNum;

void DivideSearch(int StartRow, int StartCol, int Size)
{
	if ((R < StartRow || R > StartRow + Size)
		|| (C < StartCol || C > StartCol + Size))
	{
		SearchNum += Size * Size;
		return;
	}

	if (Size == 2)
	{
		for (int i = StartRow; i < StartRow + Size; ++i)
		{
			for (int j = StartCol; j < StartCol + Size; ++j)
			{
				if (i == R && j == C)
				{
					cout << SearchNum;
					return;
				}

				++SearchNum;
			}
		}

		return;
	}

	DivideSearch(StartRow, StartCol, Size / 2);
	DivideSearch(StartRow, StartCol + Size / 2, Size / 2);
	DivideSearch(StartRow + Size / 2, StartCol, Size / 2);
	DivideSearch(StartRow + Size / 2, StartCol + Size / 2, Size / 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> R >> C;

	int Size = pow(2, N);
	DivideSearch(0, 0, Size);
}