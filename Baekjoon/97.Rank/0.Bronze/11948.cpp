#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Sum = 0;
	int Min = 100;
	for (int i = 0; i < 4; ++i)
	{
		int Num;
		cin >> Num;
		Sum += Num;
		Min = min(Min, Num);
	}
	Sum -= Min;

	Min = 100;
	for (int i = 0; i < 2; ++i)
	{
		int Num;
		cin >> Num;
		Sum += Num;
		Min = min(Min, Num);
	}
	Sum -= Min;

	cout << Sum;
}