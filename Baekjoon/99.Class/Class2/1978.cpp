#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> Sequence;

bool IsPrime(int Value)
{
	if (Value == 1)
	{
		return false;
	}

	if (Value == 2)
	{
		return true;
	}

	for (int i = 2; i < sqrtf(Value) + 1; ++i)
	{
		if (Value % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int N;
	cin >> N;

	Sequence.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Number;
		cin >> Number;
		Sequence.emplace_back(Number);
	}

	cout << count_if(Sequence.begin(), Sequence.end(), IsPrime);
}