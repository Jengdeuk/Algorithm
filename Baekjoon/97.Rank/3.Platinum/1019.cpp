#include <iostream>
using namespace std;

typedef long long ll;

ll cnt[10];

void calc(ll n, ll m)
{
	if (n == 0)
	{
		cnt[0] += m;
		return;
	}

	while (n > 0)
	{
		cnt[n % 10] += m;
		n /= 10;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll a = 1, b;
	cin >> b;

	ll mul = 1;
	while (a != b)
	{
		while (a != b && a % 10 != 0) calc(a++, mul);
		while (a != b && b % 10 != 9) calc(b--, mul);
		if (a == b)
			break;

		for (int i = 0; i < 10; ++i)
			cnt[i] += (b / 10 - a / 10 + 1) * mul;

		a /= 10;
		b /= 10;
		mul *= 10;
	}

	if (a == b) calc(a, mul);

	for (int i = 0; i < 10; ++i)
		cout << cnt[i] << ' ';
}