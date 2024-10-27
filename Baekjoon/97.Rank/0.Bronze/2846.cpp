#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int Pre;
	cin >> Pre;

	int Start = Pre;
	int Max = 0;
	for (int i = 1; i < N; ++i)
	{
		int Num;
		cin >> Num;

		if (Num > Pre)
		{
			Max = max(Max, Num - Start);
		}
		else
		{
			Start = Num;
		}

		Pre = Num;
	}

	cout << Max;
}