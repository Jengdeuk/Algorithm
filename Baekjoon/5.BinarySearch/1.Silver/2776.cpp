#include <iostream>
#include <algorithm>
using namespace std;

int n, s[1000000];

void test()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	sort(s, s + n);

	int m;
	cin >> m;
	while (m--)
	{
		int num;
		cin >> num;

		int idx = lower_bound(s, s + n, num) - s;
		cout << (idx >= 0 && idx < n && num == s[idx]) << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) test();
}