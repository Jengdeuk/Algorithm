#include <iostream>
#include <set>
using namespace std;

int Length, K, C;
set<int> S;

int N, SP[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> Length >> K >> C;
	while (K--)
	{
		int Num;
		cin >> Num;
		S.emplace(Num);
	}

	N = S.size();

	int idx = 0;
	for (const int Elem : S)
	{
		SP[idx++] = Elem;
	}

	int L = 1, R = 1000000000;
	int Longest = 1000000000, FirstCut = 1000000000;
	while (L <= R)
	{
		int M = (L + R) >> 1;

		int Pre = Length, Cnt = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			if (Cnt < C && Pre - SP[i] <= M)
			{
				if ((i > 0 && Pre - SP[i - 1] > M) || (i == 0))
				{
					Cnt++;
					Pre = SP[i];
				}
			}
		}

		if (Pre <= M)
		{
			R = M - 1;
			Longest = M;
			FirstCut = Pre;
		}
		else
		{
			L = M + 1;
		}
	}

	cout << Longest << ' ' << FirstCut;
}