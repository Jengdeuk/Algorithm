#include <iostream>
using namespace std;

int N, Cnt;
int S[10];

void BT(int Dgt, int Idx)
{
	if (Idx == Dgt)
	{
		if (Cnt++ == N)
		{
			for (int i = 0; i < Dgt; ++i)
			{
				cout << S[i];
			}

			exit(0);
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		if (Dgt > 1 && Idx == 0 && i == 0)
		{
			continue;
		}

		if (Idx >= 1 && i >= S[Idx - 1])
		{
			return;
		}

		S[Idx] = i;
		BT(Dgt, Idx + 1);
	}

	if (Idx == 0)
	{
		BT(Dgt + 1, Idx);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	if (N <= 1022)
	{
		BT(1, 0);
	}
	else
	{
		cout << -1;
	}
}