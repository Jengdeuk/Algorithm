#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll A, B, C, D, K;
	cin >> A >> B >> C >> D >> K;

	ll N = ceil(double(A + C) / D);

	ll S = 0;
	ll E = N;
	ll Result = E + 1;
	ll Catch = E + 1;
	while (S <= E)
	{
		ll T = (S + E) / 2;

		ll Toca = A - (T * (2 * B - K * (T - 1)) / 2);
		ll Doldol = A + C - T * D;

		if (Toca < Doldol)
		{
			if (Toca <= 0) Result = min(Result, T);
			S = T + 1;
		}
		else
		{
			Catch = min(Catch, T);
			E = T - 1;
		}
	}

	if (Result > N || Result >= Catch)
	{
		cout << -1;
	}
	else
	{
		cout << Result;
	}
}