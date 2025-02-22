#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll a, b;
	cin >> a >> b;
	if (a > b)
	{
		ll temp = a;
		a = b;
		b = temp;
	}

	ll mid = b - a - 1;
	cout << (mid < 0 ? 0 : mid) << '\n';
	for (ll i = a + 1; i < b; ++i)
		cout << i << ' ';
}