#include <iostream>
using namespace std;

int Paper[2187][2187];
int Num[3];

bool Check(int Row, int Col, int Size)
{
	int Comp = Paper[Row][Col];
	for (int i = Row; i < Row + Size; ++i)
	{
		for (int j = Col; j < Col + Size; ++j)
		{
			if (Paper[i][j] != Comp)
			{
				return false;
			}
		}
	}

	return true;
}

void Divide(int Row, int Col, int Size)
{
	if (Check(Row, Col, Size))
	{
		++Num[Paper[Row][Col] + 1];
		return;
	}

	int NewSize = Size / 3;
	Divide(Row, Col, NewSize);
	Divide(Row, Col + NewSize, NewSize);
	Divide(Row, Col + 2 * NewSize, NewSize);
	Divide(Row + NewSize, Col, NewSize);
	Divide(Row + NewSize, Col + NewSize, NewSize);
	Divide(Row + NewSize, Col + 2 * NewSize, NewSize);
	Divide(Row + 2 * NewSize, Col, NewSize);
	Divide(Row + 2 * NewSize, Col + NewSize, NewSize);
	Divide(Row + 2 * NewSize, Col + 2 * NewSize, NewSize);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Paper[i][j];
		}
	}

	Divide(0, 0, N);

	for (int i = 0; i < 3; ++i)
	{
		cout << Num[i] << '\n';
	}
}