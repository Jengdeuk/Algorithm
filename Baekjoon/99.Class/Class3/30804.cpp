#include <iostream>
#include <cstring>
using namespace std;

int N;
int Fruit[200000], F[10];

bool Check()
{
	int Cnt = 0;
	for (int i = 1; i <= 9; ++i)
	{
		if (F[i] > 0)
		{
			++Cnt;
		}
	}

	if (Cnt > 2)
	{
		return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Fruit[i];
	}

	int Max = 1;
	int L = 0, R = 0;
	++F[Fruit[L]];
	while (R < N)
	{
		Max = max(Max, R - L + 1);

		if (++R == N) break;
		++F[Fruit[R]];
		if (!Check())
		{
			--F[Fruit[R]];
			--R;
			--F[Fruit[L]];
			++L;
		}
	}

	cout << Max;
}