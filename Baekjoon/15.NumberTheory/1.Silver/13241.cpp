#include <iostream>
using namespace std;

typedef long long ll;

ll GCD(ll A, ll B)
{
	ll C;
	while (B != 0)
	{
		C = A % B;
		A = B;
		B = C;
	}

	return A;
}

ll LCM(ll A, ll B)
{
	return A * B / GCD(A, B);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll A, B;
	cin >> A >> B;
	cout << LCM(A, B);
}