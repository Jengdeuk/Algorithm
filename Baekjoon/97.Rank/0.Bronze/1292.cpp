#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B;
	cin >> A >> B;

	int Index = 1;
	long long Num = 1;
	long long Cnt = Num;
	long long Sum = 0;
	while (Index <= B)
	{
		if (Index >= A)
		{
			Sum += Num;
		}

		--Cnt;
		if (Cnt == 0)
		{
			++Num;
			Cnt = Num;
		}

		++Index;
	}

	cout << Sum;
}