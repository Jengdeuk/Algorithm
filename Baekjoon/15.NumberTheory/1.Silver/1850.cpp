#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		ll temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll a, b;
	cin >> a >> b;

	ll lgcd = gcd(a, b);
	for (int i = 0; i < lgcd; ++i)
		cout << 1;
}