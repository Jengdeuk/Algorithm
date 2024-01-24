#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	bool bFoundNumber = false;
	for (int i = 0; i < N; ++i)
	{
		int Sum = 0;
		int Number = i;
		Sum += Number;
		while (Number != 0)
		{
			Sum += Number % 10;
			Number /= 10;
		}

		if (Sum == N)
		{
			bFoundNumber = true;
			cout << i;
			break;
		}
	}

	if (!bFoundNumber)
	{
		cout << 0;
	}
}