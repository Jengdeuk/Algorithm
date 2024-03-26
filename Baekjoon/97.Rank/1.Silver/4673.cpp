#include <iostream>
using namespace std;

bool Self[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 1; i <= 10000; ++i)
	{
		Self[i] = true;
	}

	for (int i = 1; i <= 10000; ++i)
	{
		int Num = i;
		int Sum = Num;
		while (Num != 0)
		{
			Sum += Num % 10;
			Num /= 10;
		}

		if (Sum <= 10000)
		{
			Self[Sum] = false;
		}
	}

	for (int i = 1; i <= 10000; ++i)
	{
		if (Self[i])
		{
			cout << i << '\n';
		}
	}
}