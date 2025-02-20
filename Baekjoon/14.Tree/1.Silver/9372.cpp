#include <iostream>
using namespace std;

int n, m;

void test()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
	}
	cout << n - 1 << '\n';
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