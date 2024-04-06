#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll N, M;
	cin >> N >> M;

	ll n = 1;
	if (N > M)
	{
		for (ll i = 2; i <= M; ++i)
		{
			n *= i;
			n %= M;
		}
	}
	else
	{
		for (ll i = 2; i <= N; ++i)
		{
			n *= i;
			n %= M;
		}
	}

	cout << n;
}