#include <iostream>
using namespace std;

typedef long long ll;
const ll Mod = 1000000007;

ll Pow(ll A, ll B)
{
	if (B == 1)
	{
		return A;
	}

	if (B == 0)
	{
		return 1;
	}

	ll Half = Pow(A, B / 2) % Mod;
	if (B % 2 == 1)
	{
		return Half * Half % Mod * A % Mod;
	}

	return Half * Half % Mod;
}

ll Comb(ll N, ll K)
{
	if (K == 1 || N - K == 1)
	{
		return N;
	}

	if (K == 0 || N == K)
	{
		return 1;
	}

	ll A = 1, B = 1;
	for (ll i = N; i >= N - K + 1; --i)
	{
		A = (A * i) % Mod;
	}

	for (ll i = K; i >= 1; --i)
	{
		B = (B * i) % Mod;
	}

	return A * Pow(B, Mod - 2) % Mod;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll N, K;
	cin >> N >> K;
	cout << Comb(N, K);
}