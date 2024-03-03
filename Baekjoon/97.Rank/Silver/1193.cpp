#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int X;
	cin >> X;

	int Row = 1, Col = 1;

	bool bUp = true;
	int Cnt = 2;
	for (int i = 1; i < X; ++i)
	{

		if (bUp)
		{
			Row = (Row - 1 < 1) ? 1 : Row - 1;
			++Col;
		}
		else
		{
			Col = (Col - 1 < 1) ? 1 : Col - 1;
			++Row;
		}

		if (Col == Cnt || Row == Cnt)
		{
			bUp = !bUp;
			++Cnt;
		}
	}

	cout << Row << '/' << Col;
}