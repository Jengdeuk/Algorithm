#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll n;
	cin >> n;

	ll x = 1;
	ll p = pow(10, x - 1);
	ll np = pow(10, x);
	ll answer = 0;
	while (n > np)
	{
		answer += (np - p) * x;
		p = np;
		np = pow(10, ++x);
	}

	answer += (n - p) * x;
	cout << answer + (to_string(n).size());
}