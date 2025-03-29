#include <iostream>
#include <cmath>
using namespace std;

void func(bool isStick, int n, int s, int e)
{
	if (isStick == false)
	{
		for (int i = s; i < e; ++i)
			cout << ' ';
		return;
	}

	if (n == 0)
	{
		cout << '-';
		return;
	}

	int t = pow(3, n - 1);
	func(true, n - 1, s, s + t);
	func(false, n - 1, s + t, e - t);
	func(true, n - 1, e - t, e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	while (cin >> n)
	{
		func(true, n, 0, pow(3, n));
		cout << '\n';
	}
}