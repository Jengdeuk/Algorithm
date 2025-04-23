#include <iostream>
#include <cmath>
using namespace std;

const int ms = 1000000;

bool p[ms + 1];

void test()
{
	int n;
	cin >> n;

	int cnt = (p[2] && p[n - 2]);
	for (int i = 3; i <= n / 2; i += 2)
		if (p[i] && p[n - i])
			cnt++;

	cout << cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 2; i <= ms; ++i)
		p[i] = true;

	for (int i = 2; i <= sqrt(ms); ++i)
	{
		if (p[i] == false)
			continue;

		for (int j = i * i; j <= ms; j += i)
			p[j] = false;
	}

	int t;
	cin >> t;
	while (t--) test();
}