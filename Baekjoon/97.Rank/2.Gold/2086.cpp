#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;

const int mod = 1000000000;

mat m =
{
	{ 1, 1 },
	{ 1, 0 }
};

mat mul(mat a, mat b)
{
	mat ret = mat(2, vector<ll>(2, 0));

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				ret[i][j] += a[i][k] * b[k][j] % mod;
				ret[i][j] %= mod;
			}
		}
	}

	return ret;
}

mat pow(ll n)
{
	if (n == 1)
	{
		return m;
	}

	mat half = pow(n / 2);
	if (n % 2 == 0)
	{
		return mul(half, half);
	}
	else
	{
		return mul(m, mul(half, half));
	}
}

ll f(ll n)
{
	mat ret = pow(n);
	return ret[1][0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll a, b;
	cin >> a >> b;
	cout << (f(b + 2) - 1 - (f(a + 1) - 1) + mod) % mod;
}