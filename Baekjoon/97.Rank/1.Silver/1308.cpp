#include <iostream>
using namespace std;

const int MD[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool IsLeapYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int SY, SM, SD, EY, EM, ED;
	cin >> SY >> SM >> SD >> EY >> EM >> ED;
	if (EY - SY > 1000 || (EY - SY == 1000 && (SM < EM || (SM == EM && SD <= ED))))
	{
		cout << "gg";
		return 0;
	}

	int Day = 0;

	int Y = SY, M = SM, D = SD;
	while (Y < EY)
	{
		int Cur = 0;
		if (IsLeapYear(Y))
		{
			for (int i = 1; i < M; ++i)
			{
				if (i == 2)
				{
					Cur += 29;
				}
				else
				{
					Cur += MD[i - 1];
				}
			}
			Cur += D;

			Day += 366 - Cur;
		}
		else
		{
			for (int i = 1; i < M; ++i)
			{
				Cur += MD[i - 1];
			}
			Cur += D;

			Day += 365 - Cur;
		}

		++Y, M = 0, D = 0;
	}

	int Cur = 0;
	for (int i = 1; i < M; ++i)
	{
		if (i == 2 && IsLeapYear(Y))
		{
			Cur += 29;
		}
		else
		{
			Cur += MD[i - 1];
		}
	}
	Cur += D;

	for (int i = 1; i < EM; ++i)
	{
		if (i == 2 && IsLeapYear(Y))
		{
			Day += 29;
		}
		else
		{
			Day += MD[i - 1];
		}
	}
	Day += ED - Cur;

	cout << "D-" << Day;
}