#include <iostream>
using namespace std;

bool Little[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		int Num;
		cin >> Num;

		if (Num == -1)
		{
			break;
		}

		int Sum = 0;
		for (int i = 1; i < Num; ++i)
		{
			if (Num % i != 0)
			{
				continue;
			}

			Sum += i;
			Little[i] = true;
		}

		if (Sum == Num)
		{
			cout << Num << " = 1";
			for (int i = 2; i < Num; ++i)
			{
				if (Little[i])
				{
					cout << " + " << i;
					Little[i] = false;
				}
			}
			cout << '\n';
		}
		else
		{
			cout << Num << " is NOT perfect.\n";
			for (int i = 1; i < Num; ++i)
			{
				Little[i] = false;
			}
		}
	}
}