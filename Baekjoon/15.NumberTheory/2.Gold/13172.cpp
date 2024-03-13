#include <iostream>
#include <numeric>
using namespace std;

typedef long long ll;
const ll Mod = 1000000007;

ll Pow(ll X, ll Y)
{
	if (Y == 1)
	{
		return X;
	}

	if (Y % 2 == 1)
	{
		return X * Pow(X, Y - 1) % Mod;
	}

	ll Z = Pow(X, Y / 2);
	return Z * Z % Mod;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int M;
	cin >> M;

	ll Sum = 0;
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> B >> A;

		ll GCD = gcd(A, B);
		B /= GCD;
		A /= GCD;

		Sum += A * Pow(B, Mod - 2) % Mod;
		Sum %= Mod;
	}

	cout << Sum;
}