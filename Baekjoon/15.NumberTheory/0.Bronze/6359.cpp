#include <iostream>
using namespace std;

void test()
{
	int n;
	cin >> n;

	bool lock[101] = {};
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j * i <= n; ++j)
			lock[j * i] = !lock[j * i];

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (lock[i] == false)
			cnt++;

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