#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[200000], b[200000];

void test()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < m; ++i)
		cin >> b[i];

	sort(b, b + m);

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		cnt += lower_bound(b, b + m, a[i]) - b;

	cout << cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) test();
}