#include <iostream>
using namespace std;

typedef long long ll;

ll Sum[55];

ll Get(ll N)
{
	ll Result = N & 1;
	for (ll i = 54; i > 0; --i)
	{
		if (N & (1LL << i))
		{
			Result += Sum[i - 1] + (N - (1LL << i) + 1);
			N -= 1LL << i;
		}
	}

	return Result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Sum[0] = 1;
	for (ll i = 1; i < 55; ++i)
	{
		Sum[i] = 2 * Sum[i - 1] + (1LL << i);
	}

	ll A, B;
	cin >> A >> B;
	cout << Get(B) - Get(A - 1);
}