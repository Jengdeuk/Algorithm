#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int k = 1;
	int p = pow(10, k);
	int q = pow(10, k - 1);
	while (n > p)
	{
		int num = (n % p) / q;
		if (num >= 5)
			n += p - (q * num);
		else
			n -= q * num;

		q = p;
		p = pow(10, ++k);
	}

	cout << n;
}