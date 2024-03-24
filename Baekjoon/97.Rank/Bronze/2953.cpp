#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Index = 0;
	int Max = 0;
	for (int i = 1; i <= 5; ++i)
	{
		int Sum = 0;
		for (int j = 0; j < 4; ++j)
		{
			int Num;
			cin >> Num;
			Sum += Num;
		}

		if (Sum > Max)
		{
			Index = i;
			Max = Sum;
		}
	}

	cout << Index << ' ' << Max;
}