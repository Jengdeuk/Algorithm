#include <iostream>
using namespace std;

typedef long long ll;

ll n, k;
int t[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= k; ++i)
		cin >> t[i];

	ll l = 0, r = 30 * n;
	ll time = r;
	while (l <= r)
	{
		ll m = (l + r) / 2;

		ll cnt = min(n, k);
		for (int i = 1; i <= k; ++i)
			cnt += m / t[i];

		if (cnt >= n)
		{
			time = min(time, m);
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}

	ll cnt = min(n, k);
	for (int i = 1; i <= k; ++i)
		cnt += (time - 1) / t[i];

	int idx = min(n, k);
	if (time > 0)
	{
		for (int i = 1; i <= k; ++i)
		{
			if (time % t[i] == 0)
				++cnt;

			if (cnt == n)
			{
				idx = i;
				break;
			}
		}
	}

	cout << idx;
}