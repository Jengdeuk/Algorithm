#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	if (N == 1)
	{
		cout << 1;
		return 0;
	}

	int Pass = 2;
	int MaxCount = 6;
	int Count = 0;
	for (int i = 2; i <= N; ++i)
	{
		++Count;
		if (Count > MaxCount)
		{
			Count = 1;
			MaxCount += 6;
			++Pass;
		}
	}

	cout << Pass;
}