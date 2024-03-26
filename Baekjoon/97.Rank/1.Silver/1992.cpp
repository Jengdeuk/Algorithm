#include <iostream>
#include <string>
using namespace std;

bool Image[64][64];

bool CheckOneColor(int Row, int Col, int Size)
{
	bool bStandard = Image[Row][Col];

	for (int i = Row; i < Row + Size; ++i)
	{
		for (int j = Col; j < Col + Size; ++j)
		{
			if (Image[i][j] != bStandard)
			{
				return false;
			}
		}
	}

	return true;
}

void QuadTree(int Row, int Col, int Size)
{
	if (CheckOneColor(Row, Col, Size))
	{
		cout << Image[Row][Col];
		return;
	}

	cout << '(';

	int Half = Size / 2;

	// LT
	if (CheckOneColor(Row, Col, Half))
	{
		cout << Image[Row][Col];
	}
	else
	{
		QuadTree(Row, Col, Half);
	}

	// RT
	if (CheckOneColor(Row, Col + Half, Half))
	{
		cout << Image[Row][Col + Half];
	}
	else
	{
		QuadTree(Row, Col + Half, Half);
	}

	// LB
	if (CheckOneColor(Row + Half, Col, Half))
	{
		cout << Image[Row + Half][Col];
	}
	else
	{
		QuadTree(Row + Half, Col, Half);
	}

	// RB
	if (CheckOneColor(Row + Half, Col + Half, Half))
	{
		cout << Image[Row + Half][Col + Half];
	}
	else
	{
		QuadTree(Row + Half, Col + Half, Half);
	}

	cout << ')';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; ++i)
	{
		string Str;
		getline(cin, Str);
		for (int j = 0; j < N; ++j)
		{
			Image[i][j] = Str[j] - '0';
		}
	}

	QuadTree(0, 0, N);
}