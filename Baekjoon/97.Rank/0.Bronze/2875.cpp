#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	int team = min(n / 2, m);
	n -= 2 * team;
	m -= team;

	k -= n + m;
	if (k > 0)
		team -= (k - 1) / 3 + 1;

	cout << max(team, 0);
}