#include <iostream>
using namespace std;

int N, Order[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int LB;
		cin >> LB;

		int Idx = 0, Cnt = 0;
		while (Cnt < LB || Order[Idx] > 0)
		{
			if (Order[Idx] == 0)
			{
				Cnt++;
			}
			Idx++;
		}

		Order[Idx] = i;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << Order[i] << ' ';
	}
}