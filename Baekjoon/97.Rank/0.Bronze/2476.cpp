#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int maxMoney = 0;
	for (int i = 0; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		int money = 0;
		if (a == b && b == c)
			money = 10000 + a * 1000;
		else if (a == b || a == c)
			money = 1000 + a * 100;
		else if (b == c)
			money = 1000 + b * 100;
		else
			money = max(a, max(b, c)) * 100;

		maxMoney = max(maxMoney, money);
	}

	cout << maxMoney;
}