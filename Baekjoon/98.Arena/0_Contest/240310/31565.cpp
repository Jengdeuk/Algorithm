#include <iostream>
using namespace std;

const int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int Y1, M1, D1, Y2, M2, D2;
int Day1, Day2;

int T, N;
int DP[101][10001];

bool YearCheck[3001];

void Initialize()
{
	for (int i = 1990; i <= 3000; ++i)
	{
		if (i % 400 == 0
			|| (i % 100 != 0 && i % 4 == 0))
		{
			YearCheck[i] = true;
		}
	}

	cin >> Y1 >> M1 >> D1 >> Y2 >> M2 >> D2;
	cin >> T >> N;
}

void DynamicProgramming()
{
	for (int i = 1; i <= N; ++i)
	{
		int Command, Cost, Value;
		cin >> Command >> Cost >> Value;
		if (Command == 3)
		{
			Value *= 30;
		}

		for (int C = 0; C <= T; ++C)
		{
			if (Cost <= C)
			{
				int NonGet = DP[i - 1][C];
				int Get = DP[i - 1][C - Cost] + Value;
				if (NonGet >= Get)
				{
					DP[i][C] = DP[i - 1][C];
				}
				else
				{
					DP[i][C] = DP[i - 1][C - Cost] + Value;
				}
			}
			else
			{
				DP[i][C] = DP[i - 1][C];
			}
		}
	}
}

void GetDays()
{
	Day1 = D1;
	for (int i = 1990; i < Y1; ++i)
	{
		if (!YearCheck[i])
		{
			Day1 += 365;
		}
		else
		{
			Day1 += 366;
		}
	}

	for (int i = 1; i < M1; ++i)
	{
		if (i == 2 && YearCheck[Y1])
		{
			Day1 += 29;
		}
		else
		{
			Day1 += MonthDay[i];
		}
	}

	Day2 = D2;
	for (int i = 1990; i < Y2; ++i)
	{
		if (!YearCheck[i])
		{
			Day2 += 365;
		}
		else
		{
			Day2 += 366;
		}
	}

	for (int i = 1; i < M2; ++i)
	{
		if (i == 2 && YearCheck[Y2])
		{
			Day2 += 29;
		}
		else
		{
			Day2 += MonthDay[i];
		}
	}

	Day1 += DP[N][T];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Initialize();
	DynamicProgramming();
	GetDays();
	cout << abs(Day1 - Day2);
}