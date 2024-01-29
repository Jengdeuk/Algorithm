#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	long long r = 31, M = 1234567891, Alpha = 96;

	int L;
	cin >> L;

	string Sequence;
	cin >> Sequence;

	long long Sum = 0;
	for (int i = 0; i < L; ++i)
	{
		long long Multiplier = 1;
		for (int j = 0; j < i; ++j)
		{
			Multiplier *= r;
			Multiplier %= M;
		}

		long long Number = Sequence[i];
		Sum += ((Number - Alpha) * Multiplier) % M;
	}

	cout << Sum % M;
}