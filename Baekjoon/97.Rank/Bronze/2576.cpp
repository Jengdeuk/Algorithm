#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Sum = 0;
	int Min = 100;
	for (int i = 0; i < 7; ++i)
	{
		int Num;
		cin >> Num;
		if (Num % 2 == 1)
		{
			Sum += Num;
			if (Num < Min)
			{
				Min = Num;
			}
		}
	}

	if (Sum == 0)
	{
		cout << -1;
	}
	else
	{
		cout << Sum << '\n';
		cout << Min;
	}
}