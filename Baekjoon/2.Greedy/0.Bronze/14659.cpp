#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int Cur = 0, Cnt = 0, Max = 0;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		if (i == 0)
		{
			Cur = Num;
			continue;
		}

		if (Cur > Num)
		{
			++Cnt;
			Max = max(Max, Cnt);
		}
		else
		{
			Cnt = 0;
			Cur = Num;
		}
	}

	cout << Max;
}