#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < 5; ++i)
	{
		int a;
		cin >> a;
		if (a == n)
			++cnt;
	}

	cout << cnt;
}