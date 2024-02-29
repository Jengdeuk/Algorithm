#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Lines;

int main()
{
	int K, N;
	cin >> K >> N;

	Lines.reserve(K);
	for (int i = 0; i < K; ++i)
	{
		int Line;
		cin >> Line;
		Lines.emplace_back(Line);
	}

	int Result = 0;
	long long Length = 0;
	long long MinLength = 1;
	long long MaxLength = *max_element(Lines.begin(), Lines.end());
	while (MinLength <= MaxLength)
	{
		Length = (MinLength + MaxLength) / 2;

		int Count = 0;
		for (const int& Line : Lines)
		{
			Count += Line / Length;
		}

		if (Count < N)
		{
			MaxLength = Length - 1;
		}
		else
		{
			Result = Length;
			MinLength = Length + 1;
		}
	}

	cout << Result;
}