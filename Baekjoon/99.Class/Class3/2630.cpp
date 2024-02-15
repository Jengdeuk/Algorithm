#include <iostream>
using namespace std;

int Paper[128][128];
int CountWhite;
int CountBlue;

void DividePaper(int StartRow, int StartCol, int Size)
{
	bool bDivide = false;
	int ColorCheck = -1;

	for (int i = StartRow; i < StartRow + Size; ++i)
	{
		for (int j = StartCol; j < StartCol + Size; ++j)
		{
			if ((ColorCheck == 0 && Paper[i][j] == 1)
				||
				(ColorCheck == 1 && Paper[i][j] == 0))
			{
				bDivide = true;
				break;
			}

			ColorCheck = Paper[i][j];
		}

		if (bDivide)
		{
			break;
		}
	}

	if (bDivide)
	{
		DividePaper(StartRow, StartCol, Size / 2);
		DividePaper(StartRow + Size / 2, StartCol, Size / 2);
		DividePaper(StartRow, StartCol + Size / 2, Size / 2);
		DividePaper(StartRow + Size / 2, StartCol + Size / 2, Size / 2);
	}
	else
	{
		if (ColorCheck == 0)
		{
			++CountWhite;
		}
		else if (ColorCheck == 1)
		{
			++CountBlue;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Paper[i][j];
		}
	}

	DividePaper(0, 0, N);

	cout << CountWhite << '\n';
	cout << CountBlue << '\n';
}