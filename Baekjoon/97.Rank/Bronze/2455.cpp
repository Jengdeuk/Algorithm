#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Max = 0;
	int Man = 0;
	for (int i = 0; i < 4; ++i)
	{
		int Out, In;
		cin >> Out >> In;

		Man -= Out;
		Man += In;
		if (Man > Max)
		{
			Max = Man;
		}
	}

	cout << Max;
}