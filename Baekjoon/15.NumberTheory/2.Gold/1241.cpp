#include <iostream>
using namespace std;

int Num[100000];
int Cnt[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Num[i];
		++Cnt[Num[i]];
	}

	for (int i = 0; i < N; ++i)
	{
		int C = 0;

		for (int j = 1; j * j <= Num[i]; ++j)
		{
			if (Num[i] % j == 0)
			{
				C += Cnt[j];

				if (j != Num[i] / j)
				{
					C += Cnt[Num[i] / j];
				}
			}
		}

		cout << C - 1 << '\n';
	}
}