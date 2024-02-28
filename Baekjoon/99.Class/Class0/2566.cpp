#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Max = 0;
	int Row = 1, Col = 1;

	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			int Num;
			cin >> Num;

			if (Num > Max)
			{
				Max = Num;
				Row = i;
				Col = j;
			}
		}
	}

	cout << Max << '\n';
	cout << Row << ' ' << Col;
}