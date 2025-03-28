#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

void test()
{
	ll n;
	cin >> n;

	ll num = n;
	bool isPrime = false;
	while (isPrime == false)
	{
		isPrime = true;
		for (ll i = 2; i < ll(sqrt(num)) + 1; ++i)
		{
			if (num % i == 0)
			{
				isPrime = false;
				num++;
				break;
			}
		}
	}

	if (n < 2)
		num = 2;

	cout << num << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) test();
}