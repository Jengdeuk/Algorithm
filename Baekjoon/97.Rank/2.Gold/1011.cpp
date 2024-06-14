#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

void Test()
{
	ll X, Y;
	cin >> X >> Y;

	ll D = Y - X;
	ll N = 1;
	while (N * N <= D)
	{
		++N;
	}
	--N;

	ll A = D - N * N;
	cout << 2 * N - 1 + ceil(double(A) / N) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}