#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int L, R, K;
	cin >> L >> R >> K;

	int Cnt = 0;
	switch (K)
	{
	case 2:
		if (R <= 3)
		{
			Cnt = (R == 3);
		}
		else
		{
			if (L > 3)
			{
				Cnt = R - L + 1;
			}
			else
			{
				Cnt = R - 2;
			}
		}
		break;

	case 3:
		if (R <= 6)
		{
			Cnt = (R == 6);
		}
		else
		{
			if (L > 6)
			{
				Cnt = R / 3 - L / 3 + (L % 3 == 0);
			}
			else
			{
				Cnt = R / 3 - 1;
			}
		}
		break;

	case 4:
		if (R <= 12)
		{
			Cnt = (R >= 10 && L <= 10);
		}
		else
		{
			if (L > 12)
			{
				Cnt = R / 2 - L / 2 + (L % 2 == 0);
			}
			else if (L == 11)
			{
				Cnt = R / 2 - 6;
			}
			else
			{
				Cnt = R / 2 - 5;
			}
		}
		break;

	case 5:
		if (R <= 15)
		{
			Cnt = (R == 15);
		}
		else
		{
			if (L > 15)
			{
				Cnt = R / 5 - L / 5 + (L % 5 == 0);
			}
			else
			{
				Cnt = R / 5 - 2;
			}
		}
		break;
	}

	cout << Cnt;
}