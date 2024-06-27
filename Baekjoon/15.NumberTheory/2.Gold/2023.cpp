#include <iostream>
#include <cmath>
using namespace std;

int N;
int S[8];

bool Check(int Num)
{
	if (Num < 2)
	{
		return false;
	}

	for (int i = 2; i < sqrt(Num) + 1; ++i)
	{
		if (i == Num)
		{
			continue;
		}

		if (Num % i == 0)
		{
			return false;
		}
	}

	return true;
}

bool IsPrime(int Idx)
{
	for (int i = 0; i < Idx; ++i)
	{
		int Number = 0;
		for (int j = 0; j <= i; ++j)
		{
			int Digit = pow(10, i - j);
			Number += S[j] * Digit;
		}

		if (!Check(Number))
		{
			return false;
		}
	}

	return true;
}

void Backtracking(int Idx)
{
	if (Idx == N)
	{
		for (int i = 0; i < N; ++i)
		{
			cout << S[i];
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		S[Idx] = i;

		if (IsPrime(Idx + 1))
		{
			Backtracking(Idx + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	Backtracking(0);
}