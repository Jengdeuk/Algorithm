#include <iostream>
using namespace std;

typedef long long ll;

int n;
int s[100];

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

void test()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	ll sum = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			sum += gcd(s[i], s[j]);

	cout << sum << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		test();
}