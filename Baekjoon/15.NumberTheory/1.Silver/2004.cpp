#include <iostream>
using namespace std;

typedef long long ll;

ll f(int n, int v)
{
	int cnt = 0;
	for (ll i = v; n / i > 0; i *= v)
		cnt += n / i;
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	cout << min(f(n, 2) - f(n - m, 2) - f(m, 2), f(n, 5) - f(n - m, 5) - f(m, 5));
}