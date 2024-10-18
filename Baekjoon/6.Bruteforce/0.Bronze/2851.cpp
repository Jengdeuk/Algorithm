#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	bool bStop = false;
	int Sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		int Num;
		cin >> Num;

		if (bStop)
		{
			continue;
		}

		if (abs(100 - (Sum + Num)) > abs(100 - Sum))
		{
			bStop = true;
			continue;
		}

		Sum += Num;
	}

	cout << Sum;
}