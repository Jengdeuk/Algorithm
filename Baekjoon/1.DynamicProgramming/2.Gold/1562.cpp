#include <iostream>
using namespace std;

const int Mod = 1e9;

int N;
int DP[10][101][1 << 10];

int Get(int Num, int Digit, int Bit)
{
	if (DP[Num][Digit][Bit] != 0)
	{
		return DP[Num][Digit][Bit];
	}
	
	if (Digit == N)
	{
		if (Bit == (1 << 10) - 1)
		{
			return 1;
		}

		return 0;
	}

	int Sum = 0;

	if (Num > 0)
	{
		int Cur = Num - 1;
		Sum += Get(Cur, Digit + 1, Bit | (1 << Cur));
	}

	if (Num < 9)
	{
		int Cur = Num + 1;
		Sum += Get(Cur, Digit + 1, Bit | (1 << Cur));
	}

	Sum %= Mod;
	return DP[Num][Digit][Bit] = Sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	int Cnt = 0;
	for (int i = 1; i <= 9; ++i)
	{
		Cnt += Get(i, 1, 1 << i);
		Cnt %= Mod;
	}

	cout << Cnt;
}